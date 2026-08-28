#include <iostream>
#include <numeric>

class Fraction
{
private:
    int numerator_;
    int denominator_;

    void reduce()
    {
        if (denominator_ < 0)
        {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }

        int gcd = std::gcd(std::abs(numerator_), std::abs(denominator_));
        numerator_ /= gcd;
        denominator_ /= gcd;
    }

public:
    Fraction(int numerator, int denominator)
        : numerator_(numerator), denominator_(denominator)
    {
        reduce();
    }

    int getNumerator() const { return numerator_; }
    int getDenominator() const { return denominator_; }

    bool operator==(const Fraction &f2) const
    {
        return ((this->numerator_ * f2.denominator_) == (this->denominator_ * f2.numerator_));
    }

    bool operator!=(const Fraction &f2) const
    {
        return ((this->numerator_ * f2.denominator_) < (this->denominator_ * f2.numerator_));
    }

    bool operator<(const Fraction &f2) const
    {
        return !(*this == f2);
    }

    bool operator>(const Fraction &f2) const
    {
        return f2 < *this;
    }

    bool operator<=(const Fraction &f2) const
    {
        return !(f2 < *this);
    }

    bool operator>=(const Fraction &f2) const
    {
        return !(*this < f2);
    }

    Fraction operator+(const Fraction &f2) const
    {
        int new_num = (this->numerator_ * f2.denominator_) + (f2.numerator_ * denominator_);
        int new_den = this->denominator_ * f2.denominator_;
        return Fraction(new_num, new_den);
    }

    Fraction operator-(const Fraction &f2) const
    {
        int new_num = (this->numerator_ * f2.denominator_) - (f2.numerator_ * denominator_);
        int new_den = this->denominator_ * f2.denominator_;
        return Fraction(new_num, new_den);
    }

    Fraction operator*(const Fraction &f2) const
    {
        int new_num = this->numerator_ * f2.numerator_;
        int new_den = this->denominator_ * f2.denominator_;
        return Fraction(new_num, new_den);
    }

    Fraction operator/(const Fraction &f2) const
    {
        int new_num = this->numerator_ * f2.denominator_;
        int new_den = this->denominator_ * f2.numerator_;
        return Fraction(new_num, new_den);
    }

    Fraction operator-() const
    {
        return Fraction(-numerator_, denominator_);
    }

    Fraction &operator++()
    {
        numerator_ += denominator_;
        reduce();
        return *this;
    }

    Fraction operator++(int)
    {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction &operator--()
    {
        numerator_ -= denominator_;
        reduce();
        return *this;
    }

    Fraction operator--(int)
    {
        Fraction temp = *this;
        --(*this);
        return temp;
    }
};

std::ostream &operator<<(std::ostream &os, const Fraction &f)
{
    os << f.getNumerator() << "/" << f.getDenominator();
    return os;
}

std::istream &operator>>(std::istream &is, Fraction &f)
{
    int num, den;
    char slash;
    is >> num >> slash >> den;
    f = Fraction(num, den);
    return is;
}

int main()
{
    Fraction f1(0, 1);
    Fraction f2(0, 1);

    int num1, num2, den1, den2;

    std::cout << "Введите числитель дроби 1: ";
    std::cin >> num1;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> den1;
    std::cout << "Введите числитель дроби 2: ";
    std::cin >> num2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> den2;

    f1 = Fraction(num1, den1);
    f2 = Fraction(num2, den2);

    std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << std::endl;
    std::cout << f1 << " - " << f2 << " = " << (f1 - f2) << std::endl;
    std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << std::endl;
    std::cout << f1 << " / " << f2 << " = " << (f1 / f2) << std::endl;

    Fraction temp1 = f1;
    std::cout << "++" << f1 << " * " << f2 << " = " << (++temp1 * f2) << std::endl;
    std::cout << "Значение дроби 1 = " << temp1 << std::endl;

    Fraction temp2 = temp1;
    std::cout << temp1 << "--" << " * " << f2 << " = " << (temp2-- * f2) << std::endl;
    std::cout << "Значение дроби 1 = " << temp2 << std::endl;

    return 0;
}