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

#pragma once

#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
class CCPACSNacelleGuideCurves;

namespace generated
{
    // This class is used in:
    // CPACSNacelleGuideCurves

    // generated from /xsd:schema/xsd:complexType[681]
    class CPACSNacelleGuideCurve
    {
    public:
        TIGL_EXPORT CPACSNacelleGuideCurve(CCPACSNacelleGuideCurves* parent);

        TIGL_EXPORT virtual ~CPACSNacelleGuideCurve();

        TIGL_EXPORT CCPACSNacelleGuideCurves* GetParent();

        TIGL_EXPORT const CCPACSNacelleGuideCurves* GetParent() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetName() const;
        TIGL_EXPORT virtual void SetName(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetDescription() const;
        TIGL_EXPORT virtual void SetDescription(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetGuideCurveProfileUID() const;
        TIGL_EXPORT virtual void SetGuideCurveProfileUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetStartSectionUID() const;
        TIGL_EXPORT virtual void SetStartSectionUID(const std::string& value);

        TIGL_EXPORT virtual const double& GetFromZeta() const;
        TIGL_EXPORT virtual void SetFromZeta(const double& value);

        TIGL_EXPORT virtual const double& GetToZeta() const;
        TIGL_EXPORT virtual void SetToZeta(const double& value);

    protected:
        CCPACSNacelleGuideCurves* m_parent;

        std::string m_name;
        std::string m_description;
        std::string m_guideCurveProfileUID;
        std::string m_startSectionUID;
        double      m_fromZeta;
        double      m_toZeta;

    private:
#ifdef HAVE_CPP11
        CPACSNacelleGuideCurve(const CPACSNacelleGuideCurve&) = delete;
        CPACSNacelleGuideCurve& operator=(const CPACSNacelleGuideCurve&) = delete;

        CPACSNacelleGuideCurve(CPACSNacelleGuideCurve&&) = delete;
        CPACSNacelleGuideCurve& operator=(CPACSNacelleGuideCurve&&) = delete;
#else
        CPACSNacelleGuideCurve(const CPACSNacelleGuideCurve&);
        CPACSNacelleGuideCurve& operator=(const CPACSNacelleGuideCurve&);
#endif
    };
} // namespace generated

// Aliases in tigl namespace
#ifdef HAVE_CPP11
using CCPACSNacelleGuideCurve = generated::CPACSNacelleGuideCurve;
#else
typedef generated::CPACSNacelleGuideCurve CCPACSNacelleGuideCurve;
#endif
} // namespace tigl