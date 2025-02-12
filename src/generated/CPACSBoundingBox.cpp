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
#include "CPACSBoundingBox.h"
#include "CPACSDeckElementGeometry.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSBoundingBox::CPACSBoundingBox(CPACSDeckElementGeometry* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_deltaX(0)
        , m_deltaY(0)
        , m_deltaZ(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSBoundingBox::~CPACSBoundingBox()
    {
    }

    const CPACSDeckElementGeometry* CPACSBoundingBox::GetParent() const
    {
        return m_parent;
    }

    CPACSDeckElementGeometry* CPACSBoundingBox::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSBoundingBox::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSBoundingBox::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSBoundingBox::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSBoundingBox::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSBoundingBox::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element deltaX
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/deltaX")) {
            m_deltaX = tixi::TixiGetElement<double>(tixiHandle, xpath + "/deltaX");
        }
        else {
            LOG(ERROR) << "Required element deltaX is missing at xpath " << xpath;
        }

        // read element deltaY
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/deltaY")) {
            m_deltaY = tixi::TixiGetElement<double>(tixiHandle, xpath + "/deltaY");
        }
        else {
            LOG(ERROR) << "Required element deltaY is missing at xpath " << xpath;
        }

        // read element deltaZ
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/deltaZ")) {
            m_deltaZ = tixi::TixiGetElement<double>(tixiHandle, xpath + "/deltaZ");
        }
        else {
            LOG(ERROR) << "Required element deltaZ is missing at xpath " << xpath;
        }

        // read element origin
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/origin")) {
            m_origin = boost::in_place(this, m_uidMgr);
            try {
                m_origin->ReadCPACS(tixiHandle, xpath + "/origin");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read origin at xpath " << xpath << ": " << e.what();
                m_origin = boost::none;
            }
        }

    }

    void CPACSBoundingBox::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element deltaX
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/deltaX");
        tixi::TixiSaveElement(tixiHandle, xpath + "/deltaX", m_deltaX);

        // write element deltaY
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/deltaY");
        tixi::TixiSaveElement(tixiHandle, xpath + "/deltaY", m_deltaY);

        // write element deltaZ
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/deltaZ");
        tixi::TixiSaveElement(tixiHandle, xpath + "/deltaZ", m_deltaZ);

        // write element origin
        if (m_origin) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/origin");
            m_origin->WriteCPACS(tixiHandle, xpath + "/origin");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/origin")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/origin");
            }
        }

    }

    const double& CPACSBoundingBox::GetDeltaX() const
    {
        return m_deltaX;
    }

    void CPACSBoundingBox::SetDeltaX(const double& value)
    {
        m_deltaX = value;
    }

    const double& CPACSBoundingBox::GetDeltaY() const
    {
        return m_deltaY;
    }

    void CPACSBoundingBox::SetDeltaY(const double& value)
    {
        m_deltaY = value;
    }

    const double& CPACSBoundingBox::GetDeltaZ() const
    {
        return m_deltaZ;
    }

    void CPACSBoundingBox::SetDeltaZ(const double& value)
    {
        m_deltaZ = value;
    }

    const boost::optional<CCPACSPoint>& CPACSBoundingBox::GetOrigin() const
    {
        return m_origin;
    }

    boost::optional<CCPACSPoint>& CPACSBoundingBox::GetOrigin()
    {
        return m_origin;
    }

    CCPACSPoint& CPACSBoundingBox::GetOrigin(CreateIfNotExistsTag)
    {
        if (!m_origin)
            m_origin = boost::in_place(this, m_uidMgr);
        return *m_origin;
    }

    void CPACSBoundingBox::RemoveOrigin()
    {
        m_origin = boost::none;
    }

} // namespace generated
} // namespace tigl
