package zad2;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class DHSetup<T extends ModuloField> {

    private T generator;

    public DHSetup() {
        long characteristic = ModuloField.getCharacteristic();
        Random rd = new Random();
        long generatorValue;

        List<Long> divisors = new ArrayList<>();
        for (long i = 2; i * i < characteristic - 1; i++) {
            if ((characteristic - 1) % i == 0) {
                divisors.add(i);
            }
        }

        int s = divisors.size();
        for (int i = 0; i < s; i++) {
            divisors.add((characteristic - 1) / divisors.get(i));
        }

        List<Long> primeDivisors = new ArrayList<>();
        for (int i = 0; i < divisors.size(); i++) {
            boolean isPrime = true;
            for (int j = 2; j * j <= divisors.get(i); j++) {
                if (divisors.get(i) % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                primeDivisors.add(divisors.get(i));
            }
        }

        do {
            generatorValue = rd.nextLong(characteristic - 1) + 1;
            generator = (T) new ModuloField(generatorValue);
        } while (!generatorOk(primeDivisors));
    }

    private boolean generatorOk(List<Long> primeDivisors) {
        for (long primeDivisor : primeDivisors) {
            if (power(generator, (T.getCharacteristic() - 1) / primeDivisor).equals((T) new ModuloField(1))) {
                return false;
            }
        }
        return true;
    }

    public T getGenerator() {
        return generator;
    }

    public T power(T a, long b) {
        T result = (T) new ModuloField(1);
        while (b > 0) {
            if (b % 2 == 1) {
                result = (T) ModuloField.multiply(result, a);
            }
            a = (T) ModuloField.multiply(a, a);
            b /= 2;
        }
        return result;
    }
}

