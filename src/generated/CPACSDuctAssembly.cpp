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
#include <CCPACSDuct.h>
#include "CCPACSDucts.h"
#include "CPACSDuctAssembly.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSDuctAssembly::CPACSDuctAssembly(CCPACSDucts* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSDuctAssembly::~CPACSDuctAssembly()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
        if (m_uidMgr) {
            if (m_parentUID && !m_parentUID->empty()) m_uidMgr->TryUnregisterReference(*m_parentUID, *this);
        }
    }

    const CCPACSDucts* CPACSDuctAssembly::GetParent() const
    {
        return m_parent;
    }

    CCPACSDucts* CPACSDuctAssembly::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSDuctAssembly::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSDuctAssembly::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSDuctAssembly::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSDuctAssembly::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSDuctAssembly::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
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

        // read element parentUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/parentUID")) {
            m_parentUID = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/parentUID");
            if (m_parentUID->empty()) {
                LOG(WARNING) << "Optional element parentUID is present but empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_parentUID->empty()) m_uidMgr->RegisterReference(*m_parentUID, *this);
        }

        // read element transformation
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/transformation")) {
            m_transformation = boost::in_place(reinterpret_cast<CCPACSDuctAssembly*>(this), m_uidMgr);
            try {
                m_transformation->ReadCPACS(tixiHandle, xpath + "/transformation");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read transformation at xpath " << xpath << ": " << e.what();
                m_transformation = boost::none;
            }
        }

        // read element excludeObjectUIDs
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/excludeObjectUIDs")) {
            m_excludeObjectUIDs = boost::in_place(reinterpret_cast<CCPACSDuctAssembly*>(this), m_uidMgr);
            try {
                m_excludeObjectUIDs->ReadCPACS(tixiHandle, xpath + "/excludeObjectUIDs");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read excludeObjectUIDs at xpath " << xpath << ": " << e.what();
                m_excludeObjectUIDs = boost::none;
            }
        }

        // read element duct
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/duct")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/duct", m_ducts, 1, tixi::xsdUnbounded, reinterpret_cast<CCPACSDuctAssembly*>(this), m_uidMgr);
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSDuctAssembly::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        const std::vector<std::string> childElemOrder = { "name", "description", "parentUID", "transformation", "excludeObjectUIDs", "duct" };

        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write element name
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/name", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/name", m_name);

        // write element description
        if (m_description) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/description", childElemOrder);
            tixi::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/description");
            }
        }

        // write element parentUID
        if (m_parentUID) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/parentUID", childElemOrder);
            tixi::TixiSaveElement(tixiHandle, xpath + "/parentUID", *m_parentUID);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/parentUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/parentUID");
            }
        }

        // write element transformation
        if (m_transformation) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/transformation", childElemOrder);
            m_transformation->WriteCPACS(tixiHandle, xpath + "/transformation");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/transformation")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/transformation");
            }
        }

        // write element excludeObjectUIDs
        if (m_excludeObjectUIDs) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/excludeObjectUIDs", childElemOrder);
            m_excludeObjectUIDs->WriteCPACS(tixiHandle, xpath + "/excludeObjectUIDs");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/excludeObjectUIDs")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/excludeObjectUIDs");
            }
        }

        // write element duct
        tixi::TixiSaveElements(tixiHandle, xpath + "/duct", m_ducts);

    }

    const std::string& CPACSDuctAssembly::GetUID() const
    {
        return m_uID;
    }

    void CPACSDuctAssembly::SetUID(const std::string& value)
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

    const std::string& CPACSDuctAssembly::GetName() const
    {
        return m_name;
    }

    void CPACSDuctAssembly::SetName(const std::string& value)
    {
        m_name = value;
    }

    const boost::optional<std::string>& CPACSDuctAssembly::GetDescription() const
    {
        return m_description;
    }

    void CPACSDuctAssembly::SetDescription(const boost::optional<std::string>& value)
    {
        m_description = value;
    }

    const boost::optional<std::string>& CPACSDuctAssembly::GetParentUID() const
    {
        return m_parentUID;
    }

    void CPACSDuctAssembly::SetParentUID(const boost::optional<std::string>& value)
    {
        if (m_uidMgr) {
            if (m_parentUID && !m_parentUID->empty()) m_uidMgr->TryUnregisterReference(*m_parentUID, *this);
            if (value && !value->empty()) m_uidMgr->RegisterReference(*value, *this);
        }
        m_parentUID = value;
    }

    const boost::optional<CCPACSTransformation>& CPACSDuctAssembly::GetTransformation() const
    {
        return m_transformation;
    }

    boost::optional<CCPACSTransformation>& CPACSDuctAssembly::GetTransformation()
    {
        return m_transformation;
    }

    const boost::optional<CPACSUIDSequence>& CPACSDuctAssembly::GetExcludeObjectUIDs() const
    {
        return m_excludeObjectUIDs;
    }

    boost::optional<CPACSUIDSequence>& CPACSDuctAssembly::GetExcludeObjectUIDs()
    {
        return m_excludeObjectUIDs;
    }

    const std::vector<std::unique_ptr<CCPACSDuct>>& CPACSDuctAssembly::GetDucts() const
    {
        return m_ducts;
    }

    std::vector<std::unique_ptr<CCPACSDuct>>& CPACSDuctAssembly::GetDucts()
    {
        return m_ducts;
    }

    CCPACSTransformation& CPACSDuctAssembly::GetTransformation(CreateIfNotExistsTag)
    {
        if (!m_transformation)
            m_transformation = boost::in_place(reinterpret_cast<CCPACSDuctAssembly*>(this), m_uidMgr);
        return *m_transformation;
    }

    void CPACSDuctAssembly::RemoveTransformation()
    {
        m_transformation = boost::none;
    }

    CPACSUIDSequence& CPACSDuctAssembly::GetExcludeObjectUIDs(CreateIfNotExistsTag)
    {
        if (!m_excludeObjectUIDs)
            m_excludeObjectUIDs = boost::in_place(reinterpret_cast<CCPACSDuctAssembly*>(this), m_uidMgr);
        return *m_excludeObjectUIDs;
    }

    void CPACSDuctAssembly::RemoveExcludeObjectUIDs()
    {
        m_excludeObjectUIDs = boost::none;
    }

    CCPACSDuct& CPACSDuctAssembly::AddDuct()
    {
        m_ducts.push_back(make_unique<CCPACSDuct>(reinterpret_cast<CCPACSDuctAssembly*>(this), m_uidMgr));
        return *m_ducts.back();
    }

    void CPACSDuctAssembly::RemoveDuct(CCPACSDuct& ref)
    {
        for (std::size_t i = 0; i < m_ducts.size(); i++) {
            if (m_ducts[i].get() == &ref) {
                m_ducts.erase(m_ducts.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

    const CTiglUIDObject* CPACSDuctAssembly::GetNextUIDObject() const
    {
        return this;
    }

    void CPACSDuctAssembly::NotifyUIDChange(const std::string& oldUid, const std::string& newUid)
    {
        if (m_parentUID && *m_parentUID == oldUid) {
            m_parentUID = newUid;
        }
    }

} // namespace generated
} // namespace tigl
