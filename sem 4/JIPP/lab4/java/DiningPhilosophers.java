public class DiningPhilosophers {

    public static void main(String[] args) {
        int numberOfPhilosophers = 5;
        int mealsToEat = 3;

        Fork[] forks = new Fork[numberOfPhilosophers];
        Philosopher[] philosophers = new Philosopher[numberOfPhilosophers];

        // Initialize forks
        for (int i = 0; i < numberOfPhilosophers; i++) {
            forks[i] = new Fork();
        }

        // Initialize philosophers
        for (int i = 0; i < numberOfPhilosophers; i++) {
            // Determine if philosopher is left-handed or right-handed
            boolean isLeftHanded = i % 2 == 0; // alternate between left-handed and right-handed
            philosophers[i] = new Philosopher(i, forks[i], forks[(i + 1) % numberOfPhilosophers], isLeftHanded, mealsToEat);
            new Thread(philosophers[i]).start();
        }
    }
}
