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

#include <cassert>
#include <CCPACSWing.h>
#include "CCPACSAircraftModel.h"
#include "CCPACSRotorcraftModel.h"
#include "CPACSWings.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSWings::CPACSWings(CCPACSAircraftModel* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSAircraftModel);
    }

    CPACSWings::CPACSWings(CCPACSRotorcraftModel* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSRotorcraftModel);
    }

    CPACSWings::~CPACSWings()
    {
    }

    CTiglUIDManager& CPACSWings::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSWings::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSWings::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element wing
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/wing")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/wing", m_wings, 1, 2147483647, reinterpret_cast<CCPACSWings*>(this), m_uidMgr);
        }

    }

    void CPACSWings::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element wing
        tixi::TixiSaveElements(tixiHandle, xpath + "/wing", m_wings);

    }

    const std::vector<std::unique_ptr<CCPACSWing>>& CPACSWings::GetWings() const
    {
        return m_wings;
    }

    std::vector<std::unique_ptr<CCPACSWing>>& CPACSWings::GetWings()
    {
        return m_wings;
    }

    CCPACSWing& CPACSWings::AddWing()
    {
        m_wings.push_back(make_unique<CCPACSWing>(reinterpret_cast<CCPACSWings*>(this), m_uidMgr));
        return *m_wings.back();
    }

    void CPACSWings::RemoveWing(CCPACSWing& ref)
    {
        for (std::size_t i = 0; i < m_wings.size(); i++) {
            if (m_wings[i].get() == &ref) {
                m_wings.erase(m_wings.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
