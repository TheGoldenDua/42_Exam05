// #ifndef BIGINT_HPP
// #define BIGINT_HPP

// #include <iostream>
// #include <string>

// class bigint
// {
//     private:
//         std::string digits;
//         void removeZeros();
//         std::string addStrs(const std::string& a, const std::string& b) const;
//         bool isZero() const;

//     public: 
//         bigint();   
//         bigint(unsigned int nbr);   
//         bigint(const std::string& nbr);

//         std::string getDigits() const;

//         bigint operator+(const bigint& other) const;
//         bigint& operator+=(const bigint& other);

//         bool operator==(const bigint& other) const;
//         bool operator!=(const bigint& other) const;
//         bool operator<(const bigint& other) const;
//         bool operator>(const bigint& other) const;
//         bool operator<=(const bigint& other) const;
//         bool operator>=(const bigint& other) const;

//         bigint operator<<(unsigned int shift) const;
//         bigint operator>>(unsigned int shift) const;
//         bigint& operator<<=(unsigned int shift);
//         bigint& operator>>=(unsigned int shift);

//         bigint& operator++();
//         bigint operator++(int);
// };
// std::ostream& operator<<(std::ostream& out, const bigint& nbr);

// #endif


#include <iostream>
#include <string>

class bigint
{
    private:
        std::string digits;

        std::string addStrs(const std::string& a, const std::string& b) const;
        void removeZeros();
        bool isNumeric(const std::string& s) const;
        
    public:
        bigint();
        bigint(unsigned int nbr);
        bigint(const std::string& nbr);
        
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
        
        bool isZero() const;
        std::string getDigits() const;
};

std::ostream& operator<<(std::ostream& out, const bigint& nbr);