from CharacteristicException import CharacteristicException


class ModuloField:
    characteristic = 1234577

    def __init__(self, value):
        if value >= ModuloField.characteristic or value < 0:
            raise CharacteristicException("Value must be in range [0, characteristic).")
        self.value = value

    def __eq__(self, other):
        return self.value == other.value

    def __ne__(self, other):
        return self.value != other.value

    def __lt__(self, other):
        return self.value < other.value

    def __le__(self, other):
        return self.value <= other.value

    def __gt__(self, other):
        return self.value > other.value

    def __ge__(self, other):
        return self.value >= other.value

    def __add__(self, other):
        return ModuloField((self.value + other.value) % ModuloField.characteristic)

    def __iadd__(self, other):
        self.value = (self.value + other.value) % ModuloField.characteristic
        return self

    def __sub__(self, other):
        return ModuloField((self.value - other.value + ModuloField.characteristic) % ModuloField.characteristic)

    def __isub__(self, other):
        self.value = (self.value - other.value + ModuloField.characteristic) % ModuloField.characteristic
        return self

    def __mul__(self, other):
        return ModuloField((self.value * other.value) % ModuloField.characteristic)

    def __imul__(self, other):
        self.value = (self.value * other.value) % ModuloField.characteristic
        return self

    def __truediv__(self, other):
        return ModuloField((self.value * self.get_inverse(other.value)) % ModuloField.characteristic)

    def __itruediv__(self, other):
        self.value = (self.value * self.get_inverse(other.value)) % ModuloField.characteristic
        return self

    def get_value(self):
        return self.value

    @staticmethod
    def get_characteristic():
        return ModuloField.characteristic

    def get_inverse(self, value):
        a = value
        b = ModuloField.characteristic
        x, y, u, v = 0, 1, 1, 0

        while a != 0:
            r = b % a
            q = b // a
            m = x - u * q
            n = y - v * q

            b = a
            a = r
            x = u
            y = v
            u = m
            v = n

        return (x % ModuloField.characteristic + ModuloField.characteristic) % ModuloField.characteristic