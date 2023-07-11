#ifndef CMAKE_DEMO_CLASS_H
#define CMAKE_DEMO_CLASS_H

#include <string>
#include <ostream>

namespace Model {
namespace DB {

static int Number = 100;
static void print();

class Class {
public:
    Class() = default;
    Class(int id, const char *name);
    int getId() const;
    void setId(int id);
    const std::string &getName() const;
    void setName(const std::string &name);
    int getCTime() const;
    void setCTime(int cTime);
    friend std::ostream &operator<<(std::ostream &os, const Class &aClass);

public:
    static Class *instance_;

private:
    int id_;
    std::string name_;
    int c_time_;
};

} // namespace DB
} // namespace Model

#endif // CMAKE_DEMO_CLASS_H
