import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        test_DoubleField();

        test_FiniteField();
    }

    private static void test_FiniteField() {
        ArrayList<FiniteField> coefficients = new ArrayList<>();
        coefficients.add(new FiniteField(1, 2));
        coefficients.add(new FiniteField(0, 2));
        coefficients.add(new FiniteField(1, 2));
        coefficients.add(new FiniteField(1, 2));
        Polynomial<FiniteField> polynomial = new Polynomial<>(coefficients);

        ArrayList<FiniteField> coefficients2 = new ArrayList<>();
        coefficients2.add(new FiniteField(1, 2));
        coefficients2.add(new FiniteField(1, 2));
        Polynomial<FiniteField> polynomial2 = new Polynomial<>(coefficients2);

        assert(polynomial.add(polynomial2).equals(new Polynomial<>(new ArrayList<>(List.of(new FiniteField(0, 2), new FiniteField(1, 2), new FiniteField(1, 2), new FiniteField(1, 2))))));
        assert(polynomial.subtract(polynomial2).equals(new Polynomial<>(new ArrayList<>(List.of(new FiniteField(0, 2), new FiniteField(1, 2), new FiniteField(1, 2), new FiniteField(1, 2))))));
        assert(polynomial.multiply(polynomial2).equals(new Polynomial<>(new ArrayList<>(List.of(new FiniteField(1, 2), new FiniteField(1, 2), new FiniteField(1, 2), new FiniteField(0, 2), new FiniteField(1, 2))))));
        assert(polynomial.divide(polynomial2).equals(new Polynomial<>(new ArrayList<>(List.of(new FiniteField(0, 2), new FiniteField(0, 2), new FiniteField(1, 2))))));
        assert(polynomial.remainder(polynomial2).equals(new Polynomial<>(new ArrayList<>(List.of(new FiniteField(1, 2))))));

        assert(polynomial.compareTo(polynomial2) > 0);
        assert(polynomial.compareTo(polynomial2) >= 0);
        assert(polynomial2.compareTo(polynomial) < 0);
        assert(polynomial2.compareTo(polynomial) <= 0);

        assert(polynomial.negate().equals(polynomial));

        assert(polynomial.toString().equals("1x^3 + 1x^2 + 1"));
    }

    private static void test_DoubleField() {
        ArrayList<DoubleField> coefficients = new ArrayList<>();
        coefficients.add(new DoubleField(1));
        coefficients.add(new DoubleField(2));
        coefficients.add(new DoubleField(3));
        Polynomial<DoubleField> polynomial = new Polynomial<>(coefficients);
        assert(polynomial.evaluate(new DoubleField(2)).equals(new DoubleField(17)));

        ArrayList<DoubleField> coefficients2 = new ArrayList<>();
        coefficients2.add(new DoubleField(2));
        coefficients2.add(new DoubleField(4));
        Polynomial<DoubleField> polynomial2 = new Polynomial<>(coefficients2);

        assert(polynomial.add(polynomial2).equals(new Polynomial<>(new ArrayList<>(List.of(new DoubleField(3), new DoubleField(6), new DoubleField(3))))));
        assert(polynomial.subtract(polynomial2).equals(new Polynomial<>(new ArrayList<>(List.of(new DoubleField(-1), new DoubleField(-2), new DoubleField(3))))));
        assert(polynomial.multiply(polynomial2).equals(new Polynomial<>(new ArrayList<>(List.of(new DoubleField(2), new DoubleField(8), new DoubleField(14), new DoubleField(12))))));

        assert(polynomial.divide(polynomial2).equals(new Polynomial<>(new ArrayList<>(List.of(new DoubleField(0.125), new DoubleField(0.75))))));
        assert(polynomial.remainder(polynomial2).equals(new Polynomial<>(new ArrayList<>(List.of(new DoubleField(0.75))))));

        assert(polynomial.compareTo(polynomial2) > 0);
        assert(polynomial.compareTo(polynomial2) >= 0);
        assert(polynomial2.compareTo(polynomial) < 0);
        assert(polynomial2.compareTo(polynomial) <= 0);

        assert(polynomial.negate().equals(new Polynomial<>(new ArrayList<>(List.of(new DoubleField(-1), new DoubleField(-2), new DoubleField(-3))))));

        assert(polynomial.toString().equals("3.0x^2 + 2.0x + 1.0"));
    }
}