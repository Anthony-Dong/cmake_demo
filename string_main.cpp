#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::string* new_string() {
    return new std::string("111 222 333");
}

class Test {
   public:
    Test() = default;
    explicit Test(int x_) : x(x_) {}
    ~Test() {
        std::cout << "release: " << x << std::endl;
    }
    Test(const Test& t) {
        std::cout << "const: " << x << std::endl;
    }
    Test& operator=(const Test& t) {
        std::cout << "operator= " << x << std::endl;
        return *this;
    }
    int get_x() const {
        std::cout << "invoke api" << std::endl;
        return x;
    }
    Test& operator+(Test& t) {
        this->x = this->x + t.x;
        return *this;
    }

   public:
    int x{};
};

Test* newTestFunc(int x) {
    return new Test(x);
}

int testDecltype(Test& x) {
    decltype(x.get_x()) xx;
    xx = x.get_x();
    return xx;
}

template <class Tp>
struct is_function : public _BoolConstant<__is_function(Tp)> {};

// int main() {
//
//
//     std::unique_ptr<Test> test1 = std::unique_ptr<Test>(new Test(1));
//     // unique_ptr只有移动语意，没有拷贝语义
//     auto test2 = std::move(test1);
//     std::cout << "test1 is null ptr: " << (test1 == nullptr) << std::endl;
//     std::cout << "test2.x: " << test2->x << std::endl;
//
//     // reset 会先释放原来指针，然后再赋值
//     test2.reset(new Test(2));
//
//     // 释放引用, 例如理论上 test2 会在main函数结束后会释放，但是我其实想要这个内容，我自己管理，就可以用 release 函数释放指针
//     Test* test2_ = test2.release();
//     std::cout << "test2_->x: " << test2_->x << std::endl;
//     delete test2_;
//
//     // 不推荐这么写，可以直接用指针指针包一层
//     //    Test* test3 = newTestFunc(3);
//     // 推荐使用智能包装一层
//     auto test = std::unique_ptr<Test>(newTestFunc(3));
//
//     Test test4(4);
//     testDecltype(test4);
// }

void builtin();
void external();
int main() {
    builtin();
    external();
}

void builtin() {
    auto list = new int[10]{};
    for (int x = 0; x < 10; x++) {
        list[x] = x;
    }
    cout << *((unsigned long*)list - 1) << endl;
    delete[] list;
}

typedef struct __CStruct {
    char* name;
    int age;
} CStruct;

void print_CStruct(CStruct* ss) {
    printf("name: %s, age: %d\n", ss->name, ss->age);
}

void external() {
    using namespace std;
    auto list = new Test[10]{};
    for (int x = 0; x < 10; x++) {
        list[x].x = x;
    }
    Test tt{};
    for (int x = 0; x < 10; x++) {
        printf("tt: %p\n", &tt);
        tt = tt + list[x];
    }

    printf("tt: %d\n", tt.x);
    // 0x600000744000
    // 0x600000744008
    // 0x600000744000
    printf("%p\n", list);
    printf("%p\n", (unsigned long*)list - 1);
    cout << *((unsigned long*)list - 1) << endl;
    delete[] list;
}

// int main() {
//     Test* test = new Test(1);
//     CClass c{
//         .point = test,
//     };
//     // 正确行为，需要强制转换成 Test*；
//     delete (Test*)c.point;
// }

int main1() {
    auto str2 = new_string();
    auto str22 = str2->c_str();
    std::cout << str22 << std::endl;
    void* str3 = str2;
    std::unique_ptr<std::string> str4 = std::unique_ptr<std::string>(str2);

    str4.release();

    //    delete str2;
    std::cout << str3 << std::endl;

    const char* const_str = "1111";
    string str(const_str, strlen(const_str));
    cout << str << endl;

    cout << str.c_str() << endl;
    printf("%p\n", const_str);
    printf("%p\n", str.c_str());

    vector<std::string> x;
    x.reserve(10);
    std::cout << x.size() << std::endl;
    std::cout << x.capacity() << std::endl;
}
