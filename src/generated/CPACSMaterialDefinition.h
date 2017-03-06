// Copyright (c) 2016 RISC Software GmbH
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

#include <tixi.h>
#include <string>
#include <boost/optional.hpp>
#include "tigl_internal.h"

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSActuatorControlSurfaceAttachment
        // CPACSActuatorFuselageWingAttachment
        // CPACSActuatorParentAttachment
        // CPACSAttachmentPin
        // CPACSCap
        // CPACSCruiseRoller
        // CPACSInterConnectionStrutAttachment
        // CPACSInterconnectionStrut
        // CPACSTrackActuator
        // CPACSTrackCar
        // CPACSTrackFairing
        // CPACSTrackStructure
        // CPACSTrackStrut1
        // CPACSTrackStrut2
        // CPACSWeb
        // CPACSWingIntermediateStructureCell
        // CPACSWingRibCell
        // CPACSWingRibCrossSection
        // CPACSWingSkin
        // CPACSZCoupling
        
        // generated from /xsd:schema/xsd:complexType[640]
        class CPACSMaterialDefinition
        {
        public:
            TIGL_EXPORT CPACSMaterialDefinition();
            TIGL_EXPORT virtual ~CPACSMaterialDefinition();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT bool HasCompositeUID_choice1() const;
            TIGL_EXPORT const std::string& GetCompositeUID_choice1() const;
            TIGL_EXPORT void SetCompositeUID_choice1(const std::string& value);
            
            TIGL_EXPORT bool HasOrthotropyDirection_choice1() const;
            TIGL_EXPORT const double& GetOrthotropyDirection_choice1() const;
            TIGL_EXPORT void SetOrthotropyDirection_choice1(const double& value);
            
            TIGL_EXPORT bool HasThicknessScaling_choice1() const;
            TIGL_EXPORT const double& GetThicknessScaling_choice1() const;
            TIGL_EXPORT void SetThicknessScaling_choice1(const double& value);
            
            TIGL_EXPORT bool HasMaterialUID_choice2() const;
            TIGL_EXPORT const std::string& GetMaterialUID_choice2() const;
            TIGL_EXPORT void SetMaterialUID_choice2(const std::string& value);
            
            TIGL_EXPORT bool HasThickness_choice2() const;
            TIGL_EXPORT const double& GetThickness_choice2() const;
            TIGL_EXPORT void SetThickness_choice2(const double& value);
            
        protected:
            boost::optional<std::string> m_compositeUID_choice1;
            boost::optional<double>      m_orthotropyDirection_choice1;
            boost::optional<double>      m_thicknessScaling_choice1;
            boost::optional<std::string> m_materialUID_choice2;
            boost::optional<double>      m_thickness_choice2;
            
        private:
            #ifdef HAVE_CPP11
            CPACSMaterialDefinition(const CPACSMaterialDefinition&) = delete;
            CPACSMaterialDefinition& operator=(const CPACSMaterialDefinition&) = delete;
            
            CPACSMaterialDefinition(CPACSMaterialDefinition&&) = delete;
            CPACSMaterialDefinition& operator=(CPACSMaterialDefinition&&) = delete;
            #else
            CPACSMaterialDefinition(const CPACSMaterialDefinition&);
            CPACSMaterialDefinition& operator=(const CPACSMaterialDefinition&);
            #endif
        };
    }
    
    // This type is customized, use type CCPACSMaterial
}
