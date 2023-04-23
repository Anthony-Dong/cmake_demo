#include "Class.h++"

using namespace DB::Model;

Class::Class(int id, const char* name) : id(id), name(name) {}

void Class::setId(int _id) {
    Class::id = _id;
}

void Class::setName(const std::string& _name) {
    this->name = _name;
}

void Class::setCTime(int cTime) {
    c_time = cTime;
}

int Class::getId() const {
    return id;
}

const std::string& Class::getName() const {
    return name;
}

int Class::getCTime() const {
    return c_time;
}
