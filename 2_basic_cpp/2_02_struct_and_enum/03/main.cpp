#include <iostream>
#include <string>

struct sAddress
{
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;
    int index;
};

void printsAddress(const sAddress &address);

int main()
{
    sAddress address1 = {"Москва", "Арбат", 12, 8, 123456};
    sAddress address2 = {"Ижевск", "Пушкина", 59, 143, 953769};

    printsAddress(address1);
    std::cout << std::endl;
    printsAddress(address2);

    return 0;
}

void printsAddress(const sAddress &address)
{
    std::cout << "Город: " << address.city
              << "\nУлица: " << address.street
              << "\nомер дома: " << address.houseNumber
              << "\nНомер квартиры: " << address.apartmentNumber
              << "\nИндекс: " << address.index
              << std::endl;
}