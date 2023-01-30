import java.util.List;
import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

class Philosopher extends Thread {

    private static final int MAX_THINKING_TIME = 1000;
    private static final int MAX_EATING_TIME = 500;
    private static final int MAX_MEALS = 10;
    private long meals = 0;
    private Random random = ThreadLocalRandom.current();
    private final long id;
    private final Fork left;
    private final Fork right;

    public Philosopher(long id, Fork left, Fork right) {
        this.id = id;
        this.left = left;
        this.right = right;
    }

    public void run() {
        while (meals < MAX_MEALS) {
            think();
            eat();
        }
    }

    private synchronized void eat() {
        safePrintln("Philosopher " + id + " is hungry");

        left.request(id);
        right.request(id);

        safePrintln("Philosopher " + id + " is eating");

        try {
            Thread.sleep(random.nextInt(MAX_EATING_TIME));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        left.release();
        right.release();

        meals++;

        safePrintln("Philosopher " + id + " has eaten " + meals + " meals");
    }

    private void think() {
        safePrintln("Philosopher " + id + " is thinking");
        try {
            Thread.sleep(random.nextInt(MAX_THINKING_TIME));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    private void safePrintln(String s) {
        synchronized (System.out) {
            System.out.println(s);
        }
    }

}