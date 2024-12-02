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
#include "CPACSDeckStructuralMount.h"
#include "CPACSDeckStructuralMounts.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSDeckStructuralMount::CPACSDeckStructuralMount(CPACSDeckStructuralMounts* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSDeckStructuralMount::~CPACSDeckStructuralMount()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
        if (m_uidMgr) {
            if (!m_componentUID.empty()) m_uidMgr->TryUnregisterReference(m_componentUID, *this);
        }
    }

    const CPACSDeckStructuralMounts* CPACSDeckStructuralMount::GetParent() const
    {
        return m_parent;
    }

    CPACSDeckStructuralMounts* CPACSDeckStructuralMount::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSDeckStructuralMount::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSDeckStructuralMount::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSDeckStructuralMount::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSDeckStructuralMount::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSDeckStructuralMount::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read attribute uID
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
            m_uID = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            if (m_uID.empty()) {
                LOG(WARNING) << "Required attribute uID is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
        }

        // read element name
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/name")) {
            m_name = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
            if (m_name.empty()) {
                LOG(WARNING) << "Required element name is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element name is missing at xpath " << xpath;
        }

        // read element description
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
            m_description = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            if (m_description->empty()) {
                LOG(WARNING) << "Optional element description is present but empty at xpath " << xpath;
            }
        }

        // read element componentUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/componentUID")) {
            m_componentUID = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/componentUID");
            if (m_componentUID.empty()) {
                LOG(WARNING) << "Required element componentUID is empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_componentUID.empty()) m_uidMgr->RegisterReference(m_componentUID, *this);
        }
        else {
            LOG(ERROR) << "Required element componentUID is missing at xpath " << xpath;
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSDeckStructuralMount::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write element name
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
        tixi::TixiSaveElement(tixiHandle, xpath + "/name", m_name);

        // write element description
        if (m_description) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
            tixi::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/description");
            }
        }

        // write element componentUID
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/componentUID");
        tixi::TixiSaveElement(tixiHandle, xpath + "/componentUID", m_componentUID);

    }

    const std::string& CPACSDeckStructuralMount::GetUID() const
    {
        return m_uID;
    }

    void CPACSDeckStructuralMount::SetUID(const std::string& value)
    {
        if (m_uidMgr && value != m_uID) {
            if (m_uID.empty()) {
                m_uidMgr->RegisterObject(value, *this);
            }
            else {
                m_uidMgr->UpdateObjectUID(m_uID, value);
            }
        }
        m_uID = value;
    }

    const std::string& CPACSDeckStructuralMount::GetName() const
    {
        return m_name;
    }

    void CPACSDeckStructuralMount::SetName(const std::string& value)
    {
        m_name = value;
    }

    const boost::optional<std::string>& CPACSDeckStructuralMount::GetDescription() const
    {
        return m_description;
    }

    void CPACSDeckStructuralMount::SetDescription(const boost::optional<std::string>& value)
    {
        m_description = value;
    }

    const std::string& CPACSDeckStructuralMount::GetComponentUID() const
    {
        return m_componentUID;
    }

    void CPACSDeckStructuralMount::SetComponentUID(const std::string& value)
    {
        if (m_uidMgr) {
            if (!m_componentUID.empty()) m_uidMgr->TryUnregisterReference(m_componentUID, *this);
            if (!value.empty()) m_uidMgr->RegisterReference(value, *this);
        }
        m_componentUID = value;
    }

    const CTiglUIDObject* CPACSDeckStructuralMount::GetNextUIDObject() const
    {
        return this;
    }

    void CPACSDeckStructuralMount::NotifyUIDChange(const std::string& oldUid, const std::string& newUid)
    {
        if (m_componentUID == oldUid) {
            m_componentUID = newUid;
        }
    }

} // namespace generated
} // namespace tigl