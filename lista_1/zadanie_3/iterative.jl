
struct diophantine_solution
    x::Int64
    y::Int64
    solution_exist::Bool
end

function factorial(n::Int64)::Int64
    acc = 1
    for i in 1:n
        acc *= i
    end

    return acc
end

function gcd(a::Int64, b::Int64)::Int64
    a = abs(a)
    b = abs(b)

    while a != b
        if a > b
            a -= b
        else
            b -= a
        end
    end

    return a
end

function extended_gcd(a::Int64, b::Int64)::Tuple{Int64,Int64,Int64}
    x = 1
    y = 0

    if b == 0
        return (a, x, y)
    end

    x1 = 0
    y1 = 1

    while b != 0
        q = a ÷ b

        x, x1 = x1, x - q * x1
        y, y1 = y1, y - q * y1
        a, b = b, a - q * b
    end

    return (a, x, y)
end

function linear_equation(a::Int64, b::Int64, c::Int64)::diophantine_solution

    if a == 0 && b == 0
        if c == 0
            return diophantine_solution(0, 0, true)
        else
            return diophantine_solution(0, 0, false)
        end
    end

    (g, x, y) = extended_gcd(abs(a), abs(b))

    if c % g != 0
        return diophantine_solution(0, 0, false)
    end

    x *= c ÷ g
    y *= c ÷ g
    if a < 0
        x = -x
    end
    if b < 0
        y = -y
    end

    return diophantine_solution(x, y, true)
end