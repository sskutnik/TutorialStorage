#include <gtest/gtest.h>

#include "tutorial_storage_region.h"

#include "agent_tests.h"
#include "region_tests.h"

using tutorial_storage::Tutorial_storageRegion;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
class Tutorial_storageRegionTest : public ::testing::Test {
 protected:
  cyclus::TestContext tc_;
  Tutorial_storageRegion* src_region_;

  virtual void SetUp() {
    src_region_ = new Tutorial_storageRegion(tc_.get());
  }

  virtual void TearDown() {}
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(Tutorial_storageRegionTest, clone) {
  Tutorial_storageRegion* cloned_fac = dynamic_cast<Tutorial_storageRegion*> (src_region_->Clone());
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(Tutorial_storageRegionTest, InitialState) {
  // Test things about the initial state of the region here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(Tutorial_storageRegionTest, Print) {
  EXPECT_NO_THROW(std::string s = src_region_->str());
  // Test Tutorial_storageRegion specific aspects of the print method here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(Tutorial_storageRegionTest, Tick) {
  EXPECT_NO_THROW(src_region_->Tick());
  // Test Tutorial_storageRegion specific behaviors of the handleTick function here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(Tutorial_storageRegionTest, Tock) {
  EXPECT_NO_THROW(src_region_->Tock());
  // Test Tutorial_storageRegion specific behaviors of the handleTock function here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
cyclus::Agent* Tutorial_storageRegionConstructor(cyclus::Context* ctx) {
  return new Tutorial_storageRegion(ctx);
}

// Required to get functionality in cyclus agent unit tests library
#ifndef CYCLUS_AGENT_TESTS_CONNECTED
int ConnectAgentTests();
static int cyclus_agent_tests_connected = ConnectAgentTests();
#define CYCLUS_AGENT_TESTS_CONNECTED cyclus_agent_tests_connected
#endif  // CYCLUS_AGENT_TESTS_CONNECTED

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
INSTANTIATE_TEST_CASE_P(Tutorial_storageRegion, RegionTests,
                        ::testing::Values(&Tutorial_storageRegionConstructor));
INSTANTIATE_TEST_CASE_P(Tutorial_storageRegion, AgentTests,
                        ::testing::Values(&Tutorial_storageRegionConstructor));
