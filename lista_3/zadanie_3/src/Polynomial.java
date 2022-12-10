import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Polynomial<T extends Field<T>> implements Comparable<Polynomial<T>> {
    private final ArrayList<T> coefficients;

    public Polynomial(ArrayList<T> coefficients) {
        while (coefficients.size() > 1 && coefficients.get(coefficients.size() - 1).compareTo(coefficients.get(coefficients.size() - 1).zero()) == 0) {
            coefficients.remove(coefficients.size() - 1);
        }

        this.coefficients = coefficients;
    }

    public Polynomial(T[] coefficients) {
        this(new ArrayList<>(Arrays.asList(coefficients)));
    }

    public Polynomial(T coefficient) {
        this(new ArrayList<>(Collections.singletonList(coefficient)));
    }

    public Polynomial() {
        this.coefficients = new ArrayList<>();
    }

    Polynomial<T> add (Polynomial<T> other) {
        ArrayList<T> result = new ArrayList<>();
        int i = 0;
        while (i < coefficients.size() && i < other.coefficients.size())
        {
            result.add(coefficients.get(i).add(other.coefficients.get(i)));
            i++;
        }
        while (i < coefficients.size())
        {
            result.add(coefficients.get(i));
            i++;
        }
        while (i < other.coefficients.size())
        {
            result.add(other.coefficients.get(i));
            i++;
        }
        return new Polynomial<>(result);
    }

    Polynomial<T> subtract (Polynomial<T> other) {
        ArrayList<T> result = new ArrayList<>();
        int i = 0;
        while (i < coefficients.size() && i < other.coefficients.size())
        {
            result.add(coefficients.get(i).subtract(other.coefficients.get(i)));
            i++;
        }
        while (i < coefficients.size())
        {
            result.add(coefficients.get(i));
            i++;
        }
        while (i < other.coefficients.size())
        {
            result.add(other.coefficients.get(i).negate());
            i++;
        }
        return new Polynomial<>(result);
    }

    Polynomial<T> multiply (Polynomial<T> other) {
        ArrayList<T> result = new ArrayList<>();

        for (int i = 0; i < this.coefficients.size() + other.coefficients.size() - 1; i++) {
            result.add(this.coefficients.get(0).zero());
        }

        for (int i = 0; i < this.coefficients.size(); i++) {
            for (int j = 0; j < other.coefficients.size(); j++) {
                result.set(i + j, result.get(i + j).add(this.coefficients.get(i).multiply(other.coefficients.get(j))));
            }
        }

        return new Polynomial<>(result);
    }

    Polynomial<T> divide (Polynomial<T> other) {
        Polynomial<T> dividend = this;
        Polynomial<T> result = new Polynomial<>();
        while (dividend.coefficients.size() >= other.coefficients.size())
        {
            T coefficient = dividend.coefficients.get(dividend.coefficients.size() - 1).divide(other.coefficients.get(other.coefficients.size() - 1));
            int degree = dividend.coefficients.size() - other.coefficients.size();
            ArrayList<T> new_coefficients = new ArrayList<>(Collections.nCopies(degree + 1, dividend.coefficients.get(0).zero()));
            new_coefficients.set(degree, coefficient);
            Polynomial<T> new_polynomial = new Polynomial<>(new_coefficients);
            result = result.add(new_polynomial);
            dividend = dividend.subtract(other.multiply(new_polynomial));
            while (dividend.coefficients.size() > 0 && dividend.coefficients.get(dividend.coefficients.size() - 1).compareTo(this.coefficients.get(0).zero()) == 0)
            {
                dividend.coefficients.remove(dividend.coefficients.size() - 1);
            }
        }
        return result;
    }

    Polynomial<T> remainder(Polynomial<T> other) {
        return this.subtract(this.divide(other).multiply(other));
    }

    Polynomial<T> negate () {
        ArrayList<T> result = new ArrayList<>();

        for (T coefficient : this.coefficients) {
            result.add(coefficient.negate());
        }

        return new Polynomial<>(result);
    }

    @Override
    public boolean equals(Object other) {
        if (other instanceof Polynomial) {
            Polynomial<T> other_polynomial = (Polynomial<T>) other;
            return this.coefficients.equals(other_polynomial.coefficients);
        }
        return false;
    }

    @Override
    public String toString () {
        if (this.coefficients.size() == 0) {
            return "0";
        }

        StringBuilder result = new StringBuilder();
        for (int i = this.coefficients.size() - 1; i >= 0; i--) {
            if (this.coefficients.get(i).compareTo(this.coefficients.get(0).zero()) != 0) {
                if (i != this.coefficients.size() - 1) {
                    result.append(" + ");
                }
                result.append(this.coefficients.get(i).toString());
                if (i != 0) {
                    result.append("x");
                    if (i != 1) {
                        result.append("^").append(i);
                    }
                }
            }
        }
        return result.toString();
    }

    public T evaluate(T x) {
        T result = this.coefficients.get(0).zero();
        for (int i = this.coefficients.size() - 1; i >= 0; i--) {
            result = result.add(this.coefficients.get(i).multiply(x.pow(i)));
        }
        return result;
    }

    @Override
    public int compareTo(Polynomial<T> o) {
        if (this.coefficients.size() != o.coefficients.size()) {
            return this.coefficients.size() - o.coefficients.size();
        }
        for (int i = this.coefficients.size() - 1; i >= 0; i--) {
            int comparison = this.coefficients.get(i).compareTo(o.coefficients.get(i));
            if (comparison != 0) {
                return comparison;
            }
        }
        return 0;
    }
}
