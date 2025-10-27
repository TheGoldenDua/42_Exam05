#include "bigint.hpp"
#include <sstream>
#include <algorithm>


bigint::bigint() : digits("0") {}

bigint::bigint(unsigned int nbr)
{
    if(nbr == 0)
    {
        digits = "0";
        return ;
    }
    else
    {
        std::ostringstream oss;
        oss << nbr;
        digits = oss.str();
        std::reverse(digits.begin(), digits.end());
    }
}

bigint::bigint(const std::string& nbr)
{
    if(nbr.empty() || !(std::all_of(nbr.begin(), nbr.end(), ::isdigit)))
        digits = "0";
    else
    {
        digits = nbr;
        std::reverse(digits.begin(), digits.end());
        removeZeros();
    }
}

void bigint::removeZeros()
{
    while(digits.size() > 1 && digits.back() == '0')
        digits.pop_back();
}

bool bigint::isZero() const
{
    return digits == "0";
}

std::string bigint::getDigits() const
{
    return digits;
}

std::ostream& operator<<(std::ostream& out, const bigint& nbr)
{
    std::string nb(nbr.getDigits());
    std::reverse(nb.begin() , nb.end());
    out << nb;
    return out;
}

std::string bigint::addStrs(const std::string& a, const std::string& b) const
{
    std::string res;
    int carry = 0;
    int len = std::max(a.size(), b.size());

    for (size_t i = 0; i < len || carry; i++)
    {
        int digitA = i < a.size() ? a[i] - '0' : 0;
        int digitB = i < b.size() ? b[i] - '0' : 0;
        int sum = digitA + digitB + carry;
        
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    return res;
}

bigint bigint::operator+(const bigint& other) const
{
    bigint res;

    res.digits = addStrs(this->digits, other.digits);
    res.removeZeros();
    return res;
}

bigint& bigint::operator+=(const bigint& other)
{
    digits = addStrs(this->digits, other.digits);
    removeZeros();
    return *this;
}

bool bigint::operator==(const bigint& other) const
{
    bigint a = *this, b = other;

    a.removeZeros();
    b.removeZeros();
    return a.digits == b.digits;
}

bool bigint::operator!=(const bigint& other) const
{
    return !(*this == other);
}

bool bigint::operator<(const bigint& other) const
{
    bigint a = *this, b = other;

    a.removeZeros();
    b.removeZeros();

    if(a.digits.size() != b.digits.size())
        return a.digits.size() < b.digits.size();

    for (size_t i = a.digits.size() - 1; i >= 0; --i)
    {
        if(a.digits[i] != b.digits[i])
            return a.digits[i] < b.digits[i];
    }
    return false;
} 

bool bigint::operator>(const bigint& other) const
{
    return (other < *this);
}

bool bigint::operator<=(const bigint& other) const
{
    return !(*this > other);
}

bool bigint::operator>=(const bigint& other) const
{
    return !(*this < other);
}

bigint bigint::operator<<(unsigned int shift) const
{
    if(isZero() || shift == 0)
        return *this;

    bigint res = *this;
    res.digits.insert(res.digits.begin(), shift, '0');
    res.removeZeros();
    return res;
}

bigint bigint::operator>>(unsigned int shift) const
{
    if(shift == 0)
        return *this;

    bigint res = *this;
    if(res.digits.size() <= shift)
        res.digits = "0";
    else
        res.digits.erase(res.digits.begin(), res.digits.begin() + shift);
    res.removeZeros();
    return res;
}

bigint& bigint::operator<<=(unsigned int shift)
{
    *this = (*this << shift);
    return *this;
}

bigint& bigint::operator>>=(unsigned int shift)
{
    *this = (*this >> shift);
    return *this;
}

bigint bigint::operator++(int)
{
    bigint tmp = *this;

    *this += bigint(1);
    return tmp;
}

bigint& bigint::operator++()
{
    *this += bigint(1);
    return *this;
}