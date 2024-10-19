public class Philosopher implements Runnable {
    private final int id;
    private final Fork leftFork;
    private final Fork rightFork;
    private final boolean isLeftHanded;
    private final int mealsToEat;

    public Philosopher(int id, Fork leftFork, Fork rightFork, boolean isLeftHanded, int mealsToEat) {
        this.id = id;
        this.leftFork = leftFork;
        this.rightFork = rightFork;
        this.isLeftHanded = isLeftHanded;
        this.mealsToEat = mealsToEat;
    }

    @Override
    public void run() {
        int mealsEaten = 0;
        while (mealsEaten < mealsToEat) {
            try {
                // Determine which fork to pick up first based on handedness
                Fork firstFork = isLeftHanded ? leftFork : rightFork;
                Fork secondFork = isLeftHanded ? rightFork : leftFork;

                // Try to pick up both forks
                System.out.println("Philosopher " + id + " picks up first fork.");
                firstFork.pickUp();
                System.out.println("Philosopher " + id + " picks up second fork.");
                secondFork.pickUp();

                // Eat
                System.out.println("Philosopher " + id + " is eating.");
                mealsEaten++;

                // Put down both forks
                System.out.println("Philosopher " + id + " puts down first fork.");
                firstFork.putDown();
                System.out.println("Philosopher " + id + " puts down second fork.");
                secondFork.putDown();

                // Think
                System.out.println("Philosopher " + id + " is thinking.");
                Thread.sleep((long) (Math.random() * 1000)); // Simulate thinking
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Philosopher " + id + " has finished meals.");
    }
}
