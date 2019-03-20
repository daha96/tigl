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

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <string>
#include <tixi.h>
#include "CPACSGuideCurve_continuity.h"
#include "CPACSPointXYZ.h"
#include "CreateIfNotExists.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;

namespace generated
{
    // This class is used in:
    // CPACSGuideCurves

    // generated from /xsd:schema/xsd:complexType[441]
    /// @brief Guide Curve Type
    /// 
    /// A guide curve may be used to alter the shape of the
    /// outer geometry and "guide" the loft.
    /// The guide curve profiles are defined in the guideCurveProfileGeometryType.
    /// Their use on wing and fuselage components is illustrated in the image below.
    /// @see guideCurveIllustration
    /// 
    class CPACSGuideCurve
    {
    public:
        TIGL_EXPORT CPACSGuideCurve(CTiglUIDManager* uidMgr);
        TIGL_EXPORT virtual ~CPACSGuideCurve();

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT bool ValidateChoices() const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetName() const;
        TIGL_EXPORT virtual void SetName(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
        TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const std::string& GetGuideCurveProfileUID() const;
        TIGL_EXPORT virtual void SetGuideCurveProfileUID(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetFromGuideCurveUID_choice1() const;
        TIGL_EXPORT virtual void SetFromGuideCurveUID_choice1(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<CPACSGuideCurve_continuity>& GetContinuity_choice1() const;
        TIGL_EXPORT virtual void SetContinuity_choice1(const boost::optional<CPACSGuideCurve_continuity>& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetFromRelativeCircumference_choice2() const;
        TIGL_EXPORT virtual void SetFromRelativeCircumference_choice2(const boost::optional<double>& value);

        TIGL_EXPORT virtual const boost::optional<CPACSPointXYZ>& GetTangent_choice2() const;
        TIGL_EXPORT virtual boost::optional<CPACSPointXYZ>& GetTangent_choice2();

        TIGL_EXPORT virtual const double& GetToRelativeCircumference() const;
        TIGL_EXPORT virtual void SetToRelativeCircumference(const double& value);

        TIGL_EXPORT virtual const boost::optional<CPACSPointXYZ>& GetTangent() const;
        TIGL_EXPORT virtual boost::optional<CPACSPointXYZ>& GetTangent();

        TIGL_EXPORT virtual const boost::optional<CPACSPointXYZ>& GetRXDirection() const;
        TIGL_EXPORT virtual boost::optional<CPACSPointXYZ>& GetRXDirection();

        TIGL_EXPORT virtual CPACSPointXYZ& GetTangent_choice2(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveTangent_choice2();

        TIGL_EXPORT virtual CPACSPointXYZ& GetTangent(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveTangent();

        TIGL_EXPORT virtual CPACSPointXYZ& GetRXDirection(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveRXDirection();

    protected:
        CTiglUIDManager* m_uidMgr;

        std::string                                 m_uID;

        /// Name of guide curve
        std::string                                 m_name;

        /// Description of guide curve
        boost::optional<std::string>                m_description;

        /// Reference to a guide curve profile
        std::string                                 m_guideCurveProfileUID;

        /// Reference to the previous guide curve from
        /// which this guide curve shall start.
        boost::optional<std::string>                m_fromGuideCurveUID_choice1;

        /// Continuity definition for geometry
        /// generation. Possible options: C0, C1 from previous, C2 from
        /// previous, C1 to previous, C2 to previous
        boost::optional<CPACSGuideCurve_continuity> m_continuity_choice1;

        /// Reference to the relative circumference
        /// position from which the guide curve shall start. Valid values
        /// are in the interval -1.0...1.0.
        boost::optional<double>                     m_fromRelativeCircumference_choice2;

        /// Tangent at first point
        boost::optional<CPACSPointXYZ>              m_tangent_choice2;

        /// The relative circumference
        /// position at which the guide curve shall end. Valid values
        /// are in the interval -1.0...1.0.
        double                                      m_toRelativeCircumference;

        /// Tangent at last point
        boost::optional<CPACSPointXYZ>              m_tangent;

        /// Local direction along which the relative x-coordinates of
        /// the guide curve points are defined. For the wing the default is
        /// the wing's local x-axis, for the fuselage its the fuselage's local z-axis.
        boost::optional<CPACSPointXYZ>              m_rXDirection;

    private:
        CPACSGuideCurve(const CPACSGuideCurve&) = delete;
        CPACSGuideCurve& operator=(const CPACSGuideCurve&) = delete;

        CPACSGuideCurve(CPACSGuideCurve&&) = delete;
        CPACSGuideCurve& operator=(CPACSGuideCurve&&) = delete;
    };
} // namespace generated

// CPACSGuideCurve is customized, use type CCPACSGuideCurve directly
} // namespace tigl
