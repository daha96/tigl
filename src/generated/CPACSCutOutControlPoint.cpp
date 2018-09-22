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

#include "CPACSCutOutControlPoint.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSCutOutControlPoint::CPACSCutOutControlPoint()
        : m_relHeight(0)
        , m_xsi(0)
    {
    }

    CPACSCutOutControlPoint::~CPACSCutOutControlPoint()
    {
    }

    void CPACSCutOutControlPoint::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element relHeight
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/relHeight")) {
            m_relHeight = tixi::TixiGetElement<double>(tixiHandle, xpath + "/relHeight");
        }
        else {
            LOG(ERROR) << "Required element relHeight is missing at xpath " << xpath;
        }

        // read element xsi
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/xsi")) {
            m_xsi = tixi::TixiGetElement<double>(tixiHandle, xpath + "/xsi");
        }
        else {
            LOG(ERROR) << "Required element xsi is missing at xpath " << xpath;
        }

    }

    void CPACSCutOutControlPoint::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element relHeight
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/relHeight");
        tixi::TixiSaveElement(tixiHandle, xpath + "/relHeight", m_relHeight);

        // write element xsi
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/xsi");
        tixi::TixiSaveElement(tixiHandle, xpath + "/xsi", m_xsi);

    }

    const double& CPACSCutOutControlPoint::GetRelHeight() const
    {
        return m_relHeight;
    }

    void CPACSCutOutControlPoint::SetRelHeight(const double& value)
    {
        m_relHeight = value;
    }

    const double& CPACSCutOutControlPoint::GetXsi() const
    {
        return m_xsi;
    }

    void CPACSCutOutControlPoint::SetXsi(const double& value)
    {
        m_xsi = value;
    }

} // namespace generated
} // namespace tigl