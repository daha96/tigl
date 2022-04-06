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
#include <CCPACSTransformation.h>
#include <string>
#include <tixi.h>
#include <vector>
#include "CPACSUIDSequence.h"
#include "CreateIfNotExists.h"
#include "CTiglUIDObject.h"
#include "ITiglUIDRefObject.h"
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSDuct;
class CCPACSDucts;

namespace generated
{
    // This class is used in:
    // CPACSDucts

    /// @brief Duct assembly
    /// 
    /// 
    class CPACSDuctAssembly : public CTiglReqUIDObject, public ITiglUIDRefObject
    {
    public:
        TIGL_EXPORT CPACSDuctAssembly(CCPACSDucts* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSDuctAssembly();

        TIGL_EXPORT CCPACSDucts* GetParent();

        TIGL_EXPORT const CCPACSDucts* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

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

        TIGL_EXPORT virtual const boost::optional<std::string>& GetParentUID() const;
        TIGL_EXPORT virtual void SetParentUID(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<CCPACSTransformation>& GetTransformation() const;
        TIGL_EXPORT virtual boost::optional<CCPACSTransformation>& GetTransformation();

        TIGL_EXPORT virtual const boost::optional<CPACSUIDSequence>& GetExcludeObjectUIDs() const;
        TIGL_EXPORT virtual boost::optional<CPACSUIDSequence>& GetExcludeObjectUIDs();

        TIGL_EXPORT virtual const std::vector<std::unique_ptr<CCPACSDuct>>& GetDucts() const;
        TIGL_EXPORT virtual std::vector<std::unique_ptr<CCPACSDuct>>& GetDucts();

        TIGL_EXPORT virtual CCPACSTransformation& GetTransformation(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveTransformation();

        TIGL_EXPORT virtual CPACSUIDSequence& GetExcludeObjectUIDs(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveExcludeObjectUIDs();

        TIGL_EXPORT virtual CCPACSDuct& AddDuct();
        TIGL_EXPORT virtual void RemoveDuct(CCPACSDuct& ref);

    protected:
        CCPACSDucts* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string                              m_uID;

        /// Name
        std::string                              m_name;

        /// Description
        boost::optional<std::string>             m_description;

        /// UID of part to which the duct is
        /// mounted (if any)
        boost::optional<std::string>             m_parentUID;

        boost::optional<CCPACSTransformation>    m_transformation;

        boost::optional<CPACSUIDSequence>        m_excludeObjectUIDs;

        std::vector<std::unique_ptr<CCPACSDuct>> m_ducts;

    private:
        TIGL_EXPORT const CTiglUIDObject* GetNextUIDObject() const final;
        TIGL_EXPORT void NotifyUIDChange(const std::string& oldUid, const std::string& newUid) final;

        CPACSDuctAssembly(const CPACSDuctAssembly&) = delete;
        CPACSDuctAssembly& operator=(const CPACSDuctAssembly&) = delete;

        CPACSDuctAssembly(CPACSDuctAssembly&&) = delete;
        CPACSDuctAssembly& operator=(CPACSDuctAssembly&&) = delete;
    };
} // namespace generated

// CPACSDuctAssembly is customized, use type CCPACSDuctAssembly directly
} // namespace tigl
