package zad2;

public class Test {
    public static void main(String[] args) {
        DHSetup<ModuloField> dhSetup = new DHSetup<>();

        User<ModuloField> alice = new User<>(dhSetup);
        User<ModuloField> bob = new User<>(dhSetup);

        alice.setKey(bob.getPublicKey());
        bob.setKey(alice.getPublicKey());

        ModuloField m = new ModuloField(123);
        ModuloField c = alice.encrypt(m);
        ModuloField decrypted = bob.decrypt(c);

        System.out.println(alice.secret.getValue() + " " + alice.key.getValue() + " " + bob.secret.getValue() + " " + bob.key.getValue() + " " + dhSetup.getGenerator().getValue());
        System.out.println("Message: " + m.getValue());
        System.out.println("Encrypted: " + c.getValue());
        System.out.println("Decrypted: " + decrypted.getValue());
    }
}
