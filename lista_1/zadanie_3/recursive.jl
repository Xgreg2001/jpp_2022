
struct diophantine_solution
    x::Int64
    y::Int64
    solution_exist::Bool
end

function factorial(n::Int64)::Int64
    if n == 1
        return 1
    end

    return n * factorial(n - 1)
end

function gcd(a::Int64, b::Int64)::Int64
    if b != 0
        return gcd(b, a % b)
    else
        return a
    end
end

function extended_gcd(a::Int64, b::Int64)::NTuple{3,Int64}
    if b == 0
        return (a, 1, 0)
    end

    d, x, y = extended_gcd(b, a % b)

    return (d, y, x - y * div(a, b))
end

function linear_equation(a::Int64, b::Int64, c::Int64)
    if a == 0 && b == 0
        if c == 0
            return diophantine_solution(0, 0, true)
        else
            return diophantine_solution(0, 0, false)
        end
    end

    g, x, y = extended_gcd(abs(a), abs(b))

    if c % g != 0
        return diophantine_solution(0, 0, false)
    end

    x *= div(c, g)
    y *= div(c, g)
    x = a >= 0 ? x : -x
    y = b >= 0 ? y : -y

    return diophantine_solution(x, y, true)
end