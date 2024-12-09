/*
* Copyright (c) 2018 RISC Software GmbH
*
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

#include "CCPACSSkinSegments.h"

#include "CTiglUIDManager.h"

namespace tigl
{
CCPACSSkinSegments::CCPACSSkinSegments(CCPACSSkin* parent, CTiglUIDManager* uidMgr)
    : generated::CPACSSkin(parent, uidMgr)
{
}



/*void CCPACSSkinSegments::Invalidate(const boost::optional<std::string>& source) const
{
    for (auto& s : m_sparSegments) {
        s->Invalidate(source);
    }
}*/

int CCPACSSkinSegments::GetSkinSegmentCount() const
{
    return static_cast<int>(m_skinSegments.size());
}

CCPACSSkinSegment& CCPACSSkinSegments::GetSkinSegment(int index) const
{
    const int idx = index - 1;
    if (idx < 0 || idx >= GetSkinSegmentCount()) {
        LOG(ERROR) << "Invalid index value";
        throw CTiglError("Invalid index value in CCPACSSkinSegments::GetSkinSegment", TIGL_INDEX_ERROR);
    }
    return (*(m_skinSegments[idx]));
}

CCPACSSkinSegment& CCPACSSkinSegments::GetSkinSegment(const std::string& uid) const
{
    for (auto& s : m_skinSegments) {
        if (s->GetUID() == uid) {
            return *s;
        }
    }
    const std::string& referenceUID = CTiglWingStructureReference(*GetParent()->GetParent()).GetUID();
    LOG(ERROR) << "Spar Segment \"" << uid << "\" not found in component segment or trailing edge device with UID \"" << referenceUID << "\"";
    throw CTiglError("Spar Segment \"" + uid + "\" not found in component segment or trailing edge device with UID \"" + referenceUID + "\". Please check the CPACS document!", TIGL_ERROR);
}

} // namespace tigl
