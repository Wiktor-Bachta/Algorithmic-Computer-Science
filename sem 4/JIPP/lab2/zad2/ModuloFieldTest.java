package zad2;

public class ModuloFieldTest {
    public static void main(String[] args) {
        try {
            // Larger numbers for demonstration
            ModuloField a = new ModuloField(123456);
            ModuloField b = new ModuloField(987654);
            ModuloField c = new ModuloField(654321);

            System.out.println("Value of a: " + a.getValue());
            System.out.println("Value of b: " + b.getValue());
            System.out.println("Value of c: " + c.getValue());

            // Testing mathematical operations
            ModuloField resultAdd = ModuloField.add(a, b);
            assert resultAdd != null && resultAdd.getValue() == 1111110;
            System.out.println("\nAddition:");
            System.out.println(a.getValue() + " + " + b.getValue() + " = " + resultAdd.getValue());

            ModuloField resultSub = ModuloField.substract(c, b);
            assert resultSub != null && resultSub.getValue() == 901244;
            System.out.println("\nSubtraction:");
            System.out.println(c.getValue() + " - " + b.getValue() + " = " + resultSub.getValue());

            ModuloField resultMul = ModuloField.multiply(a, c);
            assert resultMul != null && resultMul.getValue() == 245689;
            System.out.println("\nMultiplication:");
            System.out.println(a.getValue() + " * " + c.getValue() + " = " + resultMul.getValue());

            ModuloField resultDiv = ModuloField.divide(c, b);
            assert resultDiv != null && resultDiv.getValue() == 1180971;
            System.out.println("\nDivision:");
            System.out.println(c.getValue() + " / " + b.getValue() + " = " + resultDiv.getValue());

            // Testing equality and comparisons
            System.out.println("\nEquality Test:");
            assert a.equalTo(a);
            assert !a.equalTo(b);

            System.out.println("\nComparison Test:");
            assert a.lessThan(b);
            assert !a.greaterThan(c);
            assert a.lessOrEqual(b);
            assert !a.greaterOrEqual(c);

            System.out.println("All assertions passed.");
        } catch (CharacteristicException e) {
            System.out.println("CharacteristicException: " + e.getMessage());
        }
    }
}
