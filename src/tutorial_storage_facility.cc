#include "tutorial_storage_facility.h"

namespace tutorial_storage {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Tutorial_storageFacility::Tutorial_storageFacility(cyclus::Context* ctx) : cyclus::Facility(ctx) {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
std::string Tutorial_storageFacility::str() {
  return Facility::str();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void Tutorial_storageFacility::Tick() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void Tutorial_storageFacility::Tock() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
extern "C" cyclus::Agent* ConstructTutorial_storageFacility(cyclus::Context* ctx) {
  return new Tutorial_storageFacility(ctx);
}

}  // namespace tutorial_storage
