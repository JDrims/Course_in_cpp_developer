#include <iostream>
#include <fstream>
#include <string>

class Address
{
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;

public:
    Address(std::string city,
            std::string street,
            int houseNumber,
            int apartmentNumber) : city(city),
                                   street(street),
                                   houseNumber(houseNumber),
                                   apartmentNumber(apartmentNumber) {}

    std::string getStringAddress()
    {
        return this->city + ", " +
               this->street + ", " +
               std::to_string(this->houseNumber) + ", " +
               std::to_string(this->apartmentNumber);
    }
};

int main()
{
    std::ifstream inFile("in.txt");
    if (!inFile.is_open())
    {
        std::cerr << "Ошибка: не удалось открыть файл in.txt" << std::endl;
        return 1;
    }

    int N;
    if ((!(inFile >> N) || N <= 0))
    {
        std::cerr << "Ошибка: неверный количество адресов в файле" << std::endl;
        inFile.close();
        return 1;
    }
    inFile.ignore();

    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;

    Address **arrAddress = new Address *[N]();

    bool error = false;
    for (int i = 0; i < N; ++i)
    {
        std::string city, street;
        int house, apartment;

        if (!std::getline(inFile, city) ||
            !std::getline(inFile, street) ||
            !(inFile >> house) ||
            !(inFile >> apartment))
        {
            std::cerr << "Ошибка: недостаточно данных для адреса " << i + 1 << '\n';
            error = true;
            break;
        }
        inFile.ignore(); // пропустить \n после apartment

        arrAddress[i] = new Address(city, street, house, apartment);
    }

    inFile.close();

    if (error)
    {
        for (int i = 0; i < N; ++i)
            delete arrAddress[i];
        delete[] arrAddress;
        return 1;
    }

    std::ofstream outFile("out.txt");
    if (!outFile.is_open())
    {
        std::cerr << "Ошибка: не удалось открыть файл out.txt" << std::endl;
        for (int i = 0; i < N; i++)
        {
            delete arrAddress[i];
        }
        delete[] arrAddress;
        return 1;
    }

    outFile << N << "\n";
    for (int i = N - 1; 0 <= i; i--)
        outFile << arrAddress[i]->getStringAddress() << "\n";

    for (int i = 0; i < N; i++)
    {
        delete arrAddress[i];
    }
    delete[] arrAddress;
    outFile.close();

    return 0;
}