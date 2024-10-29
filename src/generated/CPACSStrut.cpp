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
#include "CPACSLandingGearComponentAssembly.h"
#include "CPACSStrut.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSStrut::CPACSStrut(CPACSLandingGearComponentAssembly* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_length(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSStrut::~CPACSStrut()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
        if (m_uidMgr) {
            if (m_materialUID_choice1 && !m_materialUID_choice1->empty()) m_uidMgr->TryUnregisterReference(*m_materialUID_choice1, *this);
            if (m_structuralElementUID_choice2 && !m_structuralElementUID_choice2->empty()) m_uidMgr->TryUnregisterReference(*m_structuralElementUID_choice2, *this);
        }
    }

    const CPACSLandingGearComponentAssembly* CPACSStrut::GetParent() const
    {
        return m_parent;
    }

    CPACSLandingGearComponentAssembly* CPACSStrut::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSStrut::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSStrut::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSStrut::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSStrut::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSStrut::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element radius
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/radius")) {
            m_radius_choice1 = tixi::TixiGetElement<double>(tixiHandle, xpath + "/radius");
        }

        // read element materialUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/materialUID")) {
            m_materialUID_choice1 = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/materialUID");
            if (m_materialUID_choice1->empty()) {
                LOG(WARNING) << "Optional element materialUID is present but empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_materialUID_choice1->empty()) m_uidMgr->RegisterReference(*m_materialUID_choice1, *this);
        }

        // read element innerRadius
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/innerRadius")) {
            m_innerRadius_choice1 = tixi::TixiGetElement<double>(tixiHandle, xpath + "/innerRadius");
        }

        // read element structuralElementUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/structuralElementUID")) {
            m_structuralElementUID_choice2 = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/structuralElementUID");
            if (m_structuralElementUID_choice2->empty()) {
                LOG(WARNING) << "Optional element structuralElementUID is present but empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_structuralElementUID_choice2->empty()) m_uidMgr->RegisterReference(*m_structuralElementUID_choice2, *this);
        }

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

        // read element length
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/length")) {
            m_length = tixi::TixiGetElement<double>(tixiHandle, xpath + "/length");
        }
        else {
            LOG(ERROR) << "Required element length is missing at xpath " << xpath;
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
        if (!ValidateChoices()) {
            LOG(ERROR) << "Invalid choice configuration at xpath " << xpath;
        }
    }

    void CPACSStrut::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element radius
        if (m_radius_choice1) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/radius");
            tixi::TixiSaveElement(tixiHandle, xpath + "/radius", *m_radius_choice1);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/radius")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/radius");
            }
        }

        // write element materialUID
        if (m_materialUID_choice1) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/materialUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/materialUID", *m_materialUID_choice1);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/materialUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/materialUID");
            }
        }

        // write element innerRadius
        if (m_innerRadius_choice1) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/innerRadius");
            tixi::TixiSaveElement(tixiHandle, xpath + "/innerRadius", *m_innerRadius_choice1);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/innerRadius")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/innerRadius");
            }
        }

        // write element structuralElementUID
        if (m_structuralElementUID_choice2) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/structuralElementUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/structuralElementUID", *m_structuralElementUID_choice2);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/structuralElementUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/structuralElementUID");
            }
        }

        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write element length
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/length");
        tixi::TixiSaveElement(tixiHandle, xpath + "/length", m_length);

    }

    bool CPACSStrut::ValidateChoices() const
    {
        return
        (
            (
                (
                    // mandatory elements of this choice must be there
                    m_radius_choice1.is_initialized()
                    &&
                    m_materialUID_choice1.is_initialized()
                    &&
                    true // m_innerRadius_choice1 is optional in choice
                    &&
                    // elements of other choices must not be there
                    !(
                        m_structuralElementUID_choice2.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_structuralElementUID_choice2.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_radius_choice1.is_initialized()
                        ||
                        m_materialUID_choice1.is_initialized()
                        ||
                        m_innerRadius_choice1.is_initialized()
                    )
                )
                == 1
            )
        )
        ;
    }

    const boost::optional<double>& CPACSStrut::GetRadius_choice1() const
    {
        return m_radius_choice1;
    }

    void CPACSStrut::SetRadius_choice1(const boost::optional<double>& value)
    {
        m_radius_choice1 = value;
    }

    const boost::optional<std::string>& CPACSStrut::GetMaterialUID_choice1() const
    {
        return m_materialUID_choice1;
    }

    void CPACSStrut::SetMaterialUID_choice1(const boost::optional<std::string>& value)
    {
        if (m_uidMgr) {
            if (m_materialUID_choice1 && !m_materialUID_choice1->empty()) m_uidMgr->TryUnregisterReference(*m_materialUID_choice1, *this);
            if (value && !value->empty()) m_uidMgr->RegisterReference(*value, *this);
        }
        m_materialUID_choice1 = value;
    }

    const boost::optional<double>& CPACSStrut::GetInnerRadius_choice1() const
    {
        return m_innerRadius_choice1;
    }

    void CPACSStrut::SetInnerRadius_choice1(const boost::optional<double>& value)
    {
        m_innerRadius_choice1 = value;
    }

    const boost::optional<std::string>& CPACSStrut::GetStructuralElementUID_choice2() const
    {
        return m_structuralElementUID_choice2;
    }

    void CPACSStrut::SetStructuralElementUID_choice2(const boost::optional<std::string>& value)
    {
        if (m_uidMgr) {
            if (m_structuralElementUID_choice2 && !m_structuralElementUID_choice2->empty()) m_uidMgr->TryUnregisterReference(*m_structuralElementUID_choice2, *this);
            if (value && !value->empty()) m_uidMgr->RegisterReference(*value, *this);
        }
        m_structuralElementUID_choice2 = value;
    }

    const std::string& CPACSStrut::GetUID() const
    {
        return m_uID;
    }

    void CPACSStrut::SetUID(const std::string& value)
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

    const double& CPACSStrut::GetLength() const
    {
        return m_length;
    }

    void CPACSStrut::SetLength(const double& value)
    {
        m_length = value;
    }

    const CTiglUIDObject* CPACSStrut::GetNextUIDObject() const
    {
        return this;
    }

    void CPACSStrut::NotifyUIDChange(const std::string& oldUid, const std::string& newUid)
    {
        if (m_materialUID_choice1 && *m_materialUID_choice1 == oldUid) {
            m_materialUID_choice1 = newUid;
        }
        if (m_structuralElementUID_choice2 && *m_structuralElementUID_choice2 == oldUid) {
            m_structuralElementUID_choice2 = newUid;
        }
    }

} // namespace generated
} // namespace tigl
