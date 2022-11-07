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
#include "CPACSAxleAssemblies.h"
#include "CPACSAxleAssembly.h"
#include "CPACSBogie.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSAxleAssemblies::CPACSAxleAssemblies(CPACSBogie* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSAxleAssemblies::~CPACSAxleAssemblies()
    {
    }

    const CPACSBogie* CPACSAxleAssemblies::GetParent() const
    {
        return m_parent;
    }

    CPACSBogie* CPACSAxleAssemblies::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSAxleAssemblies::GetNextUIDParent() const
    {
        return m_parent;
    }

    CTiglUIDObject* CPACSAxleAssemblies::GetNextUIDParent()
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSAxleAssemblies::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSAxleAssemblies::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSAxleAssemblies::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element axleAssembly
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/axleAssembly")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/axleAssembly", m_axleAssemblys, 1, tixi::xsdUnbounded, this, m_uidMgr);
        }

    }

    void CPACSAxleAssemblies::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element axleAssembly
        tixi::TixiSaveElements(tixiHandle, xpath + "/axleAssembly", m_axleAssemblys);

    }

    const std::vector<std::unique_ptr<CPACSAxleAssembly>>& CPACSAxleAssemblies::GetAxleAssemblys() const
    {
        return m_axleAssemblys;
    }

    std::vector<std::unique_ptr<CPACSAxleAssembly>>& CPACSAxleAssemblies::GetAxleAssemblys()
    {
        return m_axleAssemblys;
    }

    CPACSAxleAssembly& CPACSAxleAssemblies::AddAxleAssembly()
    {
        m_axleAssemblys.push_back(make_unique<CPACSAxleAssembly>(this, m_uidMgr));
        return *m_axleAssemblys.back();
    }

    void CPACSAxleAssemblies::RemoveAxleAssembly(CPACSAxleAssembly& ref)
    {
        for (std::size_t i = 0; i < m_axleAssemblys.size(); i++) {
            if (m_axleAssemblys[i].get() == &ref) {
                m_axleAssemblys.erase(m_axleAssemblys.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl