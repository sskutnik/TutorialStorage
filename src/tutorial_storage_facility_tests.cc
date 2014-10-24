#include <gtest/gtest.h>

#include "tutorial_storage_facility.h"

#include "agent_tests.h"
#include "context.h"
#include "facility_tests.h"

using tutorial_storage::Tutorial_storageFacility;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
class Tutorial_storageFacilityTest : public ::testing::Test {
 protected:
  cyclus::TestContext tc_;
  Tutorial_storageFacility* src_facility_;

  virtual void SetUp() {
    src_facility_ = new Tutorial_storageFacility(tc_.get());
  }

  virtual void TearDown() {}
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(Tutorial_storageFacilityTest, clone) {
  Tutorial_storageFacility* cloned_fac =
      dynamic_cast<Tutorial_storageFacility*> (src_facility_->Clone());
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(Tutorial_storageFacilityTest, InitialState) {
  // Test things about the initial state of the facility here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(Tutorial_storageFacilityTest, Print) {
  EXPECT_NO_THROW(std::string s = src_facility_->str());
  // Test Tutorial_storageFacility specific aspects of the print method here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(Tutorial_storageFacilityTest, Tick) {
  ASSERT_NO_THROW(src_facility_->Tick());
  // Test Tutorial_storageFacility specific behaviors of the Tick function here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(Tutorial_storageFacilityTest, Tock) {
  EXPECT_NO_THROW(src_facility_->Tock());
  // Test Tutorial_storageFacility specific behaviors of the Tock function here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
cyclus::Agent* Tutorial_storageFacilityConstructor(cyclus::Context* ctx) {
  return new Tutorial_storageFacility(ctx);
}

// Required to get functionality in cyclus agent unit tests library
#ifndef CYCLUS_AGENT_TESTS_CONNECTED
int ConnectAgentTests();
static int cyclus_agent_tests_connected = ConnectAgentTests();
#define CYCLUS_AGENT_TESTS_CONNECTED cyclus_agent_tests_connected
#endif  // CYCLUS_AGENT_TESTS_CONNECTED

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
INSTANTIATE_TEST_CASE_P(Tutorial_storageFac, FacilityTests,
                        ::testing::Values(&Tutorial_storageFacilityConstructor));

INSTANTIATE_TEST_CASE_P(Tutorial_storageFac, AgentTests,
                        ::testing::Values(&Tutorial_storageFacilityConstructor));
