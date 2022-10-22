
push!(Libc.DL_LOAD_PATH, pwd())

struct diophantine_solution
    x::Int64
    y::Int64
    solution_exist::Bool
end

function factorial(n::UInt64)
    return ccall((:factorial, :lib), UInt64, (UInt64,), n)
end

function gcd(a::Int64, b::Int64)
    return ccall((:gcd, :lib), Int64, (Int64, Int64), a, b)
end

function linear_equation(a::Int64, b::Int64, c::Int64)
    return ccall((:linear_equation, :lib), diophantine_solution, (Int64, Int64, Int64), a, b, c)
end