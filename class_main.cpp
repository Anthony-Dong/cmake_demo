#include <absl/base/call_once.h>
#include <fmt/core.h>

template <class T>
class ThreadSafeSingleton {
public:
    static T &get() {
        absl::call_once(ThreadSafeSingleton<T>::create_once_, &ThreadSafeSingleton<T>::Create);
        return *ThreadSafeSingleton<T>::instance_;
    }

protected:
    static void Create() { instance_ = new T(); }
    static absl::once_flag create_once_;
    static T *instance_;
};

template <class T>
absl::once_flag ThreadSafeSingleton<T>::create_once_;

template <class T>
T *ThreadSafeSingleton<T>::instance_ = nullptr;

// An instance of a singleton class which has the same thread safety properties
// as ThreadSafeSingleton, but must be created via initialize prior to access.
//
// As with ThreadSafeSingleton the use of this class is generally discouraged.
template <class T>
class InjectableSingleton {
public:
    static T &get() {
        RELEASE_ASSERT(loader_ != nullptr, "InjectableSingleton used prior to initialization");
        return *loader_;
    }

    static T *getExisting() { return loader_; }

    static void initialize(T *value) {
        RELEASE_ASSERT(value != nullptr, "InjectableSingleton initialized with null value.");
        RELEASE_ASSERT(loader_ == nullptr, "InjectableSingleton initialized multiple times.");
        loader_ = value;
    }
    static void clear() { loader_ = nullptr; }

protected:
    static std::atomic<T *> loader_;
};

template <class T>
std::atomic<T *> InjectableSingleton<T>::loader_ = nullptr;

template <class T>
class ScopedInjectableLoader {
public:
    explicit ScopedInjectableLoader(std::unique_ptr<T> &&instance) {
        instance_ = std::move(instance);
        InjectableSingleton<T>::initialize(instance_.get());
    }
    ~ScopedInjectableLoader() { InjectableSingleton<T>::clear(); }

    T &instance() { return *instance_; }

private:
    std::unique_ptr<T> instance_;
};

// This class saves the singleton object and restore the original singleton at destroy. This class
// is not thread safe. It can be used in single thread test.
template <class T>
class StackedScopedInjectableLoader :
    // To access the protected loader_.
    protected InjectableSingleton<T> {
public:
    explicit StackedScopedInjectableLoader(std::unique_ptr<T> &&instance) {
        original_loader_ = InjectableSingleton<T>::getExisting();
        InjectableSingleton<T>::clear();
        instance_ = std::move(instance);
        InjectableSingleton<T>::initialize(instance_.get());
    }
    ~StackedScopedInjectableLoader() { InjectableSingleton<T>::loader_ = original_loader_; }

private:
    std::unique_ptr<T> instance_;
    T *original_loader_;
};

void foo() {
    fmt::print("hello world\n");
}

class Demo : public ThreadSafeSingleton<Demo> {
public:
    Demo() { fmt::print("hello world demo\n"); }
};

class A {
public:
    static int num;
};
int A::num = 100;
class B : public A {};
class C : public A {};

template <class T>
class AA {
public:
    static int num;
};

template <class T>
int AA<T>::num = 1;
class BB : public AA<BB> {};
class CC : public AA<CC> {};

int main() {
    auto  bb =ThreadSafeSingleton<BB>::get();

    printf("%p\n", &B::num);
    printf("%p\n", &C::num);

    printf("%p\n", &BB::num);
    printf("%p\n", &CC::num);

    BB b;
    b.num = 3;

    printf("%d\n", BB::num);
}

// output:
// 0x10f2c5030
// 0x10f2c5030
// 0x10f2c5034
// 0x10f2c5038