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
#include <cctype>

#include "CTiglError.h"
#include "to_string.h"

namespace tigl
{
namespace generated
{
    // This enum is used in:
    // CPACSTrackJointCoordinates

    enum CPACSTrackJointCoordinates_name
    {
        P1,
        P2,
        P3,
        P4,
        P5,
        P6,
        P7
    };

    inline std::string CPACSTrackJointCoordinates_nameToString(const CPACSTrackJointCoordinates_name& value)
    {
        switch(value) {
        case P1: return "P1";
        case P2: return "P2";
        case P3: return "P3";
        case P4: return "P4";
        case P5: return "P5";
        case P6: return "P6";
        case P7: return "P7";
        default: throw CTiglError("Invalid enum value \"" + std_to_string(static_cast<int>(value)) + "\" for enum type CPACSTrackJointCoordinates_name");
        }
    }
    inline CPACSTrackJointCoordinates_name stringToCPACSTrackJointCoordinates_name(const std::string& value)
    {
        auto toLower = [](std::string str) { for (char& c : str) { c = std::tolower(c); } return str; };
        if (toLower(value) == "p1") { return P1; }
        if (toLower(value) == "p2") { return P2; }
        if (toLower(value) == "p3") { return P3; }
        if (toLower(value) == "p4") { return P4; }
        if (toLower(value) == "p5") { return P5; }
        if (toLower(value) == "p6") { return P6; }
        if (toLower(value) == "p7") { return P7; }
        throw CTiglError("Invalid string value \"" + value + "\" for enum type CPACSTrackJointCoordinates_name");
    }
} // namespace generated

// Aliases in tigl namespace
using ECPACSTrackJointCoordinates_name = generated::CPACSTrackJointCoordinates_name;
} // namespace tigl
