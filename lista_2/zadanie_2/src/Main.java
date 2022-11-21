public class Main {
    public static void main(String[] args) {
        assert new FiniteField(0).equals(new FiniteField(1234567891));

        assert new FiniteField(1).add(new FiniteField(2)).equals(new FiniteField(3));
        assert new FiniteField(1234567890).add(new FiniteField(4)).equals(new FiniteField(3));

        assert new FiniteField(3).subtract(new FiniteField(2)).equals(new FiniteField(1));
        assert new FiniteField(3).subtract(new FiniteField(4)).equals(new FiniteField(1234567890));

        assert new FiniteField(2).multiply(new FiniteField(3)).equals(new FiniteField(6));
        assert new FiniteField(1234567890).multiply(new FiniteField(2)).equals(new FiniteField(1234567889));

        assert new FiniteField(2).inverse().equals(new FiniteField(617283946));

        assert new FiniteField(6).divide(new FiniteField(3)).equals(new FiniteField(2));
        assert new FiniteField(1234567889).divide(new FiniteField(2)).equals(new FiniteField(1234567890));

        assert new FiniteField(2).pow(3).equals(new FiniteField(8));

        assert new FiniteField(1).compareTo(new FiniteField(2)) < 0;

        assert new FiniteField(2).compareTo(new FiniteField(1)) > 0;

        assert new FiniteField(1).compareTo(new FiniteField(2)) <= 0;

        assert new FiniteField(2).compareTo(new FiniteField(1)) >= 0;

        assert new FiniteField(1).compareTo(new FiniteField(2)) != 0;

        assert new FiniteField(1).toString().equals("1");

        assert new FiniteField(1234567890).toString().equals("1234567890");

        assert new FiniteField(1234567890).equals(FiniteField.fromString("1234567890"));
    }
}