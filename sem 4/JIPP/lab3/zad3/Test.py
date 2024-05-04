from ModuloField import ModuloField
from DHSetup import DHSetup
from User import User

def main():
    dh_setup = DHSetup[ModuloField]()
    alice = User(dh_setup)
    bob = User(dh_setup)

    alice.set_key(bob.get_public_key())
    bob.set_key(alice.get_public_key())

    m = ModuloField(123)
    c = alice.encrypt(m)
    decrypted = bob.decrypt(c)

    print("Message:", m.get_value())
    print("Encrypted:", c.get_value())
    print("Decrypted:", decrypted.get_value())

if __name__ == "__main__":
    main()