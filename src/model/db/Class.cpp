#include "Class.h++"
#include <iostream>

using namespace Model::DB;

void print() {
    std::cout << "DB::Model::print()" << std::endl;
}

Model::DB::Class::Class(int id, const char *name) : id_(id), name_(name), c_time_(0) {}

Model::DB::Class *Class::instance_ = new Class();

std::ostream &Model::DB::operator<<(std::ostream &os, const Model::DB::Class &aClass) {
    os << "id_: " << aClass.id_ << " name_: " << aClass.name_ << " c_time_: " << aClass.c_time_;
    return os;
}

int Class::getId() const {
    return id_;
}
void Class::setId(int id) {
    id_ = id;
}
const std::string &Class::getName() const {
    return name_;
}
void Class::setName(const std::string &name) {
    name_ = name;
}
int Class::getCTime() const {
    return c_time_;
}
void Class::setCTime(int cTime) {
    c_time_ = cTime;
}
