#include <iostream>
#include <Windows.h>

bool has_parent(int index)
{
    return index > 0;
}

int get_parent_index(int index)
{
    return (index - 1) / 2;
}

bool has_left_child(int index, int size)
{
    return (2 * index + 1) < size;
}

int get_left_child_index(int index)
{
    return 2 * index + 1;
}

bool has_right_child(int index, int size)
{
    return (2 * index + 2) < size;
}

int get_right_child_index(int index)
{
    return 2 * index + 2;
}

void print_element(int *arr, int index, int size)
{
    int level = 0;
    int temp = index + 1;
    while (temp > 1)
    {
        temp /= 2;
        ++level;
    }

    if (index == 0)
    {
        std::cout << level << " root " << arr[index];
    }
    else
    {
        int parent_idx = (index - 1) / 2;
        if (index % 2 == 1)
        {
            std::cout << level << " left(" << arr[parent_idx] << ") " << arr[index];
        }
        else
        {
            std::cout << level << " right(" << arr[parent_idx] << ") " << arr[index];
        }
    }
    std::cout << std::endl;
}

void print_pyramid(const int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int level = 0;
        int index = i + 1;
        while (index > 1)
        {
            index /= 2;
            level++;
        }

        if (i == 0)
        {
            std::cout << level << " root " << arr[i];
        }
        else
        {
            int parent_index = (i - 1) / 2;
            int parent_value = arr[parent_index];
            if (i % 2 == 1)
            {
                std::cout << level << " left(" << parent_value << ") " << arr[i];
            }
            else
            {
                std::cout << level << " right(" << parent_value << ") " << arr[i];
            }
        }
        std::cout << std::endl;
    }
}

void print_arr(const int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i < size - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void travel(int *arr, int size)
{
    int current = 0;
    std::string command;

    while (true)
    {
        std::cout << "Вы находитесь здесь: ";
        print_element(arr, current, size);

        std::cout << "Введите команду: ";
        std::cin >> command;

        if (command == "exit")
        {
            break;
        }
        else if (command == "up")
        {
            if (has_parent(current))
            {
                current = get_parent_index(current);
                std::cout << "Ок" << std::endl;
            }
            else
            {
                std::cout << "Ошибка! Отсутствует родитель" << std::endl;
            }
        }
        else if (command == "left")
        {
            if (has_left_child(current, size))
            {
                current = get_left_child_index(current);
                std::cout << "Ок" << std::endl;
            }
            else
            {
                std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
            }
        }
        else if (command == "right")
        {
            if (has_right_child(current, size))
            {
                current = get_right_child_index(current);
                std::cout << "Ок" << std::endl;
            }
            else
            {
                std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
            }
        }
        else
        {
            std::cout << "Неизвестная команда. Доступны: up, left, right, exit" << std::endl;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr_1[] = {1, 3, 6, 5, 9, 8};
    int size_arr_1 = sizeof(arr_1) / sizeof(arr_1[0]);

    int arr_2[] = {94, 67, 18, 44, 55, 12, 6, 42};
    int size_arr_2 = sizeof(arr_2) / sizeof(arr_2[0]);

    int arr_3[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    int size_arr_3 = sizeof(arr_3) / sizeof(arr_3[0]);

    std::cout << "Исходный массив: ";
    print_arr(arr_1, size_arr_1);
    std::cout << "Пирамида:" << std::endl;
    print_pyramid(arr_1, size_arr_1);
    std::cout << std::endl;

    travel(arr_1, size_arr_1);
    std::cout << std::endl;

    std::cout << "Исходный массив: ";
    print_arr(arr_2, size_arr_2);
    std::cout << "Пирамида:" << std::endl;
    print_pyramid(arr_2, size_arr_2);
    std::cout << std::endl;

    travel(arr_2, size_arr_2);
    std::cout << std::endl;

    std::cout << "Исходный массив: ";
    print_arr(arr_3, size_arr_3);
    std::cout << "Пирамида:" << std::endl;
    print_pyramid(arr_3, size_arr_3);
    std::cout << std::endl;

    travel(arr_3, size_arr_3);

    return 0;
}