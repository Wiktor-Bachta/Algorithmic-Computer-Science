from random import uniform

with open("./data.txt", "w") as f:
    for _ in range(500):
        bit = "1" if uniform(0, 1) < 0.5 else "0"
        f.write(bit)