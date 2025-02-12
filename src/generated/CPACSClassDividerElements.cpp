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
#include "CPACSClassDividerElements.h"
#include "CPACSDeckElementBase.h"
#include "CPACSDeckElements.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSClassDividerElements::CPACSClassDividerElements(CPACSDeckElements* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSClassDividerElements::~CPACSClassDividerElements()
    {
    }

    const CPACSDeckElements* CPACSClassDividerElements::GetParent() const
    {
        return m_parent;
    }

    CPACSDeckElements* CPACSClassDividerElements::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSClassDividerElements::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSClassDividerElements::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSClassDividerElements::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSClassDividerElements::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSClassDividerElements::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element classDividerElement
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/classDividerElement")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/classDividerElement", m_classDividerElements, 1, tixi::xsdUnbounded, this, m_uidMgr);
        }

    }

    void CPACSClassDividerElements::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element classDividerElement
        tixi::TixiSaveElements(tixiHandle, xpath + "/classDividerElement", m_classDividerElements);

    }

    const std::vector<std::unique_ptr<CPACSDeckElementBase>>& CPACSClassDividerElements::GetClassDividerElements() const
    {
        return m_classDividerElements;
    }

    std::vector<std::unique_ptr<CPACSDeckElementBase>>& CPACSClassDividerElements::GetClassDividerElements()
    {
        return m_classDividerElements;
    }

    CPACSDeckElementBase& CPACSClassDividerElements::AddClassDividerElement()
    {
        m_classDividerElements.push_back(make_unique<CPACSDeckElementBase>(this, m_uidMgr));
        return *m_classDividerElements.back();
    }

    void CPACSClassDividerElements::RemoveClassDividerElement(CPACSDeckElementBase& ref)
    {
        for (std::size_t i = 0; i < m_classDividerElements.size(); i++) {
            if (m_classDividerElements[i].get() == &ref) {
                m_classDividerElements.erase(m_classDividerElements.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
