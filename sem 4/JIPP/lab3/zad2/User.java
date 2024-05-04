package zad2;

import java.util.Random;

public class User<T extends ModuloField> {
    public T secret;
    public T key;
    private DHSetup<T> dhSetup;
    private boolean keySet = false;

    public User(DHSetup<T> dhSetup) {
        this.dhSetup = dhSetup;
        Random rd = new Random();
        long characteristic = T.getCharacteristic();
        long secretValue = rd.nextLong(characteristic);
        this.secret = (T) new ModuloField(secretValue);
    }

    public T getPublicKey() {
        return dhSetup.power(dhSetup.getGenerator(), secret.getValue());
    }

    public void setKey(T a) {
        key = dhSetup.power(a, secret.getValue());
        keySet = true;
    }

    public T encrypt(T m) {
        if (!keySet) {
            System.err.println("Key is not set");
        }
        return (T) ModuloField.multiply(m, key);
    }

    public T decrypt(T c) {
        if (!keySet) {
            System.err.println("Key is not set");
        }
        return (T) ModuloField.divide(c, key);
    }
}
