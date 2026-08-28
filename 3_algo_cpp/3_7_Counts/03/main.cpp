#include <iostream>
#include <Windows.h>
#include <fstream>

int **create_two_array(int, int);
void print_two_array(int **matrix, int row, int col);
void delete_two_array(int **, int, int);

bool dfs_cycle(int **graph, int size_graph, int num_vertex, bool *arr_visited, int prev);
bool dfs_cycle(int **graph, int size_graph);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    std::ifstream inFile("input.txt");

    if (!inFile.is_open())
    {
        std::cerr << "Ошибка: не удалось открыть файл in.txt" << std::endl;
        return 1;
    }

    if (!(inFile >> N) || N <= 0)
    {
        std::cerr << "Ошибка: неверный размер массива в файле" << std::endl;
        return 1;
    }
    std::cout << "Количество вершин в графе = " << N << std::endl;

    int **graph = create_two_array(N, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!(inFile >> graph[i][j]))
            {
                std::cerr << "Ошибка: недостаточно данных в файле" << std::endl;
                delete_two_array(graph, N, N);
                return 1;
            }
        }
    }
    print_two_array(graph, N, N);

    if (dfs_cycle(graph, N))
        std::cout << "В графе есть цикл!" << std::endl;
    else
        std::cout << "В графе нет циклов" << std::endl;

    delete_two_array(graph, N, N);
    inFile.close();

    return 0;
}

int **create_two_array(int row, int col)
{
    int **matrix = new int *[row];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
    }

    return matrix;
}

void print_two_array(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << matrix[i][j];
            if (j < col - 1)
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

void delete_two_array(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

bool dfs_cycle(int **graph, int size_graph)
{
    bool *arr_visited = new bool[size_graph]();
    for (int i = 0; i < size_graph; i++)
    {
        if (!arr_visited[i])
        {
            if (dfs_cycle(graph, size_graph, i, arr_visited, -1))
            {
                delete[] arr_visited;
                return true;
            }
        }
    }
    delete[] arr_visited;
    return false;
}

bool dfs_cycle(int **graph, int size_graph, int num_vertex, bool *arr_visited, int prev)
{
    arr_visited[num_vertex] = true;

    for (int i = 0; i < size_graph; i++)
    {
        if (graph[num_vertex][i] == 1)
        {
            if (!arr_visited[i])
            {
                if (dfs_cycle(graph, size_graph, i, arr_visited, num_vertex))
                {
                    return true;
                }
            }
            else if (i != prev)
            {
                return true;
            }
        }
    }

    return false;
}