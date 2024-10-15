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
#include <typeinfo>
#include "CPACSBoundingBox.h"
#include "CPACSGenericGeometryComponent.h"
#include "CreateIfNotExists.h"
#include "CTiglError.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CTiglUIDObject;

namespace generated
{
    class CPACSDeckElementBase;
    class CPACSGalleyElement;
    class CPACSSeatElement;

    // This class is used in:
    // CPACSDeckElementBase
    // CPACSGalleyElement
    // CPACSSeatElement

    /// @brief Geometry
    /// 
    /// Description of the deck element geometry. This might be either a bounding box definition or a link to a generic geometry component.
    /// 
    class CPACSDeckElementGeometry
    {
    public:
        TIGL_EXPORT CPACSDeckElementGeometry(CPACSDeckElementBase* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSDeckElementGeometry(CPACSGalleyElement* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSDeckElementGeometry(CPACSSeatElement* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSDeckElementGeometry();

        template<typename P>
        bool IsParent() const
        {
            return m_parentType != NULL && *m_parentType == typeid(P);
        }

        template<typename P>
        P* GetParent()
        {
            static_assert(std::is_same<P, CPACSDeckElementBase>::value || std::is_same<P, CPACSGalleyElement>::value || std::is_same<P, CPACSSeatElement>::value, "template argument for P is not a parent class of CPACSDeckElementGeometry");
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        template<typename P>
        const P* GetParent() const
        {
            static_assert(std::is_same<P, CPACSDeckElementBase>::value || std::is_same<P, CPACSGalleyElement>::value || std::is_same<P, CPACSSeatElement>::value, "template argument for P is not a parent class of CPACSDeckElementGeometry");
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

        TIGL_EXPORT bool ValidateChoices() const;

        TIGL_EXPORT virtual const boost::optional<CPACSGenericGeometryComponent>& GetGenericGeometryComponent_choice1() const;
        TIGL_EXPORT virtual boost::optional<CPACSGenericGeometryComponent>& GetGenericGeometryComponent_choice1();

        TIGL_EXPORT virtual const boost::optional<CPACSBoundingBox>& GetBoundingBox_choice2() const;
        TIGL_EXPORT virtual boost::optional<CPACSBoundingBox>& GetBoundingBox_choice2();

        TIGL_EXPORT virtual CPACSGenericGeometryComponent& GetGenericGeometryComponent_choice1(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveGenericGeometryComponent_choice1();

        TIGL_EXPORT virtual CPACSBoundingBox& GetBoundingBox_choice2(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveBoundingBox_choice2();

    protected:
        void* m_parent;
        const std::type_info* m_parentType;

        CTiglUIDManager* m_uidMgr;

        boost::optional<CPACSGenericGeometryComponent> m_genericGeometryComponent_choice1;
        boost::optional<CPACSBoundingBox>              m_boundingBox_choice2;

    private:
        CPACSDeckElementGeometry(const CPACSDeckElementGeometry&) = delete;
        CPACSDeckElementGeometry& operator=(const CPACSDeckElementGeometry&) = delete;

        CPACSDeckElementGeometry(CPACSDeckElementGeometry&&) = delete;
        CPACSDeckElementGeometry& operator=(CPACSDeckElementGeometry&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSDeckElementGeometry = generated::CPACSDeckElementGeometry;
using CCPACSDeckElementBase = generated::CPACSDeckElementBase;
using CCPACSGalleyElement = generated::CPACSGalleyElement;
using CCPACSSeatElement = generated::CPACSSeatElement;
} // namespace tigl
