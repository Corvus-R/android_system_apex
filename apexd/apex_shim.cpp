/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "apex_shim.h"

#include <android-base/logging.h>
#include <unordered_set>

#include "apex_file.h"
#include "status.h"
#include "status_or.h"
#include "string_log.h"

namespace android {
namespace apex {
namespace shim {

namespace {

static constexpr const char* kApexCtsShimPackage = "com.android.cts.shim";

Status ValidateImage(const std::string& path) {
  // TODO(b/128625955): validate that image contains only hash.txt
  return Status::Success();
}

}  // namespace

bool IsShimApex(const ApexFile& apex_file) {
  return apex_file.GetManifest().name() == kApexCtsShimPackage;
}

Status ValidateShimApex(const ApexFile& apex_file) {
  LOG(DEBUG) << "Validating shim apex " << apex_file.GetPath();
  return ValidateImage(apex_file.GetPath());
}

Status ValidateUpdate(const ApexFile& from, const ApexFile& to) {
  LOG(DEBUG) << "Validating update of shim apex from " << from.GetPath()
             << " to " << to.GetPath();
  // TODO(b/128625955): calculate sha512(to) and verify it's equal to the value
  // stored in from.
  return Status::Success();
}

}  // namespace shim
}  // namespace apex
}  // namespace android