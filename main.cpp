#include <fmt/core.h>
#include <idl/model.pb.h>
#include <idl/utils.h>

#include <db/Class.h++>
#include <iostream>

int main() {
    std::cout << "hello world!" << std::endl;
    fmt::println("hello {}!", "world");

    DB::Model::Class a(1, "1314班");
    fmt::println("id: {}, name: {}", a.getId(), a.getName());

    model::idl::People people{};
    people.set_name("tom");
    people.set_id(1);
    fmt::println("people: {}", model::idl::toJson(people));
    fmt::println("people: {}", *model::idl::toJsonPtr(people));
}