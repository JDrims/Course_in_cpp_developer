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
    explicit SmartArry(int count = 0) : size_array(count), point(0), arr(new int[count]) {};
    SmartArry(const SmartArry &);
    ~SmartArry() { delete[] this->arr; };

    void add_element(int);
    int get_element(int index);

    SmartArry &operator=(const SmartArry &order);
};

SmartArry::SmartArry(const SmartArry &order) : size_array(order.size_array), point(order.point), arr(new int[order.size_array])
{
    for (int i = 0; i < order.point; i++)
    {
        this->arr[i] = order.arr[i];
    }
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
    if (0 > index || index >= size_array)
    {
        std::string msg = "Индекс " + std::to_string(index) +
                          " выходит за границы [0:" + std::to_string(point) + "]";
        throw std::out_of_range(msg);
    }
    return arr[index];
}

SmartArry &SmartArry::operator=(const SmartArry &order)
{
    if (this == &order)
    {
        return *this;
    }

    int *new_arr = new int[order.size_array];
    for (int i = 0; i < order.point; i++)
    {
        new_arr[i] = order.arr[i];
    }
    delete[] this->arr;

    this->arr = new_arr;
    this->size_array = order.size_array;
    this->point = order.point;

    return *this;
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

        SmartArry new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array;

        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}