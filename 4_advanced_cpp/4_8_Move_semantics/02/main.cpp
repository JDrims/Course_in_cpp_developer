#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

class MyBigInteger
{
    std::string value;

public:
    MyBigInteger(std::string value) : value(value) {}
    ~MyBigInteger() {}

    MyBigInteger(MyBigInteger &&other) noexcept : value(std::move(other.value)) 
    {
        other.value.clear();
    }

    MyBigInteger &operator=(MyBigInteger &&other) noexcept
    {
        if (this != &other)
        {
            value = std::move(other.value);
            other.value.clear();
        }
        return *this;
    }

    MyBigInteger operator+(const MyBigInteger &other) const
    {
        std::string a = value;
        std::string b = other.value;
        std::string result;
        int carry = 0;

        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry > 0)
        {
            int digitalA = (i >= 0) ? a[i--] - '0' : 0;
            int digitalB = (j >= 0) ? b[j--] - '0' : 0;
            int sum = digitalA + digitalB + carry;
            result.push_back('0' + (sum % 10));
            carry = sum / 10;
        }

        std::reverse(result.begin(), result.end());
        return MyBigInteger(result);
    }

    MyBigInteger operator*(const MyBigInteger &other) const
    {
        std::string a = value;
        std::string b = other.value;
        std::vector<int> result(a.size() + b.size(), 0);

        for (int i = a.size() - 1; i >= 0; --i)
        {
            for (int j = b.size() - 1; j >= 0; --j)
            {
                int digitalA = a[i] - '0';
                int digitalB = b[j] - '0';

                int mult = digitalA * digitalB + result[i + j + 1];

                result[i + j + 1] = mult % 10;
                result[i + j] += mult / 10;
            }
        }

        std::string res;
        size_t start = 0;
        while (start + 1 < result.size() && result[start] == 0)
            start++;

        for (size_t k = start; k < result.size(); ++k)
            res.push_back('0' + result[k]);

        return MyBigInteger(res);
    }

    friend std::ostream &operator<<(std::ostream &os, const MyBigInteger &num);
};

std::ostream &operator<<(std::ostream &os, const MyBigInteger &num)
{
    os << num.value;
    return os;
}

int main()
{

    auto number1 = MyBigInteger("114575");
    auto number2 = MyBigInteger("78524");
    auto sum = number1 + number2;
    std::cout << number1 << " + " << number2 << " = " << sum << std::endl;
    auto mult = number1 * number2;
    std::cout << number1 << " * " << number2 << " = " << mult << std::endl;

    return 0;
}
