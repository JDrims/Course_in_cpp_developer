#include <iostream>

template <typename T>
class MyUniquePtr
{
    T *ptr;

public:
    explicit MyUniquePtr(T *ptr = nullptr) : ptr(ptr) { std::cout << "class create" << std::endl; }
    ~MyUniquePtr()
    {
        std::cout << "class delete" << std::endl;
        delete ptr;
    }

    T &operator*() const { return *ptr; }
    MyUniquePtr(const MyUniquePtr &) = delete;
    MyUniquePtr &operator=(const MyUniquePtr &) = delete;

    T *release()
    {
        T *new_ptr = ptr;
        ptr = nullptr;
        return new_ptr;
    }
};

int main()
{
    MyUniquePtr<int> p(new int(100));
    std::cout << *p << std::endl;

    *p = 101;
    std::cout << *p << std::endl;

    int *old = p.release();
    delete old;

    return 0;
}