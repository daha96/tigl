/*
 * Copyright (C) 2019 CFS Engineering
 *
 * Created: 2018 Malo Drougard <malo.drougard@protonmail.com>
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

#include "test.h" // Brings in the GTest framework
#include "tigl.h"
#include <tixicpp.h>

#include "CCPACSConfigurationManager.h"
#include "CCPACSConfiguration.h"
#include "CCPACSFuselages.h"
#include "CCPACSFuselage.h"
#include "CTiglSectionElement.h"
#include "CCPACSFuselageSectionElement.h"
#include "CCPACSWingSectionElement.h"
#include "CTiglPoint.h"

#include <string.h>

class tiglCTiglSectionElement : public ::testing::Test
{

protected:
    std::string filename = "";

    TiglCPACSConfigurationHandle tiglHandle = -1;
    TixiDocumentHandle tixiHandle           = -1;

    tigl::CCPACSConfigurationManager* manager = nullptr;
    tigl::CCPACSConfiguration* config         = nullptr;

    void setVariables(std::string inFilename)
    {
        unsetVariables();
        filename = inFilename;
        ASSERT_EQ(SUCCESS, tixiOpenDocument(filename.c_str(), &tixiHandle));
        ASSERT_EQ(TIGL_SUCCESS, tiglOpenCPACSConfiguration(tixiHandle, "", &tiglHandle));
        manager  = &(tigl::CCPACSConfigurationManager::GetInstance());
        config   = &(manager->GetConfiguration(tiglHandle));
    }

    void unsetVariables()
    {
        filename = "";

        if (tiglHandle > -1) {
            tiglCloseCPACSConfiguration(tiglHandle);
        }
        if (tixiHandle > -1) {
            tixiCloseDocument(tixiHandle);
        }

        tiglHandle = -1;
        tiglHandle = -1;

        manager  = nullptr;
        config   = nullptr;
    }

    void TearDown()
    {
        unsetVariables();
    }

    tigl::CTiglSectionElement* GetCElementOf(std::string elementUid)
    {
        tigl::CTiglSectionElement* cElement     = nullptr;
        tigl::CTiglUIDManager::TypedPtr typePtr = config->GetUIDManager().ResolveObject(elementUid);
        if (typePtr.type == &typeid(tigl::CCPACSFuselageSectionElement)) {
            tigl::CCPACSFuselageSectionElement& fuselageElement =
                *reinterpret_cast<tigl::CCPACSFuselageSectionElement*>(typePtr.ptr);
            cElement = fuselageElement.GetCTiglSectionElement();
        }
        else if (typePtr.type == &typeid(tigl::CCPACSWingSectionElement)) {
            tigl::CCPACSWingSectionElement& wingElement =
                *reinterpret_cast<tigl::CCPACSWingSectionElement*>(typePtr.ptr);
        }
        return cElement;
    }


    void saveCurrentConfig(std::string outFilename)
    {
        // Save the result in a new file (For visual check purpose)
        // write the change in tixi memory
        config->WriteCPACS(config->GetUID());
        std::string newConfig = tixi::TixiExportDocumentAsString(tixiHandle);
        // Import-export to flat the xml // todo inform tixi developers about this "bug
        TixiDocumentHandle tixiHandle2 = tixi::TixiImportFromString(newConfig);
        newConfig                      = tixi::TixiExportDocumentAsString(tixiHandle2);
        // save the content into the output file
        std::ofstream myfile;
        myfile.open(outFilename, std::ios::trunc);
        myfile << newConfig;
        myfile.close();
        tixiCloseDocument(tixiHandle2);
    }
};

TEST_F(tiglCTiglSectionElement, getOrigin)
{

    tigl::CTiglSectionElement* ctiglElement = nullptr;

    setVariables("TestData/simpletest.cpacs.xml");
    ctiglElement = GetCElementOf("D150_Fuselage_1Section1IDElement1");
    EXPECT_TRUE(tigl::CTiglPoint(-0.5, 0, 0).isNear(ctiglElement->GetOrigin()));

    setVariables("TestData/simpletest-shifftedProfiles.xml");
    ctiglElement = GetCElementOf("D150_Fuselage_1Section2IDElement1");
    EXPECT_TRUE(tigl::CTiglPoint(0.5, 0, 0).isNear(ctiglElement->GetOrigin()));
    EXPECT_TRUE(tigl::CTiglPoint(0.5, 0, 0).isNear(ctiglElement->GetOrigin(FUSELAGE_COORDINATE_SYSTEM)));
}

TEST_F(tiglCTiglSectionElement, getCenter)
{

    tigl::CTiglSectionElement* ctiglElement = nullptr;

    setVariables("TestData/simpletest.cpacs.xml");
    ctiglElement = GetCElementOf("D150_Fuselage_1Section1IDElement1");
    EXPECT_TRUE(tigl::CTiglPoint(-0.5, 0, 0).isNear(ctiglElement->GetCenter()));

    setVariables("TestData/simpletest-shifftedProfiles.xml");
    ctiglElement = GetCElementOf("D150_Fuselage_1Section2IDElement1");
    EXPECT_TRUE(tigl::CTiglPoint(0.5, 0.5, 0).isNear(ctiglElement->GetCenter()));
    EXPECT_TRUE(tigl::CTiglPoint(0.5, 1, 0).isNear(ctiglElement->GetCenter(FUSELAGE_COORDINATE_SYSTEM)));
}

TEST_F(tiglCTiglSectionElement, getCircumference)
{

    tigl::CTiglSectionElement* ctiglElement = nullptr;

    setVariables("TestData/simpletest.cpacs.xml");
    ctiglElement = GetCElementOf("D150_Fuselage_1Section1IDElement1");
    EXPECT_NEAR(M_PI * 2 * 0.5, ctiglElement->GetCircumference(), 0.1);
    EXPECT_NEAR(M_PI * 2, ctiglElement->GetCircumference(FUSELAGE_COORDINATE_SYSTEM), 0.1);

    setVariables("TestData/simpletest-shifftedProfiles.xml");
    ctiglElement = GetCElementOf("D150_Fuselage_1Section2IDElement1");
    EXPECT_NEAR(M_PI * 2 * 0.5, ctiglElement->GetCircumference(), 0.1);
    EXPECT_NEAR(M_PI * 2, ctiglElement->GetCircumference(FUSELAGE_COORDINATE_SYSTEM), 0.1);
}

TEST_F(tiglCTiglSectionElement, setOrigin)
{

    tigl::CTiglSectionElement* ctiglElement = nullptr;
    tigl::CTiglPoint newOrigin;
    tigl::CCPACSFuselageSectionElement* element = nullptr;

    setVariables("TestData/simpletest.cpacs.xml");
    ctiglElement = GetCElementOf("D150_Fuselage_1Section1IDElement1");
    element      = &(
        config->GetUIDManager().ResolveObject<tigl::CCPACSFuselageSectionElement>("D150_Fuselage_1Section1IDElement1"));

    newOrigin = tigl::CTiglPoint(2, 1.1, 0.13);
    ctiglElement->SetOrigin(newOrigin);
    EXPECT_TRUE(newOrigin.isNear(ctiglElement->GetOrigin()));

    newOrigin = tigl::CTiglPoint(-3, 1, 2);
    ctiglElement->SetOrigin(newOrigin);
    EXPECT_TRUE(newOrigin.isNear(ctiglElement->GetOrigin()));
    // check the value of the element transformation
    // remark that to compute the element translation we must take in account the position and the scaling that affect this transformation
    tigl::CTiglPoint elementTranslation = element->GetTranslation();
    ;
    EXPECT_TRUE(tigl::CTiglPoint(-2.5, 2, 4).isNear(elementTranslation));

    newOrigin = tigl::CTiglPoint(-3, 1, 2);
    ctiglElement->SetOrigin(newOrigin, FUSELAGE_COORDINATE_SYSTEM);
    EXPECT_TRUE(newOrigin.isNear(ctiglElement->GetOrigin(FUSELAGE_COORDINATE_SYSTEM)));
    EXPECT_TRUE(tigl::CTiglPoint(-3, 0.5, 1).isNear(ctiglElement->GetOrigin()));

    newOrigin = tigl::CTiglPoint(-3, 1, 2);
    ctiglElement->SetOrigin(newOrigin, FUSELAGE_COORDINATE_SYSTEM);
    EXPECT_TRUE(newOrigin.isNear(ctiglElement->GetOrigin(FUSELAGE_COORDINATE_SYSTEM)));
    EXPECT_TRUE(tigl::CTiglPoint(-3, 0.5, 1).isNear(ctiglElement->GetOrigin()));

    // save the file for visual check
    saveCurrentConfig("TestData/Output/simpletest-out.xml");

    setVariables("TestData/simpletest-shifftedProfiles.xml");
    ctiglElement = GetCElementOf("D150_Fuselage_1Section2IDElement1");
    element      = &(
        config->GetUIDManager().ResolveObject<tigl::CCPACSFuselageSectionElement>("D150_Fuselage_1Section2IDElement1"));

    newOrigin = tigl::CTiglPoint(0, 2, 2);
    ctiglElement->SetOrigin(newOrigin);
    EXPECT_TRUE(newOrigin.isNear(ctiglElement->GetOrigin()));
    elementTranslation = element->GetTranslation();
    EXPECT_TRUE(tigl::CTiglPoint(-0.5, 4, 4).isNear(elementTranslation));

    saveCurrentConfig("TestData/Output/simpletest-shifftedProfiles-out.xml");
}

TEST_F(tiglCTiglSectionElement, setCenter)
{

    tigl::CTiglSectionElement* ctiglElement = nullptr;
    tigl::CTiglPoint newCenter;
    tigl::CCPACSFuselageSectionElement* element = nullptr;

    setVariables("TestData/simpletest.cpacs.xml");
    ctiglElement = GetCElementOf("D150_Fuselage_1Section1IDElement1");

    newCenter = tigl::CTiglPoint(-5, 1, 2);
    ctiglElement->SetCenter(newCenter, FUSELAGE_COORDINATE_SYSTEM);
    EXPECT_TRUE(newCenter.isNear(ctiglElement->GetCenter(FUSELAGE_COORDINATE_SYSTEM)));
    EXPECT_TRUE(tigl::CTiglPoint(-5, 0.5, 1).isNear(ctiglElement->GetCenter()));

    // save the file for visual check
    saveCurrentConfig("TestData/Output/simpletest-out.xml");

    setVariables("TestData/simpletest-shifftedProfiles.xml");
    ctiglElement = GetCElementOf("D150_Fuselage_1Section2IDElement1");
    element      = &(
        config->GetUIDManager().ResolveObject<tigl::CCPACSFuselageSectionElement>("D150_Fuselage_1Section2IDElement1"));

    newCenter = tigl::CTiglPoint(1, 0, 1);
    ctiglElement->SetCenter(newCenter, FUSELAGE_COORDINATE_SYSTEM);
    EXPECT_TRUE(newCenter.isNear(ctiglElement->GetCenter(FUSELAGE_COORDINATE_SYSTEM)));
    EXPECT_TRUE(tigl::CTiglPoint(1, 0, 0.5).isNear(ctiglElement->GetCenter()));
    tigl::CTiglPoint elementTranslation = element->GetTranslation();
    EXPECT_TRUE(tigl::CTiglPoint(0.5, -1, 1).isNear(elementTranslation));

    newCenter = tigl::CTiglPoint(0.5, 0, 0);
    ctiglElement->SetCenter(newCenter);
    EXPECT_TRUE(newCenter.isNear(ctiglElement->GetCenter()));

    // save the file for visual check
    saveCurrentConfig("TestData/Output/simpletest-shifftedProfiles-out.xml");
}

TEST_F(tiglCTiglSectionElement, getProfileArea_MultipleFuselagesModel)
{

    setVariables("TestData/multiple_fuselages.xml");

    tigl::CTiglSectionElement* cElement = nullptr;
    double area                         = -1;

    cElement = GetCElementOf("D150_Fuselage_CSection1IDElement1");
    area     = cElement->GetArea();
    EXPECT_NEAR(area, 1 * M_PI, 0.5);

    cElement = GetCElementOf("D150_Fuselage_CSection2IDElement1");
    area     = cElement->GetArea();
    EXPECT_NEAR(area, 28, 5);

    cElement = GetCElementOf("D150_Fuselage_CSection3IDElement1");
    area     = cElement->GetArea();
    EXPECT_NEAR(area, 0.8, 0.5);
}

TEST_F(tiglCTiglSectionElement, getNormal_MultipleFuselagesModel)
{

    setVariables("TestData/multiple_fuselages.xml");

    tigl::CTiglSectionElement* cElement = nullptr;
    tigl::CTiglPoint n, expectedN;

    cElement  = GetCElementOf("D150_Fuselage_CSection1IDElement1");
    n         = cElement->GetNormal();
    expectedN = tigl::CTiglPoint(1, 0, 0);
    EXPECT_TRUE(n.isNear(expectedN));

    n = cElement->GetNormal(TiglCoordinateSystem::FUSELAGE_COORDINATE_SYSTEM);
    EXPECT_TRUE(n.isNear(expectedN));

    cElement  = GetCElementOf("D150_Fuselage_CSection2IDElement1");
    n         = cElement->GetNormal();
    expectedN = tigl::CTiglPoint(0.925, 0.342, -0.163);
    EXPECT_TRUE(n.isNear(expectedN, 0.001));

    cElement  = GetCElementOf("D150_Fuselage_CSection3IDElement1");
    n         = cElement->GetNormal();
    expectedN = tigl::CTiglPoint(1, 0, 0);
    EXPECT_TRUE(n.isNear(expectedN));

    // simple fuselage 2 !

    cElement  = GetCElementOf("D150_Fuselage_2Section1IDElement1");
    n         = cElement->GetNormal();
    expectedN = tigl::CTiglPoint(1, 0, 0);
    EXPECT_TRUE(n.isNear(expectedN));

    n         = cElement->GetNormal(TiglCoordinateSystem::FUSELAGE_COORDINATE_SYSTEM);
    expectedN = tigl::CTiglPoint(1, 0, 0);
    EXPECT_TRUE(n.isNear(expectedN));

    // simple fuselage 3 !

    cElement  = GetCElementOf("D150_Fuselage_3Section1IDElement1");
    n         = cElement->GetNormal();
    expectedN = tigl::CTiglPoint(0.766, 0.642, 0);
    EXPECT_TRUE(n.isNear(expectedN));

    n         = cElement->GetNormal(TiglCoordinateSystem::FUSELAGE_COORDINATE_SYSTEM);
    expectedN = tigl::CTiglPoint(1, 0, 0);
    EXPECT_TRUE(n.isNear(expectedN));

    // simple fuselage 4 !

    cElement  = GetCElementOf("D150_Fuselage_4Section1IDElement1");
    n         = cElement->GetNormal();
    expectedN = tigl::CTiglPoint(0.766, 0.642, 0);
    EXPECT_TRUE(n.isNear(expectedN));

    n         = cElement->GetNormal(TiglCoordinateSystem::FUSELAGE_COORDINATE_SYSTEM);
    expectedN = tigl::CTiglPoint(1, 0, 0);
    EXPECT_TRUE(n.isNear(expectedN));
}

TEST_F(tiglCTiglSectionElement, getProfileHeight_MultipleFuselagesModel)
{

    setVariables("TestData/multiple_fuselages.xml");

    tigl::CTiglSectionElement* cElement = nullptr;
    double height                       = -1;

    cElement = GetCElementOf("D150_Fuselage_CSection1IDElement1");
    height   = cElement->GetHeight();
    EXPECT_NEAR(height, 2, 0.1);

    cElement = GetCElementOf("D150_Fuselage_CSection2IDElement1");
    height   = cElement->GetHeight();
    EXPECT_NEAR(height, 4, 0.2);

    cElement = GetCElementOf("D150_Fuselage_CSection3IDElement1");
    height   = cElement->GetHeight();
    EXPECT_NEAR(height, 1, 0.2);
}

TEST_F(tiglCTiglSectionElement, getProfileWidth_MultipleFuselagesModel)
{

    setVariables("TestData/multiple_fuselages.xml");

    tigl::CTiglSectionElement* cElement = nullptr;
    double height                       = -1;

    cElement = GetCElementOf("D150_Fuselage_CSection1IDElement1");
    height   = cElement->GetWidth();
    EXPECT_NEAR(height, 2, 0.1);

    cElement = GetCElementOf("D150_Fuselage_CSection2IDElement1");
    height   = cElement->GetWidth();
    EXPECT_NEAR(height, 8, 0.2);

    cElement = GetCElementOf("D150_Fuselage_CSection3IDElement1");
    height   = cElement->GetWidth();
    EXPECT_NEAR(height, 1, 0.2);
}


