// Copyright (c) 2018 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <CCPACSEtaIsoLine.h>
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
namespace generated
{
    // This class is used in:
    // CPACSControlSurfaceContours

    // generated from /xsd:schema/xsd:complexType[167]
    /// @brief Airfoil definition of an control surface between inner
    /// and outer border.
    /// 
    /// Optional definition of the exact airfoil shape between
    /// the inner and outer border of the control surface.
    /// The airfoil shape is defined via referencing to the
    /// airfoilUID. As the leading and trailing edge point is fix due to
    /// the outer shape definition of the control surface the airfoil
    /// can be rotated around the x-axis (axis going from leading to
    /// trailing edge of the control surface) and around the z-axis
    /// (normal axis on the control surface middle plane). Scaling in
    /// x-direction is also defined by the outer shape, wherefore only
    /// scaling in y and z direction is allowed.
    /// 
    class CPACSControlSurfaceAirfoil
    {
    public:
        TIGL_EXPORT CPACSControlSurfaceAirfoil();
        TIGL_EXPORT virtual ~CPACSControlSurfaceAirfoil();

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const CCPACSEtaIsoLine& GetEta() const;
        TIGL_EXPORT virtual CCPACSEtaIsoLine& GetEta();

        TIGL_EXPORT virtual const std::string& GetAirfoilUID() const;
        TIGL_EXPORT virtual void SetAirfoilUID(const std::string& value);

        TIGL_EXPORT virtual const double& GetRotX() const;
        TIGL_EXPORT virtual void SetRotX(const double& value);

        TIGL_EXPORT virtual const double& GetRotZ() const;
        TIGL_EXPORT virtual void SetRotZ(const double& value);

        TIGL_EXPORT virtual const double& GetScalY() const;
        TIGL_EXPORT virtual void SetScalY(const double& value);

        TIGL_EXPORT virtual const double& GetScalZ() const;
        TIGL_EXPORT virtual void SetScalZ(const double& value);

    protected:
        /// Relative spanwise coordinate (eta) of the
        /// control surface, where the leading edge of the airfoil is
        /// placed.
        CCPACSEtaIsoLine m_eta;

        /// Reference to the airfoil uID.
        std::string      m_airfoilUID;

        /// Rotation around an axis, going from the
        /// leading edge point to the trailing edge point of the control
        /// surface. Defaults to 90°, which is equivalent to perpendicular
        /// on the control surface middle plane.
        double           m_rotX;

        /// Rotation of the airfoil around the control
        /// surface middle plane normal direciotn. Reference point is the
        /// most forward point of the airfoil. Defaults to 90°, which is
        /// equivalent to the airfoilplacement in flight direction (along
        /// wings-x axis).
        double           m_rotZ;

        /// Scaling of the airfoil in spanwise direction
        /// (not used for 2D airfoils).
        double           m_scalY;

        /// Scaling in thickness direction of the airfoil.
        double           m_scalZ;

    private:
#ifdef HAVE_CPP11
        CPACSControlSurfaceAirfoil(const CPACSControlSurfaceAirfoil&) = delete;
        CPACSControlSurfaceAirfoil& operator=(const CPACSControlSurfaceAirfoil&) = delete;

        CPACSControlSurfaceAirfoil(CPACSControlSurfaceAirfoil&&) = delete;
        CPACSControlSurfaceAirfoil& operator=(CPACSControlSurfaceAirfoil&&) = delete;
#else
        CPACSControlSurfaceAirfoil(const CPACSControlSurfaceAirfoil&);
        CPACSControlSurfaceAirfoil& operator=(const CPACSControlSurfaceAirfoil&);
#endif
    };
} // namespace generated

// Aliases in tigl namespace
#ifdef HAVE_CPP11
using CCPACSControlSurfaceAirfoil = generated::CPACSControlSurfaceAirfoil;
#else
typedef generated::CPACSControlSurfaceAirfoil CCPACSControlSurfaceAirfoil;
#endif
} // namespace tigl
