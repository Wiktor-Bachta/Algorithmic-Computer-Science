from crc import Calculator, Crc32

def main():
    symbol = "01111110"
    with open("./encoded.txt", "r") as f:
        data = f.read()
    data = data.replace("\n", "")
    symbol_indexes = []
    frames = []
    decoded = []

    i = data.find("01111110")
    while True:
        symbol_indexes.append(i)
        index = data[i + 8:].find("01111110")
        if index == -1:
            break
        i = i + 8 + index
    
    i = 0
    while i < len(symbol_indexes) - 1:
        if symbol_indexes[i + 1] - symbol_indexes[i] - 8 < 32:
            symbol_indexes.pop(i + 1)
        else:
            i += 2
        
    for i in range(0, len(symbol_indexes) - 1, 2):
        frames.append(data[symbol_indexes[i]+8:symbol_indexes[i+1]])
        
    for i, frame in enumerate(frames):
        remove_0_indexes = []
        for j in range(len(frame) - 5):
            if frame[j : j + 6] == "011111":
                remove_0_indexes.append(j + 6)
        fr = list(frame)
        for index in reversed(remove_0_indexes):
            fr.pop(index)
        frames[i] = "".join(fr)
    
    for frame in frames:
        content = frame[:-32]
        crc = frame[-32:]
        crc = int(crc, 2)

        d = int(content, 2).to_bytes((len(content) + 7) // 8, byteorder='big')
        calculator = Calculator(Crc32.CRC32)
        if calculator.verify(d, crc):
            decoded.append(content)

    with open("./decoded.txt", "w") as f:
        for content in decoded:
            f.write(content + "\n")

if __name__ == "__main__":
    main()