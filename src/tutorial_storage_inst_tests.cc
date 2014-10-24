#include <gtest/gtest.h>

#include <string>

#include "tutorial_storage_inst.h"

#include "institution_tests.h"
#include "agent_tests.h"

using tutorial_storage::Tutorial_storageInst;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
class Tutorial_storageInstTest : public ::testing::Test {
 protected:
  cyclus::TestContext tc_;
  Tutorial_storageInst* src_inst_;

  virtual void SetUp() {
    src_inst_ = new Tutorial_storageInst(tc_.get());
  }

  virtual void TearDown() {}
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(Tutorial_storageInstTest, clone) {
  Tutorial_storageInst* cloned_fac = dynamic_cast<Tutorial_storageInst*> (src_inst_->Clone());
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(Tutorial_storageInstTest, InitialState) {
  // Test things about the initial state of the inst here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(Tutorial_storageInstTest, Print) {
  EXPECT_NO_THROW(std::string s = src_inst_->str());
  // Test Tutorial_storageInst specific aspects of the print method here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(Tutorial_storageInstTest, Tick) {
  int time = 1;
  EXPECT_NO_THROW(src_inst_->Tick());
  // Test Tutorial_storageInst specific behaviors of the handleTick function here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(Tutorial_storageInstTest, Tock) {
  int time = 1;
  EXPECT_NO_THROW(src_inst_->Tock());
  // Test Tutorial_storageInst specific behaviors of the handleTock function here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
cyclus::Agent* Tutorial_storageInstitutionConstructor(cyclus::Context* ctx) {
  return new Tutorial_storageInst(ctx);
}

// Required to get functionality in cyclus agent unit tests library
#ifndef CYCLUS_AGENT_TESTS_CONNECTED
int ConnectAgentTests();
static int cyclus_agent_tests_connected = ConnectAgentTests();
#define CYCLUS_AGENT_TESTS_CONNECTED cyclus_agent_tests_connected
#endif  // CYCLUS_AGENT_TESTS_CONNECTED

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
INSTANTIATE_TEST_CASE_P(Tutorial_storageInst, InstitutionTests,
                        ::testing::Values(&Tutorial_storageInstitutionConstructor));
INSTANTIATE_TEST_CASE_P(Tutorial_storageInst, AgentTests,
                        ::testing::Values(&Tutorial_storageInstitutionConstructor));
