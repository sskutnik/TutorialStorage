#include "tutorial_storage_region.h"

using tutorial_storage::Tutorial_storageRegion;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Tutorial_storageRegion::Tutorial_storageRegion(cyclus::Context* ctx) : cyclus::Region(ctx) {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Tutorial_storageRegion::~Tutorial_storageRegion() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
std::string Tutorial_storageRegion::str() {
  return Region::str();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
extern "C" cyclus::Agent* ConstructTutorial_storageRegion(cyclus::Context* ctx) {
  return new Tutorial_storageRegion(ctx);
}
