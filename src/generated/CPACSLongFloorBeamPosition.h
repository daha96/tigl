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
#include <string>
#include <tixi.h>
#include "CPACSAlignmentStructMember.h"
#include "CPACSContinuity.h"
#include "CPACSInterpolation.h"
#include "CreateIfNotExists.h"
#include "CTiglUIDObject.h"
#include "ITiglUIDRefObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSLongFloorBeam;

namespace generated
{
    // This class is used in:
    // CPACSLongFloorBeam

    /// @brief logFloorBeamPositionType
    /// 
    /// longFloorBeamPosition type, containing individual
    /// position definition
    /// 
    class CPACSLongFloorBeamPosition : public CTiglReqUIDObject, public ITiglUIDRefObject
    {
    public:
        TIGL_EXPORT CPACSLongFloorBeamPosition(CCPACSLongFloorBeam* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSLongFloorBeamPosition();

        TIGL_EXPORT CCPACSLongFloorBeam* GetParent();

        TIGL_EXPORT const CCPACSLongFloorBeam* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetStructuralElementUID() const;
        TIGL_EXPORT virtual void SetStructuralElementUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetCrossBeamUID() const;
        TIGL_EXPORT virtual void SetCrossBeamUID(const std::string& value);

        TIGL_EXPORT virtual const double& GetPositionY() const;
        TIGL_EXPORT virtual void SetPositionY(const double& value);

        TIGL_EXPORT virtual const boost::optional<CPACSAlignmentStructMember>& GetAlignment() const;
        TIGL_EXPORT virtual boost::optional<CPACSAlignmentStructMember>& GetAlignment();

        TIGL_EXPORT virtual const boost::optional<CPACSContinuity>& GetContinuity() const;
        TIGL_EXPORT virtual void SetContinuity(const boost::optional<CPACSContinuity>& value);

        TIGL_EXPORT virtual const boost::optional<CPACSInterpolation>& GetInterpolation() const;
        TIGL_EXPORT virtual void SetInterpolation(const boost::optional<CPACSInterpolation>& value);

        TIGL_EXPORT virtual CPACSAlignmentStructMember& GetAlignment(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveAlignment();

    protected:
        CCPACSLongFloorBeam* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string                                 m_uID;

        /// UID of structural element
        std::string                                 m_structuralElementUID;

        /// UID of crossbeam to which the long. beam is
        /// attached
        std::string                                 m_crossBeamUID;

        /// y position of long. beam
        double                                      m_positionY;

        boost::optional<CPACSAlignmentStructMember> m_alignment;

        /// Continuity definition for profile extrusion:
        /// 0= C0 (allows sharp edges, default), 2= C2 (defines curvature
        /// continuity)
        boost::optional<CPACSContinuity>            m_continuity;

        /// Definition of interpolation between different
        /// profiles: 0= no interpolation 1= interpolation of strcutural
        /// profile
        boost::optional<CPACSInterpolation>         m_interpolation;

    private:
        TIGL_EXPORT const CTiglUIDObject* GetNextUIDObject() const final;
        TIGL_EXPORT void NotifyUIDChange(const std::string& oldUid, const std::string& newUid) final;

        CPACSLongFloorBeamPosition(const CPACSLongFloorBeamPosition&) = delete;
        CPACSLongFloorBeamPosition& operator=(const CPACSLongFloorBeamPosition&) = delete;

        CPACSLongFloorBeamPosition(CPACSLongFloorBeamPosition&&) = delete;
        CPACSLongFloorBeamPosition& operator=(CPACSLongFloorBeamPosition&&) = delete;
    };
} // namespace generated

// CPACSLongFloorBeamPosition is customized, use type CCPACSLongFloorBeamPosition directly
} // namespace tigl
