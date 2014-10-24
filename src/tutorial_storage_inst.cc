#include "tutorial_storage_inst.h"

using tutorial_storage::Tutorial_storageInst;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Tutorial_storageInst::Tutorial_storageInst(cyclus::Context* ctx) : cyclus::Institution(ctx) {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Tutorial_storageInst::~Tutorial_storageInst() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
std::string Tutorial_storageInst::str() {
  return Institution::str();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
extern "C" cyclus::Agent* ConstructTutorial_storageInst(cyclus::Context* ctx) {
  return new Tutorial_storageInst(ctx);
}
