#include "ModuloField.h"
#include "CharacteristicException.h"
#include <iostream>
#include <cassert>

int main()
{
    try
    {
        // Larger numbers for demonstration
        ModuloField a(123456);
        ModuloField b(987654);
        ModuloField c(654321);

        std::cout << "Value of a: " << a.getValue() << std::endl;
        std::cout << "Value of b: " << b.getValue() << std::endl;
        std::cout << "Value of c: " << c.getValue() << std::endl;

        // Testing mathematical operations
        ModuloField resultAdd = a + b;
        assert(resultAdd.getValue() == 1111110);
        std::cout << "\nAddition:\n"
                  << a.getValue() << " + " << b.getValue() << " = " << resultAdd.getValue() << std::endl;

        ModuloField resultSub = c - b;
        assert(resultSub.getValue() == 901244);
        std::cout << "\nSubtraction:\n"
                  << c.getValue() << " - " << b.getValue() << " = " << resultSub.getValue() << std::endl;

        ModuloField resultMul = a * c;
        assert(resultMul.getValue() == 245689);
        std::cout << "\nMultiplication:\n"
                  << a.getValue() << " * " << c.getValue() << " = " << resultMul.getValue() << std::endl;

        ModuloField resultDiv = c / b;
        assert(resultDiv.getValue() == 1180971);
        std::cout << "\nDivision:\n"
                  << c.getValue() << " / " << b.getValue() << " = " << resultDiv.getValue() << std::endl;

        // Testing equality and comparisons
        std::cout << "\nEquality Test:" << std::endl;
        assert(a == a);
        assert(!(a == b));

        std::cout << "\nComparison Test:" << std::endl;
        assert(a < b);
        assert(!(a > c));
        assert(a <= b);
        assert(!(a >= c));

        std::cout << "\nStream test:" << std::endl;

        std::cout << a << std::endl;

        ModuloField d;
        std::cin >> d;
        std::cout << d << std::endl;

        std::cout << "All assertions passed." << std::endl;
    }
    catch (const CharacteristicException &e)
    {
        std::cerr << "CharacteristicException: " << e.what() << std::endl;
    }

    return 0;
}
