class finite_field:
    p = 1234567891

    def __init__(self, n):
        self.n = n % finite_field.p

    def __add__(self, other):
        return finite_field(self.n + other.n)

    def __sub__(self, other):
        return finite_field(self.n - other.n)

    def __mul__(self, other):
        return finite_field(self.n * other.n)

    def __truediv__(self, other):
        if other.n == 0:
            raise ZeroDivisionError
        return self * other.inverse()

    def __pow__(self, other):
        return finite_field(pow(self.n, other.n, finite_field.p))

    def __str__(self):
        return str(self.n)

    def __eq__(self, other):
        return self.n == other.n

    def __ne__(self, other):
        return self.n != other.n

    def __lt__(self, other):
        return self.n < other.n

    def __le__(self, other):
        return self.n <= other.n

    def __gt__(self, other):
        return self.n > other.n

    def __ge__(self, other):
        return self.n >= other.n

    def __hash__(self):
        return hash(self.n)

    def inverse(self):
        if self.n == 0:
            raise ZeroDivisionError
        return finite_field(pow(self.n, finite_field.p - 2, finite_field.p))

    def __neg__(self):
        return finite_field(-self.n)
