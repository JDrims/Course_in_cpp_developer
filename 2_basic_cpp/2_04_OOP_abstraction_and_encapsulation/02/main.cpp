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

    std::string getStringAddress() const
    {
        return this->city + ", " +
               this->street + ", " +
               std::to_string(this->houseNumber) + ", " +
               std::to_string(this->apartmentNumber);
    }

    std::string getCity() const
    {
        return city;
    }
};

void sortAddress(Address **address, int sizeAddress);

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
        std::cerr << "Ошибка: неверное количество адресов в файле" << std::endl;
        inFile.close();
        return 1;
    }

    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;

    Address **arrAddress = new Address *[N]();

    bool error = false;
    for (int i = 0; i < N; ++i)
    {
        if (!(inFile >> city) || !(inFile >> street) ||
            !(inFile >> houseNumber) || !(inFile >> apartmentNumber))
        {
            std::cerr << "Ошибка: недостаточно данных для адреса " << i + 1 << '\n';
            error = true;
            break;
        }
        arrAddress[i] = new Address(city, street, houseNumber, apartmentNumber);
    }
    inFile.close();

    if (error)
    {
        for (int i = 0; i < N; ++i)
            delete arrAddress[i];
        delete[] arrAddress;
        return 1;
    }

    sortAddress(arrAddress, N);

    std::ofstream outFile("out.txt");
    if (!outFile.is_open())
    {
        std::cerr << "Ошибка: не удалось открыть файл out.txt" << std::endl;
        for (int i = 0; i < N; ++i)
            delete arrAddress[i];
        delete[] arrAddress;
        return 1;
    }

    outFile << N << "\n";
    for (int i = 0; i < N; i++)
    {
        outFile << arrAddress[i]->getStringAddress();
        if (i < N - 1)
            outFile << "\n";
    }
    outFile.close();

    for (int i = 0; i < N; i++)
        delete arrAddress[i];
    delete[] arrAddress;

    return 0;
}

void sortAddress(Address **address, int sizeAddress)
{
    for (int i = 0; i < sizeAddress - 1; i++)
    {
        for (int j = 0; j < sizeAddress - i - 1; j++)
        {
            if (address[j]->getCity() > address[j + 1]->getCity())
            {
                Address *tempAddress = address[j];
                address[j] = address[j + 1];
                address[j + 1] = tempAddress;
            }
        }
    }
}