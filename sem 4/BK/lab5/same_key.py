from rc4 import RC4
from random import randint


def same_key(C1: list[int], C2: list[int]) -> bool:
    C1 = [ord(i) for i in C1]
    C2 = [ord(i) for i in C2]

    xored = [C1[i] ^ C2[i] for i in range(min(len(C1), len(C2)))]

    # if K1 = K2
    # C1 ^ C2 = M1 ^ K1 ^ M2 ^ K2 = M1 ^ M2
    # so first bit of all bytes in C1 ^ C2 should be 0
    # (provided used ascii characters 0-127)
    for i in xored:
        if i > 127:
            return False
    return True


def main():

    M1 = list("some message")
    M2 = list("other stuff")
    M3 = list("third text")

    K1 = [randint(0, 256) for _ in range(40)]
    K2 = [randint(0, 256) for _ in range(40)]

    C1 = RC4(K1, M1)
    C2 = RC4(K1, M2)
    C3 = RC4(K2, M3)

    print(f"{same_key(C1, C2)} (expected: True)")
    print(f"{same_key(C1, C3)} (expected: False)")


if __name__ == "__main__":
    main()
