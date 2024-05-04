#ifndef MODULO_FIELD_H
#define MODULO_FIELD_H

#include <iostream>

class ModuloField
{
private:
    static const long characteristic = 1234567891;
    long value;

public:
    explicit ModuloField();
    explicit ModuloField(long value);

    bool operator==(const ModuloField &other) const;
    bool operator!=(const ModuloField &other) const;
    bool operator<(const ModuloField &other) const;
    bool operator<=(const ModuloField &other) const;
    bool operator>(const ModuloField &other) const;
    bool operator>=(const ModuloField &other) const;

    ModuloField operator=(const ModuloField &other);
    ModuloField operator+(const ModuloField &other) const;
    ModuloField &operator+=(const ModuloField &other);
    ModuloField operator-(const ModuloField &other) const;
    ModuloField &operator-=(const ModuloField &other);
    ModuloField operator*(const ModuloField &other) const;
    ModuloField &operator*=(const ModuloField &other);
    ModuloField operator/(const ModuloField &other) const;
    ModuloField &operator/=(const ModuloField &other);

    long getValue() const;
    static long getCharacteristic();
    operator long();

    friend std::ostream &operator<<(std::ostream &os, const ModuloField &m);
    friend std::istream& operator>> (std::istream& is, ModuloField& m);

private:
    long getInverse() const;
};

#endif /* MODULO_FIELD_H */
