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

#include <string>
#include <tixi.h>
#include <vector>
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSProfileBasedStructuralElement;

namespace generated
{
    // This class is used in:
    // CPACSStructuralElements

    // generated from /xsd:schema/xsd:complexType[745]
    /// @brief structuralElementType
    /// 
    /// profileBasedStructuralElement type, containing a list
    /// of profile based structural elements
    /// 
    class CPACSProfileBasedStructuralElements
    {
    public:
        TIGL_EXPORT CPACSProfileBasedStructuralElements(CTiglUIDManager* uidMgr);
        TIGL_EXPORT virtual ~CPACSProfileBasedStructuralElements();

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<std::unique_ptr<CCPACSProfileBasedStructuralElement>>& GetProfileBasedStructuralElements() const;
        TIGL_EXPORT virtual std::vector<std::unique_ptr<CCPACSProfileBasedStructuralElement>>& GetProfileBasedStructuralElements();

        TIGL_EXPORT virtual CCPACSProfileBasedStructuralElement& AddProfileBasedStructuralElement();
        TIGL_EXPORT virtual void RemoveProfileBasedStructuralElement(CCPACSProfileBasedStructuralElement& ref);

    protected:
        CTiglUIDManager* m_uidMgr;

        std::vector<std::unique_ptr<CCPACSProfileBasedStructuralElement>> m_profileBasedStructuralElements;

    private:
        CPACSProfileBasedStructuralElements(const CPACSProfileBasedStructuralElements&) = delete;
        CPACSProfileBasedStructuralElements& operator=(const CPACSProfileBasedStructuralElements&) = delete;

        CPACSProfileBasedStructuralElements(CPACSProfileBasedStructuralElements&&) = delete;
        CPACSProfileBasedStructuralElements& operator=(CPACSProfileBasedStructuralElements&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSProfileBasedStructuralElements = generated::CPACSProfileBasedStructuralElements;
} // namespace tigl
