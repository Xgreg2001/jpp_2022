public class FiniteField implements Comparable<FiniteField> {
    private final long p;
    private final long value;

    private static long betterMod(long a, long p) {
        long result = a % p;
        if (result < 0) {
            result += p;
        }
        return result;
    }

    private static long betterPow(long a, long b, long p) {
        long result = 1;
        while (b > 0) {
            if (b % 2 == 1) {
                result = betterMod(result * a, p);
            }
            a = betterMod(a * a, p);
            b /= 2;
        }
        return result;
    }

    public FiniteField(long value, long prime) {
        if (!isPrime(prime)){
            throw new IllegalArgumentException("The number is not prime");
        }
        this.p = prime;
        this.value = betterMod(value, p);
    }

    private static boolean isPrime(long p) {
        if (p == 2) {
            return true;
        }
        if (p % 2 == 0) {
            return false;
        }
        for (long i = 3; i * i <= p; i += 2) {
            if (p % i == 0) {
                return false;
            }
        }
        return true;
    }

    public long getValue() {
        return value;
    }

    public FiniteField add(FiniteField other) {
        if (p != other.p) {
            throw new IllegalArgumentException("The numbers are not from the same field");
        }
        return new FiniteField(this.value + other.getValue(), p);
    }

    public FiniteField subtract(FiniteField other) {
        if (p != other.p) {
            throw new IllegalArgumentException("The numbers are not from the same field");
        }
        return new FiniteField(this.value - other.getValue(), p);
    }

    public FiniteField multiply(FiniteField other) {
        if (p != other.p) {
            throw new IllegalArgumentException("The numbers are not from the same field");
        }
        return new FiniteField(this.value * other.getValue(), p);
    }

    public FiniteField inverse() {
        if (this.value == 0) {
            throw new ArithmeticException("Division by zero");
        }
        return new FiniteField(betterPow(this.value, p - 2, p), p);
    }

    public FiniteField divide(FiniteField other) throws ArithmeticException {
        if (p != other.p) {
            throw new IllegalArgumentException("The numbers are not from the same field");
        }
        if (other.getValue() == 0) {
            throw new ArithmeticException("Division by zero");
        }
        return this.multiply(other.inverse());
    }

    public FiniteField pow(int exponent) {
        return new FiniteField(betterPow(this.value, exponent, p), p);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof FiniteField other) {
            if (p != other.p) {
                return false;
            }
            return this.value == other.getValue();
        }

        return super.equals(obj);
    }

    @Override
    public String toString() {
        return String.valueOf(value);
    }

    @Override
    public int compareTo(FiniteField o) {
        if (p != o.p) {
            throw new IllegalArgumentException("The numbers are not from the same field");
        }
        return Long.compare(this.value, o.getValue());
    }

}
