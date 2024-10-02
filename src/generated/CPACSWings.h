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
#include <typeinfo>
#include <vector>
#include "CTiglError.h"
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
class CTiglUIDManager;
class CTiglUIDObject;
class CCPACSWing;
class CCPACSAircraftModel;
class CCPACSRotorcraftModel;

namespace generated
{
    // This class is used in:
    // CPACSAircraftModel
    // CPACSRotorcraftModel

    /// @brief Wings
    /// 
    /// Wings type, containing all the lifting surfaces (wings,
    /// HTPs, VTPs, canards...) of an aircraft model.
    /// 
    class CPACSWings
    {
    public:
        TIGL_EXPORT CPACSWings(CCPACSAircraftModel* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSWings(CCPACSRotorcraftModel* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSWings();

        template<typename P>
        bool IsParent() const
        {
            return m_parentType != NULL && *m_parentType == typeid(P);
        }

        template<typename P>
        P* GetParent()
        {
            static_assert(std::is_same<P, CCPACSAircraftModel>::value || std::is_same<P, CCPACSRotorcraftModel>::value, "template argument for P is not a parent class of CPACSWings");
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        template<typename P>
        const P* GetParent() const
        {
            static_assert(std::is_same<P, CCPACSAircraftModel>::value || std::is_same<P, CCPACSRotorcraftModel>::value, "template argument for P is not a parent class of CPACSWings");
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<std::unique_ptr<CCPACSWing>>& GetWings() const;
        TIGL_EXPORT virtual std::vector<std::unique_ptr<CCPACSWing>>& GetWings();

        TIGL_EXPORT virtual CCPACSWing& AddWing();
        TIGL_EXPORT virtual void RemoveWing(CCPACSWing& ref);

    protected:
        void* m_parent;
        const std::type_info* m_parentType;

        CTiglUIDManager* m_uidMgr;

        std::vector<std::unique_ptr<CCPACSWing>> m_wings;

    private:
        CPACSWings(const CPACSWings&) = delete;
        CPACSWings& operator=(const CPACSWings&) = delete;

        CPACSWings(CPACSWings&&) = delete;
        CPACSWings& operator=(CPACSWings&&) = delete;
    };
} // namespace generated

// CPACSWings is customized, use type CCPACSWings directly
} // namespace tigl
