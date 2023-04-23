#include <fmt/core.h>
#include <idl/model.pb.h>
#include <idl/utils.h>

#include <db/Class.h++>
#include <iostream>

int main() {
    std::cout << "hello world!" << std::endl;
    fmt::print("hello {}!\n", "world");

    DB::Model::Class a(1, "1314班");
    fmt::print("id: {}, name: {}\n", a.getId(), a.getName());

    model::idl::People people{};
    people.set_name("tom");
    people.set_id(1);
    fmt::print("people: {}\n", model::idl::toJson(people));
    fmt::print("people: {}\n", *model::idl::toJsonPtr(people));
}