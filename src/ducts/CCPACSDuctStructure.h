/*
* Copyright (C) 2007-2022 German Aerospace Center (DLR/SC)
*
* Created: 2022-03-15 Anton Reiswich <Anton.Reiswich@dlr.de>
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
/**
* @file
* @brief  Implementation of CPACS duct structure handling routines.
*/

#pragma once

#include "generated/CPACSDuctStructure.h"
#include "CTiglRelativelyPositionedComponent.h"
#include "ITiglFuselageDuctStructure.h"

namespace tigl
{

class CCPACSDuctStructure : public generated::CPACSDuctStructure, public ITiglFuselageDuctStructure
{
public:
    TIGL_EXPORT CCPACSDuctStructure(CCPACSDuct* parent, CTiglUIDManager* uidMgr);
};

} //namespace tigl
