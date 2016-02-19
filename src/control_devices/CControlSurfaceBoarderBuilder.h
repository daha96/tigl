/*
* Copyright (C) 2016 German Aerospace Center (DLR/SC)
*
* Created: 2016-02-19 Martin Siggel <martin.siggel@dlr.de>
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

#ifndef CCONTROLSURFACEBOARDERBUILDER_H
#define CCONTROLSURFACEBOARDERBUILDER_H

#include <gp_Pln.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Wire.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>

namespace tigl
{

/**
 * @brief Defines are coordiante system for the wing flap
 * border.
 * 
 * The x direction of the coordinate system points from the
 * leading edge to the trailing edge of the flap border.
 */
class CSCoordSystem
{
public:
    /**
     * @brief CSCoordSystem constructor
     * 
     * @param le Leading edge point of the flap border
     * @param te Trailing edge point of the flap border
     * @param upDir Direction, that should be normal to the wing chord surface
     */
    CSCoordSystem(gp_Pnt le, gp_Pnt te, gp_Vec upDir);

    gp_Vec getNormal() const;
    gp_Pnt getLe() const;
    gp_Pnt getTe() const;
    gp_Vec getXDir() const;
    gp_Vec getYDir() const;

    gp_Pln getPlane() const;

private:
    gp_Pnt _le, _te;
    gp_Vec _ydir;
};

class CControlSurfaceBoarderBuilder
{
public:
    CControlSurfaceBoarderBuilder(const CSCoordSystem& coords, TopoDS_Shape wingShape);
    ~CControlSurfaceBoarderBuilder();

    /**
     * @brief Computes the cutout wire with a defined leading edge shape according to 
     * the CPACS definition.
     * 
     * @param rLEHeight Relative height of the nose point
     * @param xsiUpper Upper skin point, where xsi=1 is the flap leading edge, and xsi=0 the trailing edge
     * @param xsiLower Lower skin point, where xsi=1 is the flap leading edge, and xsi=0 the trailing edge
     */
    TopoDS_Wire boarderWithLEShape(double rLEHeight, double xsiNose, double xsiUpper, double xsiLower);
    TopoDS_Wire boarderSimple(double xsiUpper, double xsiLower);

    gp_Pnt2d upperPoint();
    gp_Pnt2d lowerPoint();

    gp_Vec2d upperTangent();
    gp_Vec2d lowerTangent();

private:
    CControlSurfaceBoarderBuilder();
    
    /// Computes the points on the wing skin and their tangents
    void computeSkinPointsImpl(double xsi, gp_Pnt2d& pntUp, gp_Vec2d& tangentUp, gp_Pnt2d& pntLo, gp_Vec2d& tanLo);
    void computeSkinPoints(double xsiUpper, double xsiLower);
    
    TopoDS_Shape _wingShape;
    const CSCoordSystem& _coords;
    
    gp_Pnt2d _up2d, _lp2d, _le2d, _te2d;
    gp_Vec2d _upTan2d, _loTan2d;
};


}
#endif // CCONTROLSURFACEBOARDERBUILDER_H
