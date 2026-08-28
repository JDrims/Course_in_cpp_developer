#include <iostream>

int **create_two_dim_array(int, int);
void fill_two_dim_array(int **, int, int);
void print_two_dim_array(int **, int, int);
void delete_two_dim_array(int **, int, int);

int main()
{
    int row, col;

    std::cout << "Введите количество строк: ";
    std::cin >> row;

    std::cout << "Введите количество столбцов: ";
    std::cin >> col;

    int **matrix = create_two_dim_array(row, col);
    fill_two_dim_array(matrix, row, col);

    std::cout << "Таблица умножения: " << std::endl;
    print_two_dim_array(matrix, row, col);

    delete_two_dim_array(matrix, row, col);

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

void fill_two_dim_array(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = (i + 1) * (j + 1);
        }
    }
}

void print_two_dim_array(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << matrix[i][j];
            if (j < col - 1)
            {
                std::cout << "\t";
            }
        }
        std::cout << std::endl;
    }
}

void delete_two_dim_array(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        delete matrix[i];
    }
    delete[] matrix;
}