#ifndef USER_h
#define USER_h

#include "DHSetup.h"
#include "ModuloField.h"

template <typename T>
class User
{
public:
    T secret;
    T key;
    DHSetup<T> dhSetup;
    bool keySet = false;
public:
    User(DHSetup<T> dhSetup);
    T getPublicKey();
    void setKey(T a);
    T encrypt(T m);
    T decrypt(T c);
};

#endif /* USER_h */