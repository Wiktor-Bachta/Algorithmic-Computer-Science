from random import randint
from rc4 import RC4
import itertools

# 48 - 57
# 110000
# 110001
# 110010
# 110011
# 110100
# 110101
# 110110
# 110111
# 111000
# 111001
# so only last 4 bit matter 

st = list(itertools.product([0, 1], repeat=5))

def xor(A, B):
    return [A[i] ^ B[i] for i in range(min(len(A), len(B)))]

def generate_account_number():
    return "".join([str(randint(0, 9)) for _ in range(26)])

def get_possible_maps(numbers, map):
    mp = {number: [] for number in numbers}
    c = []
    for i, num in enumerate(numbers):
        b = set()
        for num in numbers:
            b.add(num ^ numbers[i])
        c.append(b)
    for k, v in map.items():
        for i, s in enumerate(c):
            if v == s:
                mp[numbers[i]].append(k)
    print(mp)
    return mp

def main():
    account_numbers = []
    encrypted = []
    decrypted = []
    digit_xors = [{i ^ j for i in range(48, 58)} for j in range(48, 58)]
    map = {i: v for i,v in enumerate(digit_xors)}

    K = [randint(0, 255) for _ in range(40)]
    for _ in range(40):
        account_numbers.append(generate_account_number())
    for number in account_numbers:
        byte_representation = [ord(i) for i in number]
        encrypted.append(RC4(K, byte_representation))
        decrypted.append([0 for _ in range(26)])
    for i in range(1):
        curr = set()
        for number in encrypted:
            curr.add(number[i])
        mp = get_possible_maps(list(curr), map)
    

if __name__ == "__main__":
    main()