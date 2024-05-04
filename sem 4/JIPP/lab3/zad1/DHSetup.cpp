#include "DHSetup.h"
#include "ModuloField.h"

template <typename T>
DHSetup<T>::DHSetup()
{
    long characteristic = T::getCharacteristic();
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, characteristic - 1); 

    std::vector<long> divisors = std::vector<long>();
    for (int i = 2; i * i < characteristic - 1 ; i++)
    {
        if ((characteristic - 1) % i == 0)
        {
            divisors.push_back(i);
        }
    }

    int s = divisors.size();
    for (int i = 0; i < s; i++)
    {
        divisors.push_back((characteristic - 1) / divisors[i]);
    }

    std::vector<long> primeDivisors = std::vector<long>();
    for (int i = 0; i < int(divisors.size()); i++)
    {
        bool isPrime = true;
        for (int j = 2; j * j <= divisors[i]; j++)
        {
            if (divisors[i] % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            primeDivisors.push_back(divisors[i]);
        }
    }

    while (true)
    {
        generator = ModuloField(distr(gen));
        if (generatorOk(primeDivisors))
        {
            break;
        }
    }

}

template <typename T>
bool DHSetup<T>::generatorOk(std::vector<long> primeDivisors)
{
    int s = primeDivisors.size();
    for (int i = 0; i < s; i++)
    {
        if (power(generator, (T::getCharacteristic() - 1) / primeDivisors[i]) == 1)
        {
            return false;
        }
    }
    return true;
}

template <typename T>
T DHSetup<T>::getGenerator() const
{
    return generator;
}

template <typename T>
T DHSetup<T>::power(T a, unsigned long b)
{
    T result = T(1);
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result *= a;
        }
        a *= a;
        b /= 2;
    }
    return result;
}
