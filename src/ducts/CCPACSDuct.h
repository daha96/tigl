/*
* Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
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
* @brief  Implementation of CPACS duct handling routines.
*/

#pragma once

#include "generated/CPACSDuct.h"
#include "CTiglRelativelyPositionedComponent.h"
#include "CCPACSConfiguration.h"

namespace tigl
{

class CCPACSDuct : public generated::CPACSDuct, public CTiglRelativelyPositionedComponent
{
public:

    TIGL_EXPORT CCPACSDuct(CCPACSDucts* parent, CTiglUIDManager* uidMgr);

    TIGL_EXPORT CCPACSConfiguration& GetConfiguration() const;

    TIGL_EXPORT std::string GetDefaultedUID() const override;
    // Returns the Component Type TIGL_COMPONENT_DUCT
    TIGL_EXPORT TiglGeometricComponentType GetComponentType() const override;
    TIGL_EXPORT TiglGeometricComponentIntent GetComponentIntent() const override;

protected:
    PNamedShape BuildLoft() const override;
};

}
