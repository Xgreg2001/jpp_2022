public interface Field<T> extends Comparable<T> {
    T add(T other);
    T subtract(T other);
    T multiply(T other);
    T divide(T other);
    T zero();
    T one();
    T negate();
    T pow(long exponent);
    T inverse();
}
