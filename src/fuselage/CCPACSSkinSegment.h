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

#pragma once

#include "generated/CPACSSkinSegment.h"
#include "CTiglStringerFrameBorderedObject.h"

#include "geometry/CTiglRectGridSurface.h"
#include "TopoDS_Shape.hxx"
#include "TopoDS_Compound.hxx"

namespace tigl
{
    /*struct TrimShapeAnnotation;

    template <typename Annotation>
    class CTiglRectGridSurface;
*/
class CCPACSSkinSegment : public generated::CPACSSkinSegment, public CTiglStringerFrameBorderedObject
{
public:
    TIGL_EXPORT CCPACSSkinSegment(CCPACSSkinSegments* parent, CTiglUIDManager* uidMgr);

    TIGL_EXPORT virtual void SetStartFrameUID(const std::string& value) override;
    TIGL_EXPORT virtual void SetEndFrameUID(const std::string& value) override;
    TIGL_EXPORT virtual void SetStartStringerUID(const std::string& value) override;
    TIGL_EXPORT virtual void SetEndStringerUID(const boost::optional<std::string>& value) override;

    TIGL_EXPORT void BuildGeometryUVSegment(const TopoDS_Shape& loft, double umin, double umax, double vmin, double vmax);//, bool onlyVTrim);
  /*  TIGL_EXPORT void BuildGeometryUVSegment(const TopoDS_Shape& loft, double umin, double umax, double vmin, double vmax) {
        BuildGeometryUVSegment(loft, umin, umax, vmin, vmax, false);
    }
    TIGL_EXPORT void BuildGeometryUVSegment(const TopoDS_Shape& loft, double vmin, double vmax) {
        BuildGeometryUVSegment(loft, 0.0, 1.0, vmin, vmax, true);
    }*/
    TIGL_EXPORT TopoDS_Compound& GetGeometryUVSegment();

protected:

    //TIGL_EXPORT virtual TopoDS_Shape GetGeometry(TiglCoordinateSystem referenceCS = GLOBAL_COORDINATE_SYSTEM) const;
    // this enum is used internally by CutSpanWise to determine,
    // whether it is an inner or an outer cut
    enum class SpanWiseBorder {
        Inner,
        Outer
    };

    /**
     * @brief TrimSpanwise trims the wing skin in spanwise direction
     * Depending on the enum border, it can be a inner or outer
     * border. This function is called by BuildSkinGeometry to trim
     * the wing shape in spanwise direction.
     *
     * This function is used, it the borders of the cell are defined
     * relative to the wing skin via contour coordinates.
     *
     * @param cache The shape of the wing cell
     * @param border  a SpanWiseBorder enum, denoting whether it is an inner
     * or outer border
     * @param positioning CPACS definition of the border
     * @param tol a tolerance
     */
    void TrimSpanwise(CTiglRectGridSurface<TrimShapeAnnotation>& rgsurface,
                      SpanWiseBorder border,
                      double trim_coordinate,
                      double tol = 5e-3) const;

    // this enum is used internally by CutContourwise to determine,
    // whether it is a leading edge or trailing edge cut
    enum class ContourWiseBorder {
        Start,
        End
    };

    /**
     * @brief TrimContourwise trims the wing skin in contourwise direction
     * Depending on the enum border, it can be a leading edge or trailing edge
     * border. This function is called by BuildSkinGeometry to trim
     * the wing shape in contourwise direction.
     *
     * This function is used, it the borders of the cell are defined
     * relative to the wing skin via contour coordinates.
     *
     * @param cache The shape of the wing cell
     * @param border  a ContourWiseBorder enum, denoting whether it is a LE
     * or a TE border
     * @param positioning CPACS definition of the border
     * @param tol a tolerance
     */
    void TrimContourwise(CTiglRectGridSurface<TrimShapeAnnotation>& rgsurface,
                       ContourWiseBorder border,
                       double trim_coordinate,
                       double tol = 5e-3) const;

private:
    void InvalidateImpl(const boost::optional<std::string>& source) const override;
    
    TopoDS_Compound m_geometry_uv;
};
} // namespace tigl
