from crc import Calculator, Crc32

def main():
    symbol = "01111110"
    content_length = 50
    frames = []
    with open("./data.txt", "r") as f:
        data = f.read()
    data = data.replace("\n", "")

    for i in range(0, len(data), content_length):
        content = data[i : i + content_length]

        # crc
        d = int(content, 2).to_bytes((len(content) + 7) // 8, byteorder='big')
        calculator = Calculator(Crc32.CRC32)
        crc = format(calculator.checksum(d), '032b')

        content = content + crc

        # padding with zeroes
        content = list(content)
        j = 0
        while j < len(content) - 5:
            if content[j : j + 6] == list("011111"):
                content.insert(j + 6, "0")
            j += 1
        content = "".join(content)

        final = symbol + content + symbol
        frames.append(final)

    with open("./encoded.txt", "w") as f:
        for frame in frames:
            f.write(frame + "\n")

if __name__ == "__main__":
    main()
