from crc import Calculator, Crc32


calculator = Calculator(Crc32.CRC32)
l = [int(i) for i in "10101010101"]
# data = bytes(l)
data = "0b10101010101"
print(f"{calculator.checksum(data)}")
