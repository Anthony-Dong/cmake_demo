#ifndef CMAKE_DEMO_UTILS_H
#define CMAKE_DEMO_UTILS_H

#include <google/protobuf/util/json_util.h>

namespace model {
namespace idl {
std::unique_ptr<std::string> toJsonPtr(google::protobuf::Message& msg);

std::string toJson(google::protobuf::Message& msg);
}  // namespace idl
}  // namespace model

#endif  // CMAKE_DEMO_UTILS_H
