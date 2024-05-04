#include "User.h"

template <typename T>
User<T>::User(DHSetup<T> dh)
{
    dhSetup = dh;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, T::getCharacteristic() - 1);
    secret = T(distr(gen));
}

template <typename T>
T User<T>::getPublicKey()
{
    return dhSetup.power(dhSetup.getGenerator(), secret);
}

template <typename T>
void User<T>::setKey(T a)
{
    key = dhSetup.power(a, secret);
    keySet = true;
}

template <typename T>
T User<T>::encrypt(T m)
{
    if (!keySet)
    {
        std::cerr << "Key is not set" << std::endl;
        return T(1);
    }
    return m * key;
}

template <typename T>
T User<T>::decrypt(T c)
{
    if (!keySet)
    {
        std::cerr << "Key is not set" << std::endl;
        return T(1);
    }
    return c / key;
}

template class User<ModuloField>;