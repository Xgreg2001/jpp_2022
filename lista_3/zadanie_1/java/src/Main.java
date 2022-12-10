public class Main {
    public static void main(String[] args) {
        assert new FiniteField(0, 1234567891).equals(new FiniteField(1234567891, 1234567891));

        assert new FiniteField(1, 1234567891).add(new FiniteField(2, 1234567891)).equals(new FiniteField(3, 1234567891));
        assert new FiniteField(1234567890, 1234567891).add(new FiniteField(4, 1234567891)).equals(new FiniteField(3, 1234567891));

        assert new FiniteField(3, 1234567891).subtract(new FiniteField(2, 1234567891)).equals(new FiniteField(1, 1234567891));
        assert new FiniteField(3, 1234567891).subtract(new FiniteField(4, 1234567891)).equals(new FiniteField(1234567890, 1234567891));

        assert new FiniteField(2, 1234567891).multiply(new FiniteField(3, 1234567891)).equals(new FiniteField(6, 1234567891));
        assert new FiniteField(1234567890, 1234567891).multiply(new FiniteField(2, 1234567891)).equals(new FiniteField(1234567889, 1234567891));

        assert new FiniteField(2, 1234567891).inverse().equals(new FiniteField(617283946, 1234567891));

        assert new FiniteField(6, 1234567891).divide(new FiniteField(3, 1234567891)).equals(new FiniteField(2, 1234567891));
        assert new FiniteField(1234567889, 1234567891).divide(new FiniteField(2, 1234567891)).equals(new FiniteField(1234567890, 1234567891));

        assert new FiniteField(2, 1234567891).pow(3).equals(new FiniteField(8, 1234567891));

        assert new FiniteField(1, 1234567891).compareTo(new FiniteField(2, 1234567891)) < 0;

        assert new FiniteField(2, 1234567891).compareTo(new FiniteField(1, 1234567891)) > 0;

        assert new FiniteField(1, 1234567891).compareTo(new FiniteField(2, 1234567891)) <= 0;

        assert new FiniteField(2, 1234567891).compareTo(new FiniteField(1, 1234567891)) >= 0;

        assert new FiniteField(1, 1234567891).compareTo(new FiniteField(2, 1234567891)) != 0;

        assert new FiniteField(1, 1234567891).toString().equals("1");

        assert new FiniteField(1234567890, 1234567891).toString().equals("1234567890");
    }
}