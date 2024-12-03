/*
* Copyright (c) 2018 RISC Software GmbH
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "CCPACSSkinSegment.h"

#include "CCPACSFuselageStructure.h"

#include "CTiglUIDManager.h"
#include "tiglcommonfunctions.h"

#include "TopoDS_Shape.hxx"
#include "TopoDS_Compound.hxx"
#include "BRep_Builder.hxx"

#include "BRepTools.hxx"

namespace tigl
{
CCPACSSkinSegment::CCPACSSkinSegment(CCPACSSkinSegments* parent, CTiglUIDManager* uidMgr)
    : generated::CPACSSkinSegment(parent, uidMgr)
    , CTiglStringerFrameBorderedObject(*uidMgr, parent->GetParent()->GetParentComponent(), generated::CPACSSkinSegment::m_startFrameUID, generated::CPACSSkinSegment::m_endFrameUID, generated::CPACSSkinSegment::m_startStringerUID, generated::CPACSSkinSegment::m_endStringerUID)
    //, m_geometry_uv(TopoDS_Compound())
{
}

void CCPACSSkinSegment::SetStartFrameUID(const std::string& value)
{
    generated::CPACSSkinSegment::SetStartFrameUID(value);
    Invalidate();
}

void CCPACSSkinSegment::SetEndFrameUID(const std::string& value)
{
    generated::CPACSSkinSegment::SetEndFrameUID(value);
    Invalidate();
}

void CCPACSSkinSegment::SetStartStringerUID(const std::string& value)
{
    generated::CPACSSkinSegment::SetStartStringerUID(value);
    Invalidate();
}

void CCPACSSkinSegment::SetEndStringerUID(const boost::optional<std::string>& value)
{
    generated::CPACSSkinSegment::SetEndStringerUID(value);
    Invalidate();
}


void CCPACSSkinSegment::InvalidateImpl(const boost::optional<std::string>& source) const
{
    CTiglStringerFrameBorderedObject::InvalidateShapes(source);
}

/*
TopoDS_Shape CCPACSSkinSegment::GetGeometry(TiglCoordinateSystem referenceCS) const
{
    return CTiglStringerFrameBorderedObject::GetGeometry(referenceCS);
}
*/

TopoDS_Compound& CCPACSSkinSegment::GetGeometryUVSegment()
{
    return m_geometry_uv;
}

void addRGFacesToCompound(CTiglRectGridSurface<TrimShapeAnnotation> &rgsurface, TopoDS_Builder &builder, TopoDS_Compound &resultShape, std::string uid) {
    int i = 0;
    for (auto row = rgsurface.Root(); row; row = row->VNext()) {
        for (auto current = row; current; current = current->UNext()) {
            if (current->GetAnnotation().keep == true ) {

                auto face = current->GetFace();
/*                std::stringstream ss;
                ss << "H:\\" << uid << "_face_" << i << ".brep";
                std::string filename = ss.str();

    //LOG(ERROR) << "BuildGeometryUVSegment face " << i << ": " << filename.c_str();

                //std::string filename = ("face_" + i + ".brep").c_str();
                BRepTools::Write(face, filename.c_str());
                i++;
*/
                builder.Add(resultShape, face);
            }
        }
    }
}

void setRGSurfaceData(CTiglRectGridSurface<TrimShapeAnnotation> &rgsurface, std::vector<double> &row_ranges, std::vector<double> &col_ranges) {
    /*
    *  Step 1/2:
    *
    *  Compute the relative contribution of each face to the total parameter
    *  range in u- and v-direction respectively. These relative contributions
    *  correspond to the contour coordinates spanned by each individual face.
    */

    rgsurface.GetParameterRanges(row_ranges, col_ranges);

    int j = 0;
    double spanwise_contour_coordinate = 0;
    for (auto row = rgsurface.Root(); row; row = row->VNext()) {
        int i = 0;
        double contourwise_contour_coordinate = 0.;//UPPER_SIDE? 0. : 1.;
        for (auto current = row; current; current = current->UNext()){
            current->GetAnnotation().scmin = spanwise_contour_coordinate;
            current->GetAnnotation().scmax = spanwise_contour_coordinate
                    + (current->VMax() - current->VMin())/col_ranges[i];

            //if (UPPER_SIDE) {
                current->GetAnnotation().ccmin = contourwise_contour_coordinate;
                current->GetAnnotation().ccmax = contourwise_contour_coordinate
                        + (current->UMax() - current->UMin())/row_ranges[j];
                contourwise_contour_coordinate = current->GetAnnotation().ccmax;
           /* } else {
                current->GetAnnotation().ccmax = contourwise_contour_coordinate;
                current->GetAnnotation().ccmin = contourwise_contour_coordinate
                        - (current->UMax() - current->UMin())/row_ranges[j];
                contourwise_contour_coordinate = current->GetAnnotation().ccmin;
            }*/

            i++;
            if (!(current->UNext()))
            {
                spanwise_contour_coordinate = current->GetAnnotation().scmax;
            }
        }
        j++;
    }
}

void CCPACSSkinSegment::BuildGeometryUVSegment(const TopoDS_Shape& loft, double umin, double umax, double vmin, double vmax)//, bool onlyVTrim)
{    
    // The skin is composed of a rectangular grid of faces. We need to annotate
    // these faces to trim the correct faces at the correct parameters.


    CTiglRectGridSurface<TrimShapeAnnotation> rgsurface = CTiglRectGridSurface<TrimShapeAnnotation>(loft);
    std::vector<double> row_ranges, col_ranges;
    setRGSurfaceData(rgsurface, row_ranges, col_ranges);


    TopoDS_Builder builder;
//    m_geometry_uv = TopoDS_Compound();
//    builder.MakeCompound(m_geometry_uv);
    TopoDS_Compound resultShape;// = TopoDS_Compound();
    builder.MakeCompound(resultShape);

        //LOG(ERROR) << "BuildGeometryUVSegment 4";
    /*
        *  Step 2/2:
        *
        *  Trim all the faces and store the result
        */
    if (umin > umax) {
        //LOG(ERROR) << "BuildGeometryUVSegment alt trim " << GetUID();

        TrimSpanwise(rgsurface, SpanWiseBorder::Inner, vmin, 1e-4);
        TrimSpanwise(rgsurface, SpanWiseBorder::Outer, vmax, 1e-4);
        TrimContourwise(rgsurface, ContourWiseBorder::Start, umin, 1e-4);
        addRGFacesToCompound(rgsurface, builder, resultShape, GetUID());
        
        
        CTiglRectGridSurface<TrimShapeAnnotation> rgsurface2 = CTiglRectGridSurface<TrimShapeAnnotation>(loft);
        std::vector<double> row_ranges2, col_ranges2;
        setRGSurfaceData(rgsurface2, row_ranges2, col_ranges2);

        TrimSpanwise(rgsurface2, SpanWiseBorder::Inner, vmin, 1e-4);
        TrimSpanwise(rgsurface2, SpanWiseBorder::Outer, vmax, 1e-4);
        TrimContourwise(rgsurface2, ContourWiseBorder::End, umax, 1e-4);
        addRGFacesToCompound(rgsurface2, builder, resultShape, GetUID());
    }
    else {
        TrimSpanwise(rgsurface, SpanWiseBorder::Inner, vmin, 1e-4);
        TrimSpanwise(rgsurface, SpanWiseBorder::Outer, vmax, 1e-4);
        TrimContourwise(rgsurface, ContourWiseBorder::Start, umin, 1e-4);
        TrimContourwise(rgsurface, ContourWiseBorder::End, umax, 1e-4);
        addRGFacesToCompound(rgsurface, builder, resultShape, GetUID());
    }

        //LOG(ERROR) << "BuildGeometryUVSegment 5";

                /*std::stringstream ss;
                ss << "face_" << 8 << ".brep";
                std::string filename = ss.str();
                BRepTools::Write(m_geometry_uv, filename.c_str());
*/
    //LOG(ERROR) << "BuildGeometryUVSegment 6";

        //LOG(ERROR) << "BuildGeometryUVSegment 7";
    m_geometry_uv = resultShape;
    //return resultShape;

}
void CCPACSSkinSegment::TrimSpanwise(CTiglRectGridSurface<TrimShapeAnnotation>& rgsurface,
                                  SpanWiseBorder border,
                                  double trim_coordinate,
                                  double tol) const
{

    for(auto row = rgsurface.Root(); row; row = row->UNext()) {
        for (auto current = row; current; current = current->VNext()) {
            if (current->GetAnnotation().keep) {
                if (trim_coordinate <= current->GetAnnotation().scmin) {
                    if (border == SpanWiseBorder::Outer) {
                        // remove this face from the rgsurface
                        current->GetAnnotation().keep = false;
                    }
                }
                else if (trim_coordinate >= current->GetAnnotation().scmax) {
                    if (border == SpanWiseBorder::Inner) {
                        // remove this face from the rgsurface
                        current->GetAnnotation().keep = false;
                    }
                }
                else {
                    //trim the face

                    double alpha = (trim_coordinate - current->GetAnnotation().scmin) / (current->GetAnnotation().scmax - current->GetAnnotation().scmin);
                    double v = (1-alpha)*current->VMin() + alpha * current->VMax();

                    double vmin = current->VMin();
                    double vmax = current->VMax();
                    bool trim = false;
                    if (border == SpanWiseBorder::Inner) {
                        if ( fabs(v - vmin) > tol ) {
                            vmin = v;
                            current->GetAnnotation().scmin = trim_coordinate;
                            trim = true;
                        }
                    }
                    else {
                        if ( fabs(vmax - v) > tol ) {
                            vmax = v;
                            current->GetAnnotation().scmax = trim_coordinate;
                            trim = true;
                        }
                    }

                    if (trim) {
                        current->ReplaceFace(TrimFace(current->GetFace(),
                                                      current->UMin(),
                                                      current->UMax(),
                                                      vmin,
                                                      vmax));
                    }
                }
            }
        }
    }
}

void CCPACSSkinSegment::TrimContourwise(CTiglRectGridSurface<TrimShapeAnnotation>& rgsurface,
                                  ContourWiseBorder border,
                                  double trim_coordinate,
                                  double tol) const
{
    for(auto row = rgsurface.Root(); row; row = row->UNext()) {
        for (auto current = row; current; current = current->VNext()) {
            if (current->GetAnnotation().keep) {
                if (trim_coordinate <= current->GetAnnotation().ccmin) {
                    if (border == ContourWiseBorder::End) {
                        // remove this face from the rgsurface
                        current->GetAnnotation().keep = false;
                    }
                }
                else if (trim_coordinate >= current->GetAnnotation().ccmax) {
                    if (border == ContourWiseBorder::Start) {
                        // remove this face from the rgsurface
                        current->GetAnnotation().keep = false;
                    }
                }
                else {
                    //trim the face

                    double alpha = (trim_coordinate - current->GetAnnotation().ccmin) / (current->GetAnnotation().ccmax - current->GetAnnotation().ccmin);

                    // On the lower side, u increases from End to Start, while contour coordinates increase from Start (0) to End (1)
                    double u = (1-alpha)*current->UMin() + alpha * current->UMax();

                    double umin = current->UMin();
                    double umax = current->UMax();
                    bool trim = false;
                    if (   border == ContourWiseBorder::Start) {
                        if ( fabs(u - umin) > tol ) {
                            umin = u;
                            trim = true;
                        }
                    }
                    if (  border == ContourWiseBorder::End) {
                        if ( fabs(umax - u) > tol ) {
                            umax = u;
                            trim = true;
                        }
                    }

                    if (trim) {
                        // update annotation
                        if (border == ContourWiseBorder::Start) {
                            current->GetAnnotation().ccmin = trim_coordinate;
                        } else {
                            current->GetAnnotation().ccmax = trim_coordinate;
                        }

                        // replace face
                        current->ReplaceFace(TrimFace(current->GetFace(),
                                                      umin,
                                                      umax,
                                                      current->VMin(),
                                                      current->VMax()));
                    }
                }
            }
        }
    }
}


} // namespace tigl
