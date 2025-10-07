#include "vect2.hpp"

vect2::vect2(int x, int y)
{
    data[0] = x;
    data[1] = y;
}

vect2::vect2(const vect2& other)
{
    data[0] = other.data[0];
    data[1] = other.data[1];
}

vect2& vect2::operator=(const vect2& other)
{
    if(this != &other)
    {
        data[0] = other.data[0];
        data[1] = other.data[1];
    }
    return *this;
}

int& vect2::operator[](int index)
{
    return (data[index]);
}

const int& vect2::operator[](int index) const
{
    return (data[index]);
}

std::ostream& operator<<(std::ostream& out, const vect2& other)
{
    out << "{" << other[0] << ", " << other[1] << "}";
    return out;
}

vect2& vect2::operator++()
{
    ++(data[0]);
    ++(data[1]);

    return *this;
}

vect2 vect2::operator++(int)
{
    vect2 res = *this;

    ++(data[0]);
    ++(data[1]);

    return res;
}
vect2& vect2::operator--()
{
    --(data[0]);
    --(data[1]);

    return *this;
}

vect2 vect2::operator--(int)
{
    vect2 res = *this;

    --(data[0]);
    --(data[1]);

    return res;
}

vect2& vect2::operator+=(const vect2& other)
{
    data[0] += other.data[0];
    data[1] += other.data[1];

    return *this;
}

vect2& vect2::operator-=(const vect2& other)
{
    data[0] -= other.data[0];
    data[1] -= other.data[1];

    return *this;
}

vect2& vect2::operator*=(int carry)
{
    data[0] *= carry;
    data[1] *= carry;

    return *this;
}

vect2 vect2::operator+(const vect2& other)const
{
    vect2 sum;
    sum.data[0]  = this->data[0] + other.data[0];
    sum.data[1]  = this->data[1] + other.data[1];

    return sum;
}

vect2 vect2::operator-(const vect2& other)const
{
    vect2 sum;
    sum.data[0]  = this->data[0] - other.data[0];
    sum.data[1]  = this->data[1] - other.data[1];

    return sum;
}

vect2 vect2::operator*(int carry)const
{
    vect2 res;
    res.data[0]  = this->data[0] * carry;
    res.data[1]  = this->data[1] * carry;

    return res;
}

vect2 vect2::operator+()
{
    vect2 res;
    res.data[0]  = +this->data[0];
    res.data[1]  = +this->data[1];

    return res;
}

vect2 vect2::operator-()
{
    vect2 res;
    res.data[0]  = -this->data[0];
    res.data[1]  = -this->data[1];

    return res;
}

bool vect2::operator==(const vect2& other)const
{
    return(data[0] == other.data[0] && data[1] == other.data[1]);
}

bool vect2::operator!=(const vect2& other)const
{
    return(data[0] == other.data[0] && data[1] == other.data[1]);
}

vect2 operator*(int carry, const vect2& v)
{
    return(vect2(v[0] * carry, v[1] * carry));
}