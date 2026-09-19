#include <iostream>
#include <vector>
#include <xutility>
#include <Windows.h>
#include <stdexcept>

template <typename T>
class MyVector
{
    T *arr;
    int size_arr;
    int capacity_arr;

public:
    MyVector() : arr(nullptr), size_arr(0), capacity_arr(0) {}
    MyVector(const int &count) : arr(new T[count]), size_arr(count), capacity_arr(0) {}
    MyVector(const int &count, const T &value = T()) : arr(count > 0 ? new T[count] : nullptr), size_arr(count), capacity_arr(count)
    {
        for (size_t i = 0; i < size_arr; i++)
            arr[i] = value;
    }
    ~MyVector() { delete[] arr; }

    T &at(int index)
    {
        if (0 > index || index >= size_arr)
            throw std::out_of_range("Выход за границы контейнера");
        return arr[index];
    }

    const T &at(int index) const
    {
        if (0 > index || index >= size_arr)
            throw std::out_of_range("Выход за границы контейнера");
        return arr[index];
    }

    void push_back(T value)
    {
        if (capacity_arr == size_arr)
        {
            int new_capacity = (capacity_arr == 0) ? 1 : capacity_arr * 2;

            T *new_arr = new T[new_capacity];
            for (int i = 0; i < size_arr; ++i)
                new_arr[i] = arr[i];

            delete[] arr;
            arr = new_arr;
            capacity_arr = new_capacity;
        }
        arr[size_arr] = value;
        ++size_arr;
    }

    int size() { return size_arr; }
    int capacity() { return capacity_arr; }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    MyVector<int> myVector;
    std::cout << "size = " << myVector.size() << ", capacity = " << myVector.capacity() << std::endl;

    for (int i = 1; i <= 5; ++i)
    {
        myVector.push_back(i * 10);
        std::cout << "push_back(" << i * 10 << ") -> size = " << myVector.size()
                  << ", capacity = " << myVector.capacity() << '\n';
    }

    std::cout << "v.at(2) = " << myVector.at(2) << '\n';

    try
    {
        std::cout << myVector.at(100) << '\n';
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Ошибка: " << e.what() << '\n';
    }

    return 0;
}