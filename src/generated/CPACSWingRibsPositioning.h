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
#include <CCPACSWingRibRotation.h>
#include <string>
#include <tixi.h>
#include "CPACSRibCrossingBehaviour.h"
#include "tigl_internal.h"

namespace tigl
{
class CCPACSWingRibsDefinition;

namespace generated
{
    // This class is used in:
    // CPACSWingRibsDefinition

    // generated from /xsd:schema/xsd:complexType[968]
    /// @brief wingRibsPositioningType
    /// 
    /// Within the ribsPositioing type the position and the
    /// orientaion of the ribs of the rib set are difend.
    /// The positions of the ribs are defined by placing the
    /// ribs on a reference line on the wing (ribReference). The inner
    /// and the outer beginning of the rib set is defined using etaStart
    /// and etaEnd. The position of the forward and rear end of the ribs
    /// is defiend by ribStart and ribEnd. The orientation of the ribs
    /// is defined in ribRotaton. The number of ribs of the current rib
    /// set is either defined by ribNumber or by spacing.
    /// Three examples how ribs can be placed on the wing can
    /// be found in the picture below. For more detailed information,
    /// pleas refer to the descripion of each parameter.
    /// @see ribs
    /// 
    class CPACSWingRibsPositioning
    {
    public:
        TIGL_EXPORT CPACSWingRibsPositioning(CCPACSWingRibsDefinition* parent);

        TIGL_EXPORT virtual ~CPACSWingRibsPositioning();

        TIGL_EXPORT CCPACSWingRibsDefinition* GetParent();

        TIGL_EXPORT const CCPACSWingRibsDefinition* GetParent() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT bool ValidateChoices() const;

        TIGL_EXPORT virtual const std::string& GetRibReference() const;
        TIGL_EXPORT virtual void SetRibReference(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetEtaStart_choice1() const;
        TIGL_EXPORT virtual void SetEtaStart_choice1(const boost::optional<double>& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetElementStartUID_choice2() const;
        TIGL_EXPORT virtual void SetElementStartUID_choice2(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetSparPositionStartUID_choice3() const;
        TIGL_EXPORT virtual void SetSparPositionStartUID_choice3(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetEtaEnd_choice1() const;
        TIGL_EXPORT virtual void SetEtaEnd_choice1(const boost::optional<double>& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetElementEndUID_choice2() const;
        TIGL_EXPORT virtual void SetElementEndUID_choice2(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetSparPositionEndUID_choice3() const;
        TIGL_EXPORT virtual void SetSparPositionEndUID_choice3(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const std::string& GetRibStart() const;
        TIGL_EXPORT virtual void SetRibStart(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetRibEnd() const;
        TIGL_EXPORT virtual void SetRibEnd(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetSpacing_choice1() const;
        TIGL_EXPORT virtual void SetSpacing_choice1(const boost::optional<double>& value);

        TIGL_EXPORT virtual const boost::optional<int>& GetNumberOfRibs_choice2() const;
        TIGL_EXPORT virtual void SetNumberOfRibs_choice2(const boost::optional<int>& value);

        TIGL_EXPORT virtual const CPACSRibCrossingBehaviour& GetRibCrossingBehaviour() const;
        TIGL_EXPORT virtual void SetRibCrossingBehaviour(const CPACSRibCrossingBehaviour& value);

        TIGL_EXPORT virtual const CCPACSWingRibRotation& GetRibRotation() const;
        TIGL_EXPORT virtual CCPACSWingRibRotation& GetRibRotation();

    protected:
        CCPACSWingRibsDefinition* m_parent;

        /// The ribReference is the reference line for the geometrical rib
        /// placement. It can either
        /// be a sparUID or "trailingEdge" or "leadingEdge"
        std::string                  m_ribReference;

        /// EtaStart defines the innerBorder location of the beginning of the rib
        /// set on the
        /// ribReference line. Please note, the eta is relative to wing eta coordinate!
        boost::optional<double>      m_etaStart_choice1;

        /// elementStartUID defines the innerBorder location of the beginning of the rib
        /// set on the
        /// ribReference line. It is relative to a section element and hence linked to
        /// the outer shape.
        boost::optional<std::string> m_elementStartUID_choice2;

        /// TIGL extension
        boost::optional<std::string> m_sparPositionStartUID_choice3;

        /// EtaEnd defines the outerBorder location of the end of the rib set on
        /// the
        /// ribReference line. Please note, the eta is relative to wing eta coordinate!
        boost::optional<double>      m_etaEnd_choice1;

        /// elementEndUID defines the innerBorder location of the beginning of the rib
        /// set on the
        /// ribReference line. It is relative to a section element and hence linked to
        /// the outer shape.
        boost::optional<std::string> m_elementEndUID_choice2;

        /// TIGL extension
        boost::optional<std::string> m_sparPositionEndUID_choice3;

        /// RibStart defines the forward beginning of the ribs. It can either be a
        /// sparUID or
        /// "trailingEdge" or "leadingEdge".
        std::string                  m_ribStart;

        /// RibEnd defines the backward ending of the ribs. It can either be a
        /// sparUID or
        /// "trailingEdge" or "leadingEdge".
        std::string                  m_ribEnd;

        /// The spacing of the ribs defines the distance between two ribs,
        /// measured on the
        /// ribReferenceLine. First rib is placed at etaStart.
        boost::optional<double>      m_spacing_choice1;

        /// RibNumber defines the number of ribs in this ribSet. First rib is at
        /// etaStart on the
        /// referenceLine, last rib is at etaEnd. The spacing is constant on the
        /// ribReferenceLine.
        boost::optional<int>         m_numberOfRibs_choice2;

        CPACSRibCrossingBehaviour    m_ribCrossingBehaviour;

        CCPACSWingRibRotation        m_ribRotation;

    private:
        CPACSWingRibsPositioning(const CPACSWingRibsPositioning&) = delete;
        CPACSWingRibsPositioning& operator=(const CPACSWingRibsPositioning&) = delete;

        CPACSWingRibsPositioning(CPACSWingRibsPositioning&&) = delete;
        CPACSWingRibsPositioning& operator=(CPACSWingRibsPositioning&&) = delete;
    };
} // namespace generated

// CPACSWingRibsPositioning is customized, use type CCPACSWingRibsPositioning directly
} // namespace tigl
