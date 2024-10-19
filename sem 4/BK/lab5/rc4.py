from random import randint


def KSA(K: list[int]) -> list[int]:
    n = len(K)
    j = 0
    # tablica T - 256 elementow (powtarzane bajty klucza)
    T = [K[i % n] for i in range(256)]
    # S na tablica postaci S[0]=0, S[1]=1, ..., S[255]=255
    S = list(range(256))
    # generuj permutacje tablicy S na podstawie klucza
    for i in range(256):
        j = (j + S[i] + T[i]) % 256
        S[i], S[j] = S[j], S[i]  # zamien S[i] z S[j]
    return S


def PRGA(S: list[int], m: int) -> list[int]:
    i = 0
    j = 0
    KS = [0 for _ in range(m)]
    for b in range(m):
        i = (i + 1) % 256
        j = (j + S[i]) % 256
        S[i], S[j] = S[j], S[i]
        KS[b] = S[(S[i] + S[j]) % 256]
    return KS


def RC4(K: list[int], M: list[int]) -> list[int]:
    m = len(M)
    S = KSA(K)
    KS = PRGA(S, m)
    return [M[i] ^ KS[i] for i in range(m)]


def main():
    detected = 0
    for i in range(1000):
        M = [ord(i) for i in list("sibqo")]
        M2 = [ord(i) for i in list("aanl7")]
        K = [randint(0, 255) for _ in range(32)]  # K też jest z bajtów
        K2 = K.copy()
        K2[15] += 1
        enc = RC4(K, M)
        dec = RC4(K, enc)
        enc2 = RC4(K2, M2)
        
        #print("".join([chr(i) for i in M]))
        xored = [enc[i] ^ enc2[i] for i in range(min(len(enc), len(enc2)))]
        same = True
        for i in xored:
            if i > 127:
                same = False
        if not same:
            detected += 1
        
    print(detected/1000)

    #print("".join([chr(i) for i in dec]))


if __name__ == "__main__":
    main()
