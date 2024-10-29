// Copyright (c) 2020 RISC Software GmbH
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
#include "ITiglUIDRefObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CTiglUIDObject;
class CCPACSNacelleGuideCurves;

namespace generated
{
    // This class is used in:
    // CPACSNacelleGuideCurves

    /// @brief Guide curve
    /// 
    /// The following figure shows the basic setup of the guide curves.
    /// They always start at a given ζ-position ( fromZeta ) on the profile of the specified start section ( startSectionUID ) and end at the ζ-position ( toZeta ) on the profile of the subsequent section.
    /// The relative coordinates of the guide curves are specified in cpacs/vehicles/profiles/guideCurves and referenced via its uID .
    /// @see nacelle_guideCurves
    /// Note : Guide curves and profiles must result in a valid curve network.
    /// The guide curve points are interpreted as ( Δr and Δx ) offsets from a cubic polynomial.
    /// This polynomial serves as a baseline for guide curves between segments located on different radial positions with smooth transitions:
    /// @see nacelle_guideCurve
    /// Note : Currently, the nacelles do not have an explicit guide curve type but employ the standard guide curve definition, which is used in wings and profiles.
    /// Therefore, the parameters have a different meaning:
    /// Standard guide curve parameter Nacelle guide curve equivalent Description rX φ Independent variable normalized to [0,1] rY Δx Orthogonal offset (translation in x -direction) rZ Δr Radial offset
    class CPACSNacelleGuideCurve : public ITiglUIDRefObject
    {
    public:
        TIGL_EXPORT CPACSNacelleGuideCurve(CCPACSNacelleGuideCurves* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSNacelleGuideCurve();

        TIGL_EXPORT CCPACSNacelleGuideCurves* GetParent();

        TIGL_EXPORT const CCPACSNacelleGuideCurves* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetName() const;
        TIGL_EXPORT virtual void SetName(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
        TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const std::string& GetGuideCurveProfileUID() const;
        TIGL_EXPORT virtual void SetGuideCurveProfileUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetStartSectionUID() const;
        TIGL_EXPORT virtual void SetStartSectionUID(const std::string& value);

        TIGL_EXPORT virtual const double& GetFromZeta() const;
        TIGL_EXPORT virtual void SetFromZeta(const double& value);

        TIGL_EXPORT virtual const double& GetToZeta() const;
        TIGL_EXPORT virtual void SetToZeta(const double& value);

    protected:
        CCPACSNacelleGuideCurves* m_parent;

        CTiglUIDManager* m_uidMgr;

        /// Name
        std::string                  m_name;

        /// Description
        boost::optional<std::string> m_description;

        /// UID of the guide curve profile
        std::string                  m_guideCurveProfileUID;

        /// UID of the start section
        std::string                  m_startSectionUID;

        /// Curve coordinate of the referenced section profile at which the guide curve shall start.
        /// Valid values are in the interval -1,..,1.
        double                       m_fromZeta;

        /// Curve coordinate of the profile following the referenced section profile.
        /// It defines where the guide curve ends.
        /// Valid values are in the interval -1,..,1.
        double                       m_toZeta;

    private:
        TIGL_EXPORT const CTiglUIDObject* GetNextUIDObject() const final;
        TIGL_EXPORT void NotifyUIDChange(const std::string& oldUid, const std::string& newUid) final;

        CPACSNacelleGuideCurve(const CPACSNacelleGuideCurve&) = delete;
        CPACSNacelleGuideCurve& operator=(const CPACSNacelleGuideCurve&) = delete;

        CPACSNacelleGuideCurve(CPACSNacelleGuideCurve&&) = delete;
        CPACSNacelleGuideCurve& operator=(CPACSNacelleGuideCurve&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSNacelleGuideCurve = generated::CPACSNacelleGuideCurve;
} // namespace tigl
