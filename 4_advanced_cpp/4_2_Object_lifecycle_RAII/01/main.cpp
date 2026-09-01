#include <iostream>
#include <Windows.h>
#include <xutility>
#include <string>

class SmartArry
{
private:
    int size_array;
    int *arr;
    int point;

public:
    explicit SmartArry(int count = 0) : size_array(count), point(0), arr(new int[count]) {}
    ~SmartArry() { delete[] this->arr; }

    void add_element(int);
    int get_element(int index);
};

void SmartArry::add_element(int element)
{
    if (point == size_array)
    {
        int new_size = (size_array == 0) ? 1 : size_array * 2;
        int *new_arr = new int[new_size];
        for (int i = 0; i < size_array; i++)
        {
            new_arr[i] = this->arr[i];
        }
        delete[] arr;
        arr = new_arr;
        size_array = new_size;
    }
    arr[this->point++] = element;
}

int SmartArry::get_element(int index)
{
    if (0 > index || index > size_array)
    {
        std::string msg = "Индекс " + std::to_string(index) +
                          " выходит за границы [0:" + std::to_string(point) + "]";
        throw std::out_of_range(msg);
    }
    return arr[index];
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try
    {
        SmartArry arr(2);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(2) << std::endl;
        std::cout << arr.get_element(-1) << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}