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
#include <CCPACSWingRibCrossSection.h>
#include <CCPACSWingRibExplicitPositioning.h>
#include <CCPACSWingRibsPositioning.h>
#include <string>
#include <tixi.h>
#include "CreateIfNotExists.h"
#include "CTiglUIDObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSWingRibsDefinitions;

namespace generated
{
    // This class is used in:
    // CPACSWingRibsDefinitions

    /// @brief Definition of a set of ribs
    /// 
    /// RibDefinitionType, containing the definition for ribs.
    /// Ribs are defined in sets of one or more ribs. The positions of
    /// the rib, as well as the orientation of the ribs are defined in
    /// 'ribPositioing'. The cross section properties, as e.g.
    /// materials, are defined in 'ribCrossSection'.
    /// 
    class CPACSWingRibsDefinition : public CTiglReqUIDObject
    {
    public:
        TIGL_EXPORT CPACSWingRibsDefinition(CCPACSWingRibsDefinitions* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSWingRibsDefinition();

        TIGL_EXPORT CCPACSWingRibsDefinitions* GetParent();

        TIGL_EXPORT const CCPACSWingRibsDefinitions* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

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

        TIGL_EXPORT virtual const boost::optional<CCPACSWingRibsPositioning>& GetRibsPositioning_choice1() const;
        TIGL_EXPORT virtual boost::optional<CCPACSWingRibsPositioning>& GetRibsPositioning_choice1();

        TIGL_EXPORT virtual const boost::optional<CCPACSWingRibExplicitPositioning>& GetRibExplicitPositioning_choice2() const;
        TIGL_EXPORT virtual boost::optional<CCPACSWingRibExplicitPositioning>& GetRibExplicitPositioning_choice2();

        TIGL_EXPORT virtual const CCPACSWingRibCrossSection& GetRibCrossSection() const;
        TIGL_EXPORT virtual CCPACSWingRibCrossSection& GetRibCrossSection();

        TIGL_EXPORT virtual CCPACSWingRibsPositioning& GetRibsPositioning_choice1(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveRibsPositioning_choice1();

        TIGL_EXPORT virtual CCPACSWingRibExplicitPositioning& GetRibExplicitPositioning_choice2(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveRibExplicitPositioning_choice2();

    protected:
        CCPACSWingRibsDefinitions* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string                                       m_uID;

        /// Name of the rib set
        std::string                                       m_name;

        /// Description of the rib set
        boost::optional<std::string>                      m_description;

        boost::optional<CCPACSWingRibsPositioning>        m_ribsPositioning_choice1;

        boost::optional<CCPACSWingRibExplicitPositioning> m_ribExplicitPositioning_choice2;

        CCPACSWingRibCrossSection                         m_ribCrossSection;

    private:
        CPACSWingRibsDefinition(const CPACSWingRibsDefinition&) = delete;
        CPACSWingRibsDefinition& operator=(const CPACSWingRibsDefinition&) = delete;

        CPACSWingRibsDefinition(CPACSWingRibsDefinition&&) = delete;
        CPACSWingRibsDefinition& operator=(CPACSWingRibsDefinition&&) = delete;
    };
} // namespace generated

// CPACSWingRibsDefinition is customized, use type CCPACSWingRibsDefinition directly
} // namespace tigl
