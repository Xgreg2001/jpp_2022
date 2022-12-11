class polynomial:

    def __init__(self, coefficients):
        while len(coefficients) > 0 and coefficients[-1] == 0:
            coefficients.pop()
        self.coefficients = coefficients

    def __add__(self, other):
        if len(self.coefficients) > len(other.coefficients):
            return polynomial([self.coefficients[i] + other.coefficients[i] for i in range(len(other.coefficients))] + self.coefficients[len(other.coefficients):])
        else:
            return polynomial([self.coefficients[i] + other.coefficients[i] for i in range(len(self.coefficients))] + other.coefficients[len(self.coefficients):])

    def __sub__(self, other):
        if len(self.coefficients) > len(other.coefficients):
            return polynomial([self.coefficients[i] - other.coefficients[i] for i in range(len(other.coefficients))] + self.coefficients[len(other.coefficients):])
        else:
            return polynomial([self.coefficients[i] - other.coefficients[i] for i in range(len(self.coefficients))] + [-other.coefficients[i] for i in range(len(self.coefficients), len(other.coefficients))])

    def __mul__(self, other):
        result = [0] * (len(self.coefficients) + len(other.coefficients) - 1)
        for i in range(len(self.coefficients)):
            for j in range(len(other.coefficients)):
                result[i + j] += self.coefficients[i] * other.coefficients[j]
        return polynomial(result)

    def __truediv__(self, other):
        if len(other.coefficients) == 0:
            raise ZeroDivisionError
        if len(self.coefficients) < len(other.coefficients):
            return polynomial([0])
        divident = self.coefficients[:]
        result = [0] * (len(divident) - len(other.coefficients) + 1)
        for i in range(len(divident) - len(other.coefficients), -1, -1):
            result[i] = divident[i +
                                 len(other.coefficients) - 1] / other.coefficients[-1]
            for j in range(len(other.coefficients) - 1, -1, -1):
                divident[i + j] -= result[i] * other.coefficients[j]
        return polynomial(result)

    def __mod__(self, other):
        return self - (self / other) * other

    def __str__(self):
        result = ""
        for i in range(len(self.coefficients) - 1, -1, -1):
            if self.coefficients[i] != 0:
                if self.coefficients[i] > 0 and i != len(self.coefficients) - 1:
                    result += " + "
                if self.coefficients[i] < 0:
                    result += " - "
                if abs(self.coefficients[i]) != 1 or i == 0:
                    result += str(abs(self.coefficients[i]))
                if i != 0:
                    result += "x"
                if i > 1:
                    result += "^" + str(i)
        return result

    def __eq__(self, other):
        return self.coefficients == other.coefficients

    def __ne__(self, other):
        return self.coefficients != other.coefficients

    def __lt__(self, other):
        if len(self.coefficients) < len(other.coefficients):
            return True
        if len(self.coefficients) > len(other.coefficients):
            return False
        for i in range(len(self.coefficients) - 1, -1, -1):
            if self.coefficients[i] < other.coefficients[i]:
                return True
            if self.coefficients[i] > other.coefficients[i]:
                return False
        return False

    def __le__(self, other):
        if len(self.coefficients) < len(other.coefficients):
            return True
        if len(self.coefficients) > len(other.coefficients):
            return False
        for i in range(len(self.coefficients) - 1, -1, -1):
            if self.coefficients[i] < other.coefficients[i]:
                return True
            if self.coefficients[i] > other.coefficients[i]:
                return False
        return True

    def __gt__(self, other):
        if len(self.coefficients) > len(other.coefficients):
            return True
        if len(self.coefficients) < len(other.coefficients):
            return False
        for i in range(len(self.coefficients) - 1, -1, -1):
            if self.coefficients[i] > other.coefficients[i]:
                return True
            if self.coefficients[i] < other.coefficients[i]:
                return False
        return False

    def __ge__(self, other):
        if len(self.coefficients) > len(other.coefficients):
            return True
        if len(self.coefficients) < len(other.coefficients):
            return False
        for i in range(len(self.coefficients) - 1, -1, -1):
            if self.coefficients[i] > other.coefficients[i]:
                return True
            if self.coefficients[i] < other.coefficients[i]:
                return False
        return True

    def evaluate(self, x):
        result = 0
        for i in range(len(self.coefficients)):
            result += self.coefficients[i] * x**i
        return result
