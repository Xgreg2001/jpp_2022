public class FiniteField {
    private static final int p = 1234567891;
    private final long value;

    private static long betterMod(long a) {
        long result = a % (long) FiniteField.p;
        if (result < 0) {
            result += FiniteField.p;
        }
        return result;
    }

    private static long betterPow(long a, long b) {
        long result = 1;
        while (b > 0) {
            if (b % 2 == 1) {
                result = betterMod(result * a);
            }
            a = betterMod(a * a);
            b /= 2;
        }
        return result;
    }

    public FiniteField(long value) {
        this.value = value % p;
    }
    public long getValue() {
        return value;
    }

    public FiniteField add(FiniteField other) {
        return new FiniteField(betterMod(this.value + other.getValue()));
    }

    public FiniteField subtract(FiniteField other) {
        return new FiniteField(betterMod(this.value - other.getValue()));
    }

    public FiniteField multiply(FiniteField other) {
        return new FiniteField(betterMod(this.value * other.getValue()));
    }

    public FiniteField inverse() {
        return new FiniteField(betterPow(this.value, p - 2));
    }

    public FiniteField divide(FiniteField other) {
        return this.multiply(other.inverse());
    }

    public FiniteField pow(int exponent) {
        return new FiniteField(betterPow(this.value, exponent));
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof FiniteField other) {
            return this.value == other.getValue();
        }

        return super.equals(obj);
    }

    public boolean lessThan(FiniteField other) {
        return this.value < other.getValue();
    }

    public boolean greaterThan(FiniteField other) {
        return this.value > other.getValue();
    }

    public boolean lessThanOrEqual(FiniteField other) {
        return this.value <= other.getValue();
    }

    public boolean greaterThanOrEqual(FiniteField other) {
        return this.value >= other.getValue();
    }

    public boolean notEqual(FiniteField other) {
        return this.value != other.getValue();
    }

    @Override
    public String toString() {
        return String.valueOf(value);
    }

    public static FiniteField fromString(String str) {
        return new FiniteField(Long.parseLong(str));
    }



}
