// Copyright 2018, Bosch Software Innovations GmbH.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ROSBAG2_CPP__CONVERTER_INTERFACES__SERIALIZATION_FORMAT_DESERIALIZER_HPP_
#define ROSBAG2_CPP__CONVERTER_INTERFACES__SERIALIZATION_FORMAT_DESERIALIZER_HPP_

#include <memory>
#include <string>

#include "rosbag2_cpp/types/introspection_message.hpp"
#include "rosbag2_storage/serialized_bag_message.hpp"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosbag2_cpp/visibility_control.hpp"

namespace rosbag2_cpp
{
namespace converter_interfaces
{

class ROSBAG2_CPP_PUBLIC SerializationFormatDeserializer
{
public:
  virtual ~SerializationFormatDeserializer() = default;

  virtual void deserialize(
    std::shared_ptr<const rosbag2_storage::SerializedBagMessage> serialized_message,
    const rosidl_message_type_support_t * type_support,
    std::shared_ptr<rosbag2_introspection_message_t> ros_message) = 0;

  static std::string get_package_name()
  {
    return "rosbag2_cpp";
  }
  static std::string get_base_class_name()
  {
    return "rosbag2_cpp::converter_interfaces::SerializationFormatDeserializer";
  }
};

}  // namespace converter_interfaces
}  // namespace rosbag2_cpp

#endif  // ROSBAG2_CPP__CONVERTER_INTERFACES__SERIALIZATION_FORMAT_DESERIALIZER_HPP_
