#include <iostream>
#include <Windows.h>
#include <fstream>

int **create_two_array(int, int);
void print_two_array(int **matrix, int row, int col);
void delete_two_array(int **, int, int);

void bfs(int **graph, int size_graph, int start);

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
    std::cout << "В графе " << N << " вершин." << std::endl;

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

    int num_vertex;
    do
    {
        std::cout << "Введите номер вершины, с которой начнётся обход: ";
        std::cin >> num_vertex;
        if (num_vertex < 1 || num_vertex > N)
        {
            std::cout << "Некорректный номер! Введите число от 1 до " << N << "." << std::endl;
        }
    } while (num_vertex < 1 || num_vertex > N);

    bfs(graph, N, num_vertex);

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

void bfs(int **graph, int size_graph, int start)
{
    bool *arr_visited = new bool[size_graph]();
    int *queue = new int[size_graph];
    int head = 0;
    int tail = 0;

    int start_index = start - 1;
    arr_visited[start_index] = true;
    queue[tail++] = start_index;

    std::cout << "Порядок обхода вершин: ";

    while (head < tail)
    {
        int v = queue[head++];
        std::cout << (v + 1);

        for (int i = 0; i < size_graph; i++)
        {
            if (graph[v][i] == 1 && !arr_visited[i])
            {
                arr_visited[i] = true;
                queue[tail++] = i;
            }
        }
        if (head < tail)
            std::cout << " ";
    }
    std::cout << std::endl;

    delete[] arr_visited;
    delete[] queue;
}