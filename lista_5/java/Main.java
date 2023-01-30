import java.util.ArrayList;
import java.util.List;

class Main {

    static final int NUMBER_OF_PHILOSOPHERS = 5;

    public static void main(String[] args) {
        List<Fork> forks = new ArrayList<>();

        for (int i = 0; i < NUMBER_OF_PHILOSOPHERS; i++) {
            forks.add(new Fork(i));
        }

        List<Philosopher> philosophers = new ArrayList<>();

        for (int i = 0; i < NUMBER_OF_PHILOSOPHERS; i++) {
            philosophers.add(new Philosopher(i, forks.get(i), forks.get((i + 1) % NUMBER_OF_PHILOSOPHERS)));
        }

        for (Philosopher philosopher : philosophers) {
            philosopher.start();
        }

        try {
            for (Philosopher philosopher : philosophers) {
                philosopher.join();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("All philosophers have finished eating");
    }
}