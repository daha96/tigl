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
#include <CCPACSPressureBulkheadAssemblyPosition.h>
#include "CCPACSFuselageStructure.h"
#include "CPACSPressureBulkheadAssembly.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSPressureBulkheadAssembly::CPACSPressureBulkheadAssembly(CCPACSFuselageStructure* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSPressureBulkheadAssembly::~CPACSPressureBulkheadAssembly()
    {
    }

    const CCPACSFuselageStructure* CPACSPressureBulkheadAssembly::GetParent() const
    {
        return m_parent;
    }

    CCPACSFuselageStructure* CPACSPressureBulkheadAssembly::GetParent()
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSPressureBulkheadAssembly::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSPressureBulkheadAssembly::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSPressureBulkheadAssembly::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element pressureBulkhead
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/pressureBulkhead")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/pressureBulkhead", m_pressureBulkheads, 1, 2147483647, reinterpret_cast<CCPACSPressureBulkheadAssembly*>(this), m_uidMgr);
        }

    }

    void CPACSPressureBulkheadAssembly::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element pressureBulkhead
        tixi::TixiSaveElements(tixiHandle, xpath + "/pressureBulkhead", m_pressureBulkheads);

    }

    const std::vector<std::unique_ptr<CCPACSPressureBulkheadAssemblyPosition>>& CPACSPressureBulkheadAssembly::GetPressureBulkheads() const
    {
        return m_pressureBulkheads;
    }

    std::vector<std::unique_ptr<CCPACSPressureBulkheadAssemblyPosition>>& CPACSPressureBulkheadAssembly::GetPressureBulkheads()
    {
        return m_pressureBulkheads;
    }

    CCPACSPressureBulkheadAssemblyPosition& CPACSPressureBulkheadAssembly::AddPressureBulkhead()
    {
        m_pressureBulkheads.push_back(make_unique<CCPACSPressureBulkheadAssemblyPosition>(reinterpret_cast<CCPACSPressureBulkheadAssembly*>(this), m_uidMgr));
        return *m_pressureBulkheads.back();
    }

    void CPACSPressureBulkheadAssembly::RemovePressureBulkhead(CCPACSPressureBulkheadAssemblyPosition& ref)
    {
        for (std::size_t i = 0; i < m_pressureBulkheads.size(); i++) {
            if (m_pressureBulkheads[i].get() == &ref) {
                m_pressureBulkheads.erase(m_pressureBulkheads.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
