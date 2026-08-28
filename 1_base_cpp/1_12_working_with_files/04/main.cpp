#include <iostream>
#include <fstream>

int **create_two_dim_array(int, int);
void print_two_dim_array(int **matrix, int row, int col);
void delete_two_dim_array(int **, int, int);

int main()
{
    std::ifstream inFile("in.txt");

    if (!inFile.is_open())
    {
        std::cerr << "Ошибка: не удалось открыть файл in.txt" << std::endl;
        return 1;
    }

    int row, col;
    if ((!(inFile >> row) || row <= 0) || (!(inFile >> col) || col <= 0))
    {
        std::cerr << "Ошибка: неверный размер массива в файле" << std::endl;
        return 1;
    }

    int **arr = create_two_dim_array(row, col);

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (!(inFile >> arr[i][j]))
            {
                std::cerr << "Ошибка: недостаточно данных в файле" << std::endl;
                delete_two_dim_array(arr, row, col);
                return 1;
            }
        }
    }

    print_two_dim_array(arr, row, col);

    delete_two_dim_array(arr, row, col);
    inFile.close();

    return 0;
}

int **create_two_dim_array(int row, int col)
{
    int **matrix = new int *[row];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
    }

    return matrix;
}

void print_two_dim_array(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            std::cout << matrix[i][j];
            if (j > 0)
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

void delete_two_dim_array(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}