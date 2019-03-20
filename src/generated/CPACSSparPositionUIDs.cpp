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

#include "CPACSSparPositionUIDs.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSSparPositionUIDs::CPACSSparPositionUIDs()
    {
    }

    CPACSSparPositionUIDs::~CPACSSparPositionUIDs()
    {
    }

    void CPACSSparPositionUIDs::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element sparPositionUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/sparPositionUID")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/sparPositionUID", m_sparPositionUIDs, 2, 2147483647);
        }

    }

    void CPACSSparPositionUIDs::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element sparPositionUID
        tixi::TixiSaveElements(tixiHandle, xpath + "/sparPositionUID", m_sparPositionUIDs);

    }

    const std::vector<std::string>& CPACSSparPositionUIDs::GetSparPositionUIDs() const
    {
        return m_sparPositionUIDs;
    }

    std::vector<std::string>& CPACSSparPositionUIDs::GetSparPositionUIDs()
    {
        return m_sparPositionUIDs;
    }

} // namespace generated
} // namespace tigl
