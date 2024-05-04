def main():
    symbol = "01111110"
    with open("./encoded.txt", "r") as f:
        data = f.read()
    symbol_indexes = []
    frames = []
    encoded_frames = []
    frame_started = False

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
            symbol_indexes.remove(i + 1)
        else:
            i += 1


    with open("./decoded.txt", "w") as f:
        for frame in encoded_frames:
            f.write(frame)

if __name__ == "__main__":
    main()