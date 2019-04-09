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

#include "CPACSCutOutProfile.h"
#include "CPACSCutOutProfiles.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSCutOutProfiles::CPACSCutOutProfiles()
    {
    }

    CPACSCutOutProfiles::~CPACSCutOutProfiles()
    {
    }

    void CPACSCutOutProfiles::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element outerCutOutProfile
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/outerCutOutProfile")) {
            m_outerCutOutProfile.ReadCPACS(tixiHandle, xpath + "/outerCutOutProfile");
        }
        else {
            LOG(ERROR) << "Required element outerCutOutProfile is missing at xpath " << xpath;
        }

        // read element innerCutOutProfile
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/innerCutOutProfile")) {
            m_innerCutOutProfile.ReadCPACS(tixiHandle, xpath + "/innerCutOutProfile");
        }
        else {
            LOG(ERROR) << "Required element innerCutOutProfile is missing at xpath " << xpath;
        }

        // read element cutOutProfile
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/cutOutProfile")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/cutOutProfile", m_cutOutProfiles, 0, tixi::xsdUnbounded);
        }

    }

    void CPACSCutOutProfiles::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element outerCutOutProfile
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/outerCutOutProfile");
        m_outerCutOutProfile.WriteCPACS(tixiHandle, xpath + "/outerCutOutProfile");

        // write element innerCutOutProfile
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/innerCutOutProfile");
        m_innerCutOutProfile.WriteCPACS(tixiHandle, xpath + "/innerCutOutProfile");

        // write element cutOutProfile
        tixi::TixiSaveElements(tixiHandle, xpath + "/cutOutProfile", m_cutOutProfiles);

    }

    const CPACSOuterCutOutProfile& CPACSCutOutProfiles::GetOuterCutOutProfile() const
    {
        return m_outerCutOutProfile;
    }

    CPACSOuterCutOutProfile& CPACSCutOutProfiles::GetOuterCutOutProfile()
    {
        return m_outerCutOutProfile;
    }

    const CPACSOuterCutOutProfile& CPACSCutOutProfiles::GetInnerCutOutProfile() const
    {
        return m_innerCutOutProfile;
    }

    CPACSOuterCutOutProfile& CPACSCutOutProfiles::GetInnerCutOutProfile()
    {
        return m_innerCutOutProfile;
    }

    const std::vector<std::unique_ptr<CPACSCutOutProfile>>& CPACSCutOutProfiles::GetCutOutProfiles() const
    {
        return m_cutOutProfiles;
    }

    std::vector<std::unique_ptr<CPACSCutOutProfile>>& CPACSCutOutProfiles::GetCutOutProfiles()
    {
        return m_cutOutProfiles;
    }

    CPACSCutOutProfile& CPACSCutOutProfiles::AddCutOutProfile()
    {
        m_cutOutProfiles.push_back(make_unique<CPACSCutOutProfile>());
        return *m_cutOutProfiles.back();
    }

    void CPACSCutOutProfiles::RemoveCutOutProfile(CPACSCutOutProfile& ref)
    {
        for (std::size_t i = 0; i < m_cutOutProfiles.size(); i++) {
            if (m_cutOutProfiles[i].get() == &ref) {
                m_cutOutProfiles.erase(m_cutOutProfiles.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
