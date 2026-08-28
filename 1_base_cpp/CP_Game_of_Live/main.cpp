#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "windows.h"

void loadFile(std::ifstream &, bool **, int, int);
bool **createUniverse(int, int);
void copyUniverse(bool **, bool **, int, int);
bool updateNextUniverse(bool **, bool **, int, int);
int countAliveNearby(bool **, int, int, int, int);
int countAliveUniverse(bool **, int, int);
void destroyUniverse(bool **, int, int);
void printField(bool **, int, int, int, int);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int DELAY = 1000;
    int row{0}, col{0};
    int generation{1};
    bool startGame;
    bool **currentUniverse, **nextUniverse;
    bool changeUniverse;

    std::ifstream file("initStatus.txt");
    if (!file.is_open())
    {
        std::cerr << "Error open file initStatus.txt" << std::endl;
        return 1;
    }

    file >> row >> col;
    currentUniverse = createUniverse(row, col);
    nextUniverse = createUniverse(row, col);
    loadFile(file, currentUniverse, row, col);
    startGame = true;

    while (startGame)
    {
        generation++;
        int aliveCount = countAliveUniverse(currentUniverse, row, col);
        printField(currentUniverse, row, col, generation, aliveCount);

        if (aliveCount == 0)
        {
            std::cout << "Game over! all the cells are dead" << std::endl;
            startGame = false;
        }

        changeUniverse = updateNextUniverse(currentUniverse, nextUniverse, row, col);

        if (!changeUniverse)
        {
            std::cout << "Game over: a stable configuration has been achieved" << std::endl;
            startGame = false;
        }

        copyUniverse(nextUniverse, currentUniverse, row, col);

        _sleep(DELAY);
    }

    destroyUniverse(currentUniverse, row, col);
    destroyUniverse(nextUniverse, row, col);
    file.close();
    std::system("pause");

    return 0;
}

void loadFile(std::ifstream &file, bool **matrixField, int row, int col)
{
    while (file >> row >> col)
    {
        matrixField[row][col] = true;
    }
}

bool **createUniverse(int row, int col)
{
    bool **matrixField = new bool *[row]();
    for (int i = 0; i < row; i++)
    {
        matrixField[i] = new bool[col]();
    }
    return matrixField;
}

void copyUniverse(bool **originField, bool **copyField, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            copyField[i][j] = originField[i][j];
        }
    }
}

bool updateNextUniverse(bool **currentField, bool **nextField, int row, int col)
{
    bool changedField = false;
    int alive;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            alive = countAliveNearby(currentField, row, col, i, j);

            if (currentField[i][j])
            {
                if (alive == 2 || alive == 3)
                {
                    nextField[i][j] = true;
                }
                else
                {
                    nextField[i][j] = false;
                    changedField = true;
                }
            }
            else
            {
                if (alive == 3)
                {
                    nextField[i][j] = true;
                    changedField = true;
                }
                else
                {
                    nextField[i][j] = false;
                }
            }
        }
    }
    return changedField;
}

int countAliveNearby(bool **matrixField, int row, int col, int indexRow, int indexCol)
{
    int alive = 0;
    for (int dr = -1; dr <= 1; dr++)
    {
        for (int dc = -1; dc <= 1; dc++)
        {
            if (dr == 0 && dc == 0)
                continue;

            int currRow = indexRow + dr;
            int currCol = indexCol + dc;

            if (currRow >= 0 && currRow < row && currCol >= 0 && currCol < col)
            {
                if (matrixField[currRow][currCol])
                    alive++;
            }
        }
    }
    return alive;
}

int countAliveUniverse(bool **matrixField, int row, int col)
{
    int alive = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrixField[i][j])
            {
                alive++;
            }
        }
    }
    return alive;
}

void destroyUniverse(bool **matrixField, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        delete[] matrixField[i];
    }
    delete[] matrixField;
}

void printField(bool **matrixField, int row, int col, int gen, int alive)
{
    std::system("cls");
    std::cout << " GAME OF LIVE" << std::endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << ((matrixField[i][j]) ? "*" : "-");
            if (j < (col - 1))
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Generation: " << gen << ". Alive cells: " << alive << std::endl;
}