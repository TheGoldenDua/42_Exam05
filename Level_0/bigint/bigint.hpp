#include <iostream>
#include <string>


class bigint
{
    private:
        std::string digits;
        std::string addStrs(const std::string& a, const std::string& b)  const;
        void removeZeros();
        bool isZero() const;

    public:
        bigint();
        bigint(const std::string& nbr);
        bigint(unsigned int nbr);

        bigint operator+(const bigint& other) const;
        bigint& operator+=(const bigint& other);

        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;
        bool operator<(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>=(const bigint& other) const;

        bigint operator<<(unsigned int shift) const;
        bigint operator>>(unsigned int shift) const;
        bigint& operator<<=(unsigned int shift);
        bigint& operator>>=(unsigned int shift);

        bigint& operator++();
        bigint operator++(int);

        std::string getDigits() const;

};

std::ostream& operator<<(std::ostream& out, const bigint& nbr);
