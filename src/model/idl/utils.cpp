#include "utils.h"

std::unique_ptr<std::string> model::idl::toJsonPtr(google::protobuf::Message& msg) {
    auto out = std::unique_ptr<std::string>(new std::string());
    out->reserve(16);
    google::protobuf::util::MessageToJsonString(msg, out.get());
    return out;
}

std::string model::idl::toJson(google::protobuf::Message& msg) {
    std::string out;
    out.reserve(16);
    google::protobuf::util::MessageToJsonString(msg, &out);
    return out;
}