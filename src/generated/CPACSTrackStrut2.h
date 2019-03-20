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

#include <CCPACSMaterialDefinition.h>
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
namespace generated
{
    // This class is used in:
    // CPACSTrackStructure

    // generated from /xsd:schema/xsd:complexType[887]
    /// @brief trackStrut2Type
    /// 
    /// 
    /// 
    class CPACSTrackStrut2
    {
    public:
        TIGL_EXPORT CPACSTrackStrut2();
        TIGL_EXPORT virtual ~CPACSTrackStrut2();

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const CCPACSMaterialDefinition& GetMaterial() const;
        TIGL_EXPORT virtual CCPACSMaterialDefinition& GetMaterial();

    protected:
        /// Definition of the material properties.
        CCPACSMaterialDefinition m_material;

    private:
        CPACSTrackStrut2(const CPACSTrackStrut2&) = delete;
        CPACSTrackStrut2& operator=(const CPACSTrackStrut2&) = delete;

        CPACSTrackStrut2(CPACSTrackStrut2&&) = delete;
        CPACSTrackStrut2& operator=(CPACSTrackStrut2&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSTrackStrut2 = generated::CPACSTrackStrut2;
} // namespace tigl
