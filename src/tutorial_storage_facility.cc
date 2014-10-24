#include "tutorial_storage_facility.h"

namespace tutorial_storage {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Tutorial_storageFacility::Tutorial_storageFacility(cyclus::Context* ctx) : cyclus::Facility(ctx) {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
std::string Tutorial_storageFacility::str() {
  return Facility::str();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void Tutorial_storageFacility::Tick() {

   LOG(cyclus::LEV_INFO1,"tutorial_storage") << "Hello...";

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void Tutorial_storageFacility::Tock() {

   LOG(cyclus::LEV_INFO1,"tutorial_storage") << "...nurse!";
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
extern "C" cyclus::Agent* ConstructTutorial_storageFacility(cyclus::Context* ctx) {
  return new Tutorial_storageFacility(ctx);
}

}  // namespace tutorial_storage
