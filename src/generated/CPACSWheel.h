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

#pragma once

#include <string>
#include <tixi.h>
#include "CTiglUIDObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;

namespace generated
{
    class CPACSAxle;

    // This class is used in:
    // CPACSAxle

    /// @brief Definition of the landing gear wheel.
    /// 
    /// The center plane of the wheel is located on the end point of the axle.
    /// 
    class CPACSWheel : public CTiglReqUIDObject
    {
    public:
        TIGL_EXPORT CPACSWheel(CPACSAxle* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSWheel();

        TIGL_EXPORT CPACSAxle* GetParent();

        TIGL_EXPORT const CPACSAxle* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const double& GetRadius() const;
        TIGL_EXPORT virtual void SetRadius(const double& value);

        TIGL_EXPORT virtual const double& GetWidth() const;
        TIGL_EXPORT virtual void SetWidth(const double& value);

        TIGL_EXPORT virtual const bool& GetBraked() const;
        TIGL_EXPORT virtual void SetBraked(const bool& value);

    protected:
        CPACSAxle* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string m_uID;

        /// Wheel radius
        double      m_radius;

        /// With of the wheel
        double      m_width;

        /// Brake: false =
        /// not braked; true = braked.
        bool        m_braked;

    private:
        CPACSWheel(const CPACSWheel&) = delete;
        CPACSWheel& operator=(const CPACSWheel&) = delete;

        CPACSWheel(CPACSWheel&&) = delete;
        CPACSWheel& operator=(CPACSWheel&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSWheel = generated::CPACSWheel;
using CCPACSAxle = generated::CPACSAxle;
} // namespace tigl
