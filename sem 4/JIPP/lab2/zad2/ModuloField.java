package zad2;

public class ModuloField {

    static final long characteristic = 1234577;
    private long value;

    public ModuloField(long value) throws CharacteristicException {
        if (value >= characteristic || value < 0) {
            throw new CharacteristicException("value >= characteristic");
        }
        this.value = value;
    }

    public boolean equalTo(ModuloField m) {
        return value == m.getValue();
    }

    public boolean notEqualTo(ModuloField m) {
        return !equalTo(m);
    }

    public boolean lessThan(ModuloField m) {
        return value < m.getValue();
    }

    public boolean lessOrEqual(ModuloField m) {
        return !greaterThan(m);
    }

    public boolean greaterThan(ModuloField m) {
        return value > m.getValue();
    }

    public boolean greaterOrEqual(ModuloField m) {
        return !lessThan(m);
    }

    public void setTo(ModuloField m) {
        value = m.getValue();
    }

    public void add(ModuloField m) {
        value = (value + m.getValue()) % characteristic;
    }

    public static ModuloField add(ModuloField m, ModuloField n) {
        ModuloField result;
        try {
            result = new ModuloField((m.getValue() + n.getValue()) % characteristic);
        } catch (CharacteristicException e) {
            return null;
        }
        return result;
    }

    public void substract(ModuloField m) {
        value = (value - m.getValue() + characteristic) % characteristic;
    }

    public static ModuloField substract(ModuloField m, ModuloField n) {
        ModuloField result;
        try {
            result = new ModuloField((m.getValue() - n.getValue() + characteristic) % characteristic);
        } catch (CharacteristicException e) {
            return null;
        }
        return result;
    }

    public void multiply(ModuloField m) {
        value = value * m.getValue() % characteristic;
    }

    public static ModuloField multiply(ModuloField m, ModuloField n) {
        ModuloField result;
        try {
            result = new ModuloField(m.getValue() * n.getValue() % characteristic);
        } catch (CharacteristicException e) {
            return null;
        }
        return result;
    }

    public void divide(ModuloField m) {
        value = value * m.getInverse() % characteristic;
    }

    public static ModuloField divide(ModuloField m, ModuloField n) {
        ModuloField result;
        try {
            result = new ModuloField(m.getValue() * n.getInverse() % characteristic);
        } catch (CharacteristicException e) {
            return null;
        }
        return result;
    }

    public long getInverse() {

        long a = value;
        long b = characteristic;

        long x = 0;
        long y = 1;
        long u = 1;
        long v = 0;

        while (a != 0) {
            long r = b % a;
            long q = b / a;
            long m = x - u * q;
            long n = y - v * q;

            b = a;
            a = r;
            x = u;
            y = v;
            u = m;
            v = n;
        }

        return (x % characteristic + characteristic) % characteristic;
    }

    public long getValue() {
        return value;
    }

    public static long getCharacteristic() {
        return characteristic;
    }
}
