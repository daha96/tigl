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

#include <cassert>
#include <CCPACSProfileBasedStructuralElement.h>
#include "CPACSProfileBasedStructuralElements.h"
#include "CPACSStructuralElements.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSProfileBasedStructuralElements::CPACSProfileBasedStructuralElements(CPACSStructuralElements* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSProfileBasedStructuralElements::~CPACSProfileBasedStructuralElements()
    {
    }

    const CPACSStructuralElements* CPACSProfileBasedStructuralElements::GetParent() const
    {
        return m_parent;
    }

    CPACSStructuralElements* CPACSProfileBasedStructuralElements::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSProfileBasedStructuralElements::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSProfileBasedStructuralElements::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSProfileBasedStructuralElements::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSProfileBasedStructuralElements::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSProfileBasedStructuralElements::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element profileBasedStructuralElement
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/profileBasedStructuralElement")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/profileBasedStructuralElement", m_profileBasedStructuralElements, 1, tixi::xsdUnbounded, this, m_uidMgr);
        }

    }

    void CPACSProfileBasedStructuralElements::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element profileBasedStructuralElement
        tixi::TixiSaveElements(tixiHandle, xpath + "/profileBasedStructuralElement", m_profileBasedStructuralElements);

    }

    const std::vector<std::unique_ptr<CCPACSProfileBasedStructuralElement>>& CPACSProfileBasedStructuralElements::GetProfileBasedStructuralElements() const
    {
        return m_profileBasedStructuralElements;
    }

    std::vector<std::unique_ptr<CCPACSProfileBasedStructuralElement>>& CPACSProfileBasedStructuralElements::GetProfileBasedStructuralElements()
    {
        return m_profileBasedStructuralElements;
    }

    CCPACSProfileBasedStructuralElement& CPACSProfileBasedStructuralElements::AddProfileBasedStructuralElement()
    {
        m_profileBasedStructuralElements.push_back(make_unique<CCPACSProfileBasedStructuralElement>(this, m_uidMgr));
        return *m_profileBasedStructuralElements.back();
    }

    void CPACSProfileBasedStructuralElements::RemoveProfileBasedStructuralElement(CCPACSProfileBasedStructuralElement& ref)
    {
        for (std::size_t i = 0; i < m_profileBasedStructuralElements.size(); i++) {
            if (m_profileBasedStructuralElements[i].get() == &ref) {
                m_profileBasedStructuralElements.erase(m_profileBasedStructuralElements.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
