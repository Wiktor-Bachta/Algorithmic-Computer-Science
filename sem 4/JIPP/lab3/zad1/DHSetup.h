#ifndef DH_SETUP_h
#define DH_SETUP_h

#include <vector>
#include <random>
#include <iostream>
#include <cmath>

template <typename T>
class DHSetup
{
private:
    T generator;

public:
    DHSetup();
    T getGenerator() const;
    T power(T a, unsigned long b);
private:
    bool generatorOk(std::vector<long> primeDivisors);
};

#endif /* DH_SETUP_H */