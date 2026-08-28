#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> shiftRight(const std::vector<int> &arr)
{
    if (arr.empty())
        return arr;
    std::vector<int> result(arr.size());
    result[0] = arr.back();
    for (size_t i = 1; i < arr.size(); ++i)
    {
        result[i] = arr[i - 1];
    }
    return result;
}

std::vector<int> shiftLeft(const std::vector<int> &arr)
{
    if (arr.empty())
        return arr;
    std::vector<int> result(arr.size());
    for (size_t i = 0; i < arr.size() - 1; ++i)
    {
        result[i] = arr[i + 1];
    }
    result.back() = arr.front();
    return result;
}

int main()
{
    std::ifstream inFile("in.txt");
    if (!inFile.is_open())
    {
        std::cerr << "Не удалось открыть файл in.txt!" << std::endl;
        return 1;
    }

    int N;
    inFile >> N;
    std::vector<int> arrayN(N);
    for (int i = 0; i < N; ++i)
    {
        inFile >> arrayN[i];
    }

    int M;
    inFile >> M;
    std::vector<int> arrayM(M);
    for (int i = 0; i < M; ++i)
    {
        inFile >> arrayM[i];
    }
    inFile.close();

    std::vector<int> shiftedM = shiftRight(arrayM);
    std::vector<int> shiftedN = shiftLeft(arrayN);

    std::ofstream outFile("out.txt");
    if (!outFile.is_open())
    {
        std::cerr << "Не удалось открыть файл out.txt для записи!" << std::endl;
        return 1;
    }

    outFile << M << std::endl;
    for (int val : shiftedM)
    {
        outFile << val << " ";
    }
    outFile << std::endl;

    outFile << N << std::endl;
    for (int val : shiftedN)
    {
        outFile << val << " ";
    }
    outFile << std::endl;

    outFile.close();

    std::cout << "Программа успешно завершена. Результат записан в out.txt" << std::endl;
    return 0;
}