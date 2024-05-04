#include "ModuloField.h"
#include "CharacteristicException.h"

ModuloField::ModuloField()
{
}

ModuloField::ModuloField(long value)
{
    if (value >= characteristic || value < 0)
    {
        throw CharacteristicException("Value must be in range [0, characteristic).");
    }
    this->value = value;
}

bool ModuloField::operator==(const ModuloField &other) const
{
    return value == other.value;
}

bool ModuloField::operator!=(const ModuloField &other) const
{
    return value != other.value;
}

bool ModuloField::operator<(const ModuloField &other) const
{
    return value < other.value;
}

bool ModuloField::operator<=(const ModuloField &other) const
{
    return value <= other.value;
}

bool ModuloField::operator>(const ModuloField &other) const
{
    return value > other.value;
}

bool ModuloField::operator>=(const ModuloField &other) const
{
    return value >= other.value;
}

ModuloField ModuloField::operator=(const ModuloField &other)
{
    this->value = other.value;
    return *this;
}

ModuloField ModuloField::operator+(const ModuloField &other) const
{
    return ModuloField(value + other.value);
}

ModuloField &ModuloField::operator+=(const ModuloField &other)
{
    this->value += other.value;
    this->value %= characteristic;
    return *this;
}

ModuloField ModuloField::operator-(const ModuloField &other) const
{
    return ModuloField((value - other.value + characteristic) % characteristic);
}

ModuloField &ModuloField::operator-=(const ModuloField &other)
{
    this->value -= other.value;
    this->value = (this->value + characteristic) % characteristic;
    return *this;
}

ModuloField ModuloField::operator*(const ModuloField &other) const
{
    return ModuloField(value * other.value % characteristic);
}

ModuloField &ModuloField::operator*=(const ModuloField &other)
{
    this->value *= other.value;
    this->value %= characteristic;
    return *this;
}

ModuloField ModuloField::operator/(const ModuloField &other) const
{
    return ModuloField(value * other.getInverse() % characteristic);
}

ModuloField &ModuloField::operator/=(const ModuloField &other)
{
    this->value *= other.getInverse();
    this->value %= characteristic;
    return *this;
}

ModuloField::operator long() {
    return value;
}

long ModuloField::getValue() const
{
    return value;
}

long ModuloField::getCharacteristic()
{
    return characteristic;
}

long ModuloField::getInverse() const
{
    long a = value;
    long b = characteristic;
    long x = 0;
    long y = 1;
    long u = 1;
    long v = 0;

    while (a != 0)
    {
        long r = b % a;
        long q = b / a;
        long m = x - u * q;
        long n = y - v * q;

        b = a;
        a = r;
        x = u;
        y = v;
        u = m;
        v = n;
    }

    return (x % characteristic + characteristic) % characteristic;
}

std::ostream &operator<<(std::ostream &os, const ModuloField &m)
{
    os << m.getValue();
    return os;
}

std::istream &operator>>(std::istream &is, ModuloField &m)
{
    is >> m.value;
    return is;
}