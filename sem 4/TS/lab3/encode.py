def main():
    symbol = "01111110"
    content_length = 80
    frames = []
    with open("./data.txt", "r") as f:
        data = f.read()

    for i in range(0, len(data), content_length):
        content = data[i : i + content_length]
        add_0_indexes = []
        for j in range(len(content) - 5):
            if content[j : j + 6] == "011111":
                add_0_indexes.append(j + 6)
        content = list(content)
        for index in reversed(add_0_indexes):
            content.insert(index, "0")
        content = symbol + "".join(content) + symbol
        frames.append(content)
        print(content)

    with open("./encoded.txt", "w") as f:
        for frame in frames:
            f.write(frame)

if __name__ == "__main__":
    main()
