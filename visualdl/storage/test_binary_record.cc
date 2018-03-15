/* Copyright (c) 2017 VisualDL Authors. All Rights Reserve.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#include "visualdl/storage/binary_record.h"

#include <gtest/gtest.h>

using namespace visualdl;

TEST(BinaryRecord, init) {
  std::string message = "hello world";
  BinaryRecord rcd("./", std::move(message));
  rcd.tofile();

  BinaryRecordReader reader("./", rcd.filename());
  LOG(INFO) << reader.data;
  ASSERT_EQ(reader.data, "hello world");
}
