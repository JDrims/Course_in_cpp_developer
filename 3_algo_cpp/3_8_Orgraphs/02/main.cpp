#include <iostream>
#include <Windows.h>
#include <fstream>

int **create_two_array(int, int);
void print_two_array(int **matrix, int row, int col);
void delete_two_array(int **, int, int);

void sort_orgraph(int **graph, int size_graph, int index_vertex,
                  bool *arr_visited, int &index_finish, int *arr_fihish);
void sort_orgraph(int **graph, int size_graph);

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

    sort_orgraph(graph, N);

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

void sort_orgraph(int **graph, int size_graph)
{
    bool *arr_visited = new bool[size_graph]();
    int *arr_fihish = new int[size_graph]();
    int index_finish = size_graph - 1;

    for (int i = 0; i < size_graph; i++)
    {
        if (!arr_visited[i])
        {
            sort_orgraph(graph, size_graph, i, arr_visited, index_finish, arr_fihish);
        }
    }

    std::cout << "Топологический порядок вершин: ";
    for (int i = 0; i < size_graph; i++)
    {
        std::cout << (arr_fihish[i] + 1);
        if (i < size_graph - 1)
            std::cout << " ";
    }
    std::cout << std::endl;

    delete[] arr_visited;
    delete[] arr_fihish;
}

void sort_orgraph(int **graph, int size_graph, int index_vertex,
                  bool *arr_visited, int &index_finish, int *arr_fihish)
{
    arr_visited[index_vertex] = true;

    for (int i = 0; i < size_graph; i++)
    {
        if (graph[index_vertex][i] == 1 && !arr_visited[i])
        {
            sort_orgraph(graph, size_graph, i, arr_visited, index_finish, arr_fihish);
        }
    }

    arr_fihish[index_finish--] = index_vertex;
}