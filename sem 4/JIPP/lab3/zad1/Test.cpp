#include "ModuloField.h"
#include "DHSetup.h"
#include "User.h"
#include "CharacteristicException.h"
#include <iostream>
#include <cassert>

int main()
{
    DHSetup<ModuloField> dhSetup = DHSetup<ModuloField>();

    User<ModuloField> alice = User(dhSetup);
    User<ModuloField> bob = User(dhSetup);

    alice.setKey(bob.getPublicKey());
    bob.setKey(alice.getPublicKey());

    ModuloField m = ModuloField(123);
    ModuloField c = alice.encrypt(m);
    ModuloField decrypted = bob.decrypt(c);

    std::cout << "Message: " << m << std::endl;
    std::cout << "Encrypted: " << c << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}
