from typing import TypeVar, Generic
from random import randint
from ModuloField import ModuloField
from DHSetup import DHSetup

T = TypeVar('T')

class User(Generic[T]):
    def __init__(self, dh_setup: DHSetup[T]) -> None:
        self.secret = ModuloField(randint(1, ModuloField.characteristic - 1))
        self.key = None
        self.key_set = False
        self.dh_setup = dh_setup

    def get_public_key(self) -> T:
        return self.dh_setup.power(self.dh_setup.get_generator(), self.secret.get_value())

    def set_key(self, a: T) -> None:
        self.key = self.dh_setup.power(a, self.secret.get_value())
        self.key_set = True

    def encrypt(self, m: ModuloField) -> ModuloField:
        if not self.key_set:
            print("Key is not set")
            return ModuloField(1)  
        return m * self.key

    def decrypt(self, c: ModuloField) -> ModuloField:
        if not self.key_set:
            print("Key is not set")
            return ModuloField(1)  
        return c / self.key