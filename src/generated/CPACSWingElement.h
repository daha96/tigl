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

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <CCPACSTransformation.h>
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSWingSectionElements;

namespace generated
{
    // This class is used in:
    // CPACSWingElements

    // generated from /xsd:schema/xsd:complexType[944]
    /// @brief Element of the section.
    /// 
    /// Within elements the airfoils of the wing are defined.
    /// Each section can have one or more elements. Within each element
    /// one airfoil have to be defined. If e.g. the wing should have a
    /// step at this section, two elements can be defined for the two
    /// airfoils.
    /// Mathematically spoken a element is a coordinate system
    /// that is translated, rotated and scaled relative to the section
    /// coordinate system. This transformation parameters are defined
    /// withing the transformation section. The wirfoil, which is linked
    /// by using the parameter airfoilUID is directly 'copied' in the
    /// element coordinate system. If e.g. the airfoil is defined from 0
    /// to 1 in x-direction and the total scaling of the elements x-axis
    /// equals 3.5 the wing chord is 3.5 m long.
    /// An example for wing element can be found in the
    /// picture below:
    /// @see wingelements
    /// 
    class CPACSWingElement
    {
    public:
        TIGL_EXPORT CPACSWingElement(CCPACSWingSectionElements* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSWingElement();

        TIGL_EXPORT CCPACSWingSectionElements* GetParent();

        TIGL_EXPORT const CCPACSWingSectionElements* GetParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetName() const;
        TIGL_EXPORT virtual void SetName(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
        TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const std::string& GetAirfoilUID() const;
        TIGL_EXPORT virtual void SetAirfoilUID(const std::string& value);

        TIGL_EXPORT virtual const CCPACSTransformation& GetTransformation() const;
        TIGL_EXPORT virtual CCPACSTransformation& GetTransformation();

    protected:
        CCPACSWingSectionElements* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string                  m_uID;

        /// Name of the wing element.
        std::string                  m_name;

        /// Description of the wing element.
        boost::optional<std::string> m_description;

        /// Reference to a wing airfoil.
        std::string                  m_airfoilUID;

        CCPACSTransformation         m_transformation;

    private:
        CPACSWingElement(const CPACSWingElement&) = delete;
        CPACSWingElement& operator=(const CPACSWingElement&) = delete;

        CPACSWingElement(CPACSWingElement&&) = delete;
        CPACSWingElement& operator=(CPACSWingElement&&) = delete;
    };
} // namespace generated

// CPACSWingElement is customized, use type CCPACSWingSectionElement directly
} // namespace tigl
