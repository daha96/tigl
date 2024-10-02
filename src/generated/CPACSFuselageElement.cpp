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
#include "CCPACSFuselageSectionElements.h"
#include "CPACSFuselageElement.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSFuselageElement::CPACSFuselageElement(CCPACSFuselageSectionElements* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_transformation(reinterpret_cast<CCPACSFuselageSectionElement*>(this), m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSFuselageElement::~CPACSFuselageElement()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
        if (m_uidMgr) {
            if (!m_profileUID.empty()) m_uidMgr->TryUnregisterReference(m_profileUID, *this);
        }
    }

    const CCPACSFuselageSectionElements* CPACSFuselageElement::GetParent() const
    {
        return m_parent;
    }

    CCPACSFuselageSectionElements* CPACSFuselageElement::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSFuselageElement::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSFuselageElement::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSFuselageElement::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSFuselageElement::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSFuselageElement::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
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

        // read element profileUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/profileUID")) {
            m_profileUID = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/profileUID");
            if (m_profileUID.empty()) {
                LOG(WARNING) << "Required element profileUID is empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_profileUID.empty()) m_uidMgr->RegisterReference(m_profileUID, *this);
        }
        else {
            LOG(ERROR) << "Required element profileUID is missing at xpath " << xpath;
        }

        // read element transformation
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/transformation")) {
            m_transformation.ReadCPACS(tixiHandle, xpath + "/transformation");
        }
        else {
            LOG(ERROR) << "Required element transformation is missing at xpath " << xpath;
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSFuselageElement::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
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

        // write element profileUID
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/profileUID");
        tixi::TixiSaveElement(tixiHandle, xpath + "/profileUID", m_profileUID);

        // write element transformation
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/transformation");
        m_transformation.WriteCPACS(tixiHandle, xpath + "/transformation");

    }

    const std::string& CPACSFuselageElement::GetUID() const
    {
        return m_uID;
    }

    void CPACSFuselageElement::SetUID(const std::string& value)
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

    const std::string& CPACSFuselageElement::GetName() const
    {
        return m_name;
    }

    void CPACSFuselageElement::SetName(const std::string& value)
    {
        m_name = value;
    }

    const boost::optional<std::string>& CPACSFuselageElement::GetDescription() const
    {
        return m_description;
    }

    void CPACSFuselageElement::SetDescription(const boost::optional<std::string>& value)
    {
        m_description = value;
    }

    const std::string& CPACSFuselageElement::GetProfileUID() const
    {
        return m_profileUID;
    }

    void CPACSFuselageElement::SetProfileUID(const std::string& value)
    {
        if (m_uidMgr) {
            if (!m_profileUID.empty()) m_uidMgr->TryUnregisterReference(m_profileUID, *this);
            if (!value.empty()) m_uidMgr->RegisterReference(value, *this);
        }
        m_profileUID = value;
    }

    const CCPACSTransformation& CPACSFuselageElement::GetTransformation() const
    {
        return m_transformation;
    }

    CCPACSTransformation& CPACSFuselageElement::GetTransformation()
    {
        return m_transformation;
    }

    const CTiglUIDObject* CPACSFuselageElement::GetNextUIDObject() const
    {
        return this;
    }

    void CPACSFuselageElement::NotifyUIDChange(const std::string& oldUid, const std::string& newUid)
    {
        if (m_profileUID == oldUid) {
            m_profileUID = newUid;
        }
    }

} // namespace generated
} // namespace tigl
