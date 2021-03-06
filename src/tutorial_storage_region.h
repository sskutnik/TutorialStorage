#ifndef CYCLUS_TUTORIAL_STORAGES_TUTORIAL_STORAGE_REGION_H_
#define CYCLUS_TUTORIAL_STORAGES_TUTORIAL_STORAGE_REGION_H_

#include <string>

#include "cyclus.h"

namespace tutorial_storage {

/// @class Tutorial_storageRegion
///
/// This Region is intended
/// as a skeleton to guide the implementation of new Region agents.
///
/// The Tutorial_storageRegion class inherits from the Region class and is
/// dynamically loaded by the Agent class when requested.
///
/// @section intro Introduction
/// Place an introduction to the agent here.
///
/// @section agentparams Agent Parameters
/// Place a description of the required input parameters which define the
/// agent implementation.
///
/// @section optionalparams Optional Parameters
/// Place a description of the optional input parameters to define the
/// agent implementation.
///
/// @section detailed Detailed Behavior
/// Place a description of the detailed behavior of the agent. Consider
/// describing the behavior at the tick and tock as well as the behavior
/// upon sending and receiving materials and messages.
class Tutorial_storageRegion : public cyclus::Region {
 public:
  /// Constructor for Tutorial_storageRegion Class
  /// @param ctx the cyclus context for access to simulation-wide parameters
  explicit Tutorial_storageRegion(cyclus::Context* ctx);

  /// Every agent should be destructable
  virtual ~Tutorial_storageRegion();

  /// The Prime Directive
  /// Generates code that handles all input file reading and restart operations
  /// (e.g., reading from the database, instantiating a new object, etc.).
  /// @warning The Prime Directive must have a space before it! (A fix will be
  /// in 2.0 ^TM)

  #pragma cyclus

  #pragma cyclus note {"doc": "A tutorial_storage region is provided as a skeleton " \
                              "for the design of new region agents."}

  /// A verbose printer for the Tutorial_storageRegion
  virtual std::string str();

  // And away we go!
};

}  // namespace tutorial_storage

#endif  // CYCLUS_TUTORIAL_STORAGES_TUTORIAL_STORAGE_REGION_H_
