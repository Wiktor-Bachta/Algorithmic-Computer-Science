from typing import TypeVar, Generic
from random import randint
from ModuloField import ModuloField

T = TypeVar('T')

class DHSetup(Generic[T]):
    def __init__(self) -> None:
        self.generator = None
        divisors = [i for i in range(2, ModuloField.characteristic - 1) if (ModuloField.characteristic - 1) % i == 0]
        prime_divisors = [d for d in divisors if all(d % j != 0 for j in range(2, int(d**0.5) + 1))]
        while True:
            self.generator = ModuloField(randint(1, ModuloField.characteristic - 1))
            if self.generator_ok(prime_divisors):
                break

    def generator_ok(self, prime_divisors: list[int]) -> bool:
        for prime_divisor in prime_divisors:
            if self.power(self.generator, (ModuloField.characteristic - 1) // prime_divisor) == ModuloField(1):
                return False
        return True

    def get_generator(self) -> T:
        return self.generator

    @staticmethod
    def power(a: ModuloField, b: int) -> ModuloField:
        result = ModuloField(1)
        while b > 0:
            if b % 2 == 1:
                result = result * a
            a = a * a
            b //= 2
        return result