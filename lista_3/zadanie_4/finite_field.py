def isPrime(p):
    if p == 2:
        return True
    if p % 2 == 0 or p <= 1:
        return False
    sqr = int(p ** 0.5) + 1
    for divisor in range(3, sqr, 2):
        if p % divisor == 0:
            return False
    return True


class finite_field:

    def __init__(self, n, p):
        self.n = n % p
        if isPrime(p):
            self.p = p
        else:
            raise TypeError

    def __add__(self, other):
        if self.p != other.p:
            raise TypeError
        return finite_field(self.n + other.n, self.p)

    def __sub__(self, other):
        if self.p != other.p:
            raise TypeError
        return finite_field(self.n - other.n, self.p)

    def __mul__(self, other):
        if self.p != other.p:
            raise TypeError
        return finite_field(self.n * other.n, self.p)

    def __truediv__(self, other):
        if self.p != other.p:
            raise TypeError
        if other.n == 0:
            raise ZeroDivisionError
        return self * other.inverse()

    def __pow__(self, other):
        if self.p != other.p:
            raise TypeError
        return finite_field(pow(self.n, other.n, self.p), self.p)

    def __str__(self):
        return str(self.n)

    def __eq__(self, other):
        if self.p != other.p:
            raise TypeError
        return self.n == other.n

    def __ne__(self, other):
        if self.p != other.p:
            raise TypeError
        return self.n != other.n

    def __lt__(self, other):
        if self.p != other.p:
            raise TypeError
        return self.n < other.n

    def __le__(self, other):
        if self.p != other.p:
            raise TypeError
        return self.n <= other.n

    def __gt__(self, other):
        if self.p != other.p:
            raise TypeError
        return self.n > other.n

    def __ge__(self, other):
        if self.p != other.p:
            raise TypeError
        return self.n >= other.n

    def __hash__(self):
        return hash(self.n)

    def inverse(self):
        if self.n == 0:
            raise ZeroDivisionError
        return finite_field(pow(self.n, self.p - 2, self.p), self.p)

    def __neg__(self):
        return finite_field(-self.n, self.p)
