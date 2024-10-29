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

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <CCPACSPoint.h>
#include <string>
#include <tixi.h>
#include "CreateIfNotExists.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CTiglUIDObject;

namespace generated
{
    class CPACSDeckElementGeometry;

    // This class is used in:
    // CPACSDeckElementGeometry

    /// @brief Bounding Box
    /// 
    /// 
    class CPACSBoundingBox
    {
    public:
        TIGL_EXPORT CPACSBoundingBox(CPACSDeckElementGeometry* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSBoundingBox();

        TIGL_EXPORT CPACSDeckElementGeometry* GetParent();

        TIGL_EXPORT const CPACSDeckElementGeometry* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const double& GetDeltaX() const;
        TIGL_EXPORT virtual void SetDeltaX(const double& value);

        TIGL_EXPORT virtual const double& GetDeltaY() const;
        TIGL_EXPORT virtual void SetDeltaY(const double& value);

        TIGL_EXPORT virtual const double& GetDeltaZ() const;
        TIGL_EXPORT virtual void SetDeltaZ(const double& value);

        TIGL_EXPORT virtual const boost::optional<CCPACSPoint>& GetOrigin() const;
        TIGL_EXPORT virtual boost::optional<CCPACSPoint>& GetOrigin();

        TIGL_EXPORT virtual CCPACSPoint& GetOrigin(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveOrigin();

    protected:
        CPACSDeckElementGeometry* m_parent;

        CTiglUIDManager* m_uidMgr;

        /// Length in x
        double                       m_deltaX;

        /// Length in y
        double                       m_deltaY;

        /// Length in z
        double                       m_deltaZ;

        /// Origin
        boost::optional<CCPACSPoint> m_origin;

    private:
        CPACSBoundingBox(const CPACSBoundingBox&) = delete;
        CPACSBoundingBox& operator=(const CPACSBoundingBox&) = delete;

        CPACSBoundingBox(CPACSBoundingBox&&) = delete;
        CPACSBoundingBox& operator=(CPACSBoundingBox&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSBoundingBox = generated::CPACSBoundingBox;
using CCPACSDeckElementGeometry = generated::CPACSDeckElementGeometry;
} // namespace tigl
