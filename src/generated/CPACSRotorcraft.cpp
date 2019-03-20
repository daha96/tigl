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

#include <CCPACSRotorcraftModel.h>
#include "CPACSRotorcraft.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSRotorcraft::CPACSRotorcraft(CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
    }

    CPACSRotorcraft::~CPACSRotorcraft()
    {
    }

    CTiglUIDManager& CPACSRotorcraft::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSRotorcraft::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSRotorcraft::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element model
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/model")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/model", m_models, 1, 2147483647, m_uidMgr);
        }

    }

    void CPACSRotorcraft::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element model
        tixi::TixiSaveElements(tixiHandle, xpath + "/model", m_models);

    }

    const std::vector<std::unique_ptr<CCPACSRotorcraftModel>>& CPACSRotorcraft::GetModels() const
    {
        return m_models;
    }

    std::vector<std::unique_ptr<CCPACSRotorcraftModel>>& CPACSRotorcraft::GetModels()
    {
        return m_models;
    }

    CCPACSRotorcraftModel& CPACSRotorcraft::AddModel()
    {
        m_models.push_back(make_unique<CCPACSRotorcraftModel>(m_uidMgr));
        return *m_models.back();
    }

    void CPACSRotorcraft::RemoveModel(CCPACSRotorcraftModel& ref)
    {
        for (std::size_t i = 0; i < m_models.size(); i++) {
            if (m_models[i].get() == &ref) {
                m_models.erase(m_models.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
