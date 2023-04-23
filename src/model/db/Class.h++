#ifndef CMAKE_DEMO_CLASS_H
#define CMAKE_DEMO_CLASS_H

#include <string>

namespace DB {
namespace Model {

class Class {
   public:
    Class() = default;

    Class(int id, const char* name);

    void setId(int id);

    void setName(const std::string& name);

    void setCTime(int cTime);

    int getId() const;

    const std::string& getName() const;

    int getCTime() const;

   private:
    int id{};
    std::string name{};
    int c_time{};
};
}  // namespace Model
}  // namespace DB

#endif  // CMAKE_DEMO_CLASS_H
