public class DoubleField implements Field<DoubleField> {

    private final double value;

    public DoubleField(double value) {
        this.value = value;
    }

    @Override
    public DoubleField add(DoubleField other) {
        return new DoubleField(this.value + other.value);
    }

    @Override
    public DoubleField subtract(DoubleField other) {
        return new DoubleField(this.value - other.value);
    }

    @Override
    public DoubleField multiply(DoubleField other) {
        return new DoubleField(this.value * other.value);
    }

    @Override
    public DoubleField divide(DoubleField other) {
        return new DoubleField(this.value / other.value);
    }

    @Override
    public DoubleField zero() {
        return new DoubleField(0);
    }

    @Override
    public DoubleField one() {
        return new DoubleField(1);
    }

    @Override
    public DoubleField negate() {
        return new DoubleField(-value);
    }

    @Override
    public DoubleField pow(long exponent) {
        return new DoubleField(Math.pow(value, exponent));
    }

    @Override
    public DoubleField inverse() {
        return new DoubleField(1 / value);
    }

    @Override
    public int compareTo(DoubleField o) {
        return Double.compare(value, o.value);
    }

    @Override
    public String toString() {
        return Double.toString(value);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof DoubleField other) {
            return this.value == other.value;
        }
        return super.equals(obj);
    }
}
