#include <iostream>
#include <stdexcept>

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

    T &operator*() const
    {
        if (ptr == nullptr)
            throw std::runtime_error("MyUniquePtr nullptr");
        return *ptr;
    }
    T *operator->() const
    {
        if (ptr == nullptr)
            throw std::runtime_error("MyUniquePtr nullptr");
        return ptr;
    }
    MyUniquePtr(const MyUniquePtr &myUniquePtr) = delete;
    MyUniquePtr &operator=(const MyUniquePtr &myUniquePtr) = delete;

    T *release()
    {
        T *new_ptr = ptr;
        ptr = nullptr;
        return new_ptr;
    }
};

int main()
{
    try
    {
        MyUniquePtr<int> p(new int(100));
        std::cout << *p << std::endl;

        *p = 101;
        std::cout << *p << std::endl;

        int *old = p.release();
        std::cout << *p << std::endl;
        delete old;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}