#include <fmt/core.h>
#include "src/model/idl/model.pb.h"
#include "src/model/db/Class.h++"
#include "src/model/idl/utils.h"
#include <iostream>
#include <absl/strings/str_format.h>
#include <google/protobuf/util/json_util.h>

int main() {
    fmt::print("hello {}!\n", "world");

    Model::DB::Class a(1, "1314班");
    std::cout << a << std::endl;

    model::idl::People people{};
    people.set_name("tom");
    people.set_id(1);
    fmt::print("people: {}\n", model::idl::toJson(people));
    std::string out;
    google::protobuf::util::MessageToJsonString(people, &out);
    fmt::print("out {}!\n", out);

    std::string str = absl::StrFormat("Welcome to %s, Number %d!", "The Village", 6);
    std::cout << str << std::endl;
}