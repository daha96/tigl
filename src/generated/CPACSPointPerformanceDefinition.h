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
#include "CPACSEnvironment.h"
#include "CPACSPointPerformanceConstraints.h"
#include "CPACSPointPerformanceDefinition_typeOfPointPerformance.h"
#include "CPACSPointPerformanceRequirements.h"
#include "CreateIfNotExists.h"
#include "CTiglUIDObject.h"
#include "ITiglUIDRefObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;

namespace generated
{
    class CPACSPointPerformanceDefinitions;

    // This class is used in:
    // CPACSPointPerformanceDefinitions

    /// @brief pointPerformanceType
    /// 
    /// Specific performance settings for the point performance calculation (e.g.: a cruise Mach number)
    /// 
    class CPACSPointPerformanceDefinition : public CTiglReqUIDObject, public ITiglUIDRefObject
    {
    public:
        TIGL_EXPORT CPACSPointPerformanceDefinition(CPACSPointPerformanceDefinitions* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSPointPerformanceDefinition();

        TIGL_EXPORT CPACSPointPerformanceDefinitions* GetParent();

        TIGL_EXPORT const CPACSPointPerformanceDefinitions* GetParent() const;

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

        TIGL_EXPORT virtual const boost::optional<std::string>& GetSegmentUID_choice1() const;
        TIGL_EXPORT virtual void SetSegmentUID_choice1(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetMassFraction_choice2() const;
        TIGL_EXPORT virtual void SetMassFraction_choice2(const boost::optional<double>& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetFuelFraction_choice3() const;
        TIGL_EXPORT virtual void SetFuelFraction_choice3(const boost::optional<double>& value);

        TIGL_EXPORT virtual const CPACSPointPerformanceDefinition_typeOfPointPerformance& GetTypeOfPointPerformance() const;
        TIGL_EXPORT virtual void SetTypeOfPointPerformance(const CPACSPointPerformanceDefinition_typeOfPointPerformance& value);

        TIGL_EXPORT virtual const boost::optional<CPACSPointPerformanceConstraints>& GetConstraints() const;
        TIGL_EXPORT virtual boost::optional<CPACSPointPerformanceConstraints>& GetConstraints();

        TIGL_EXPORT virtual const boost::optional<CPACSPointPerformanceRequirements>& GetRequirements() const;
        TIGL_EXPORT virtual boost::optional<CPACSPointPerformanceRequirements>& GetRequirements();

        TIGL_EXPORT virtual const boost::optional<CPACSEnvironment>& GetEnvironment() const;
        TIGL_EXPORT virtual boost::optional<CPACSEnvironment>& GetEnvironment();

        TIGL_EXPORT virtual CPACSPointPerformanceConstraints& GetConstraints(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveConstraints();

        TIGL_EXPORT virtual CPACSPointPerformanceRequirements& GetRequirements(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveRequirements();

        TIGL_EXPORT virtual CPACSEnvironment& GetEnvironment(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveEnvironment();

    protected:
        CPACSPointPerformanceDefinitions* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string                                            m_uID;

        /// Name
        std::string                                            m_name;

        /// Description
        boost::optional<std::string>                           m_description;

        /// Defines at which part of the mission
        /// the point performance should be
        /// considered - after indicated segment
        /// of the mission as defined in
        /// performanceCase
        boost::optional<std::string>                           m_segmentUID_choice1;

        /// Defines at which part of the mission
        /// the point performance should be
        /// considered - at the defined
        /// massFraction within the mission as
        /// defined in performanceCase
        /// (mCurrent/mTO)
        boost::optional<double>                                m_massFraction_choice2;

        /// Defines at which part of the mission
        /// the point performance should be
        /// considered - at the defined
        /// fuelFraction within the mission as
        /// defined in performanceCase
        /// (mFuelCurrent/mFuelTO)
        boost::optional<double>                                m_fuelFraction_choice3;

        /// Indicates the type of point performance
        CPACSPointPerformanceDefinition_typeOfPointPerformance m_typeOfPointPerformance;

        boost::optional<CPACSPointPerformanceConstraints>      m_constraints;

        boost::optional<CPACSPointPerformanceRequirements>     m_requirements;

        boost::optional<CPACSEnvironment>                      m_environment;

    private:
        TIGL_EXPORT const CTiglUIDObject* GetNextUIDObject() const final;
        TIGL_EXPORT void NotifyUIDChange(const std::string& oldUid, const std::string& newUid) final;

        CPACSPointPerformanceDefinition(const CPACSPointPerformanceDefinition&) = delete;
        CPACSPointPerformanceDefinition& operator=(const CPACSPointPerformanceDefinition&) = delete;

        CPACSPointPerformanceDefinition(CPACSPointPerformanceDefinition&&) = delete;
        CPACSPointPerformanceDefinition& operator=(CPACSPointPerformanceDefinition&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSPointPerformanceDefinition = generated::CPACSPointPerformanceDefinition;
using CCPACSPointPerformanceDefinitions = generated::CPACSPointPerformanceDefinitions;
} // namespace tigl