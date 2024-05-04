from ModuloField import ModuloField, CharacteristicException

def main():
    try:
        # Larger numbers for demonstration
        a = ModuloField(123456)
        b = ModuloField(987654)
        c = ModuloField(654321)

        print("Value of a:", a.get_value())
        print("Value of b:", b.get_value())
        print("Value of c:", c.get_value())

        # Testing mathematical operations
        result_add = a + b
        assert result_add.get_value() == 1111110
        print("\nAddition:")
        print(f"{a.get_value()} + {b.get_value()} = {result_add.get_value()}")

        result_sub = c - b
        assert result_sub.get_value() == 901244
        print("\nSubtraction:")
        print(f"{c.get_value()} - {b.get_value()} = {result_sub.get_value()}")

        result_mul = a * c
        assert result_mul.get_value() == 245689
        print("\nMultiplication:")
        print(f"{a.get_value()} * {c.get_value()} = {result_mul.get_value()}")

        result_div = c / b
        assert result_div.get_value() == 1180971
        print("\nDivision:")
        print(f"{c.get_value()} / {b.get_value()} = {result_div.get_value()}")

        # Testing equality and comparisons
        print("\nEquality Test:")
        assert a == a
        assert not (a == b)

        print("\nComparison Test:")
        assert a < b
        assert not (a > c)
        assert a <= b
        assert not (a >= c)

        print("All assertions passed.")

    except CharacteristicException as e:
        print("CharacteristicException:", e)

if __name__ == "__main__":
    main()
