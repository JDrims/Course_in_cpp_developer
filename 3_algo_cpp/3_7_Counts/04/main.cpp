#include <iostream>
#include <Windows.h>
#include <fstream>

int **create_two_array(int, int);
void print_two_array(int **matrix, int row, int col);
void delete_two_array(int **, int, int);

void dfs_connectivity(int **graph, int size_graph, int num_vertex, int *arr_visited, int comp_id);
void dfs_connectivity(int **graph, int size_graph);

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
    inFile.close();

    print_two_array(graph, N, N);

    dfs_connectivity(graph, N);

    delete_two_array(graph, N, N);

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

void dfs_connectivity(int **graph, int size_graph)
{
    int *arr_visited = new int[size_graph]();
    int count_id = 0;

    for (int i = 0; i < size_graph; i++)
    {
        if (arr_visited[i] == 0)
        {
            count_id++;
            dfs_connectivity(graph, size_graph, i, arr_visited, count_id);
        }
    }

    std::cout << "Принадлежность вершин компонентам связности:" << std::endl;
    for (int i = 0; i < size_graph; i++)
    {
        std::cout << (i + 1) << " - " << arr_visited[i] << std::endl;
    }
    std::cout << "Количество компонентов связности в графе: " << count_id << std::endl;

    delete[] arr_visited;
}

void dfs_connectivity(int **graph, int size_graph, int num_vertex, int *arr_visited, int comp_id)
{
    arr_visited[num_vertex] = comp_id;

    for (int i = 0; i < size_graph; i++)
    {
        if ((graph[num_vertex][i] == 1) && (arr_visited[i] == 0))
        {
            dfs_connectivity(graph, size_graph, i, arr_visited, comp_id);
        }
    }
}