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

#include "CPACSUpdate.h"
#include "CPACSUpdates.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSUpdates::CPACSUpdates()
    {
    }

    CPACSUpdates::~CPACSUpdates()
    {
    }

    void CPACSUpdates::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element update
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/update")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/update", m_updates, 1, 2147483647);
        }

    }

    void CPACSUpdates::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element update
        tixi::TixiSaveElements(tixiHandle, xpath + "/update", m_updates);

    }

    const std::vector<std::unique_ptr<CPACSUpdate>>& CPACSUpdates::GetUpdates() const
    {
        return m_updates;
    }

    std::vector<std::unique_ptr<CPACSUpdate>>& CPACSUpdates::GetUpdates()
    {
        return m_updates;
    }

    CPACSUpdate& CPACSUpdates::AddUpdate()
    {
        m_updates.push_back(make_unique<CPACSUpdate>());
        return *m_updates.back();
    }

    void CPACSUpdates::RemoveUpdate(CPACSUpdate& ref)
    {
        for (std::size_t i = 0; i < m_updates.size(); i++) {
            if (m_updates[i].get() == &ref) {
                m_updates.erase(m_updates.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
