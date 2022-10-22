include("library.jl")
using Test

function main()
    @test factorial(UInt64(5)) == 120

    @test gcd(12, 3) == 3
    @test gcd(5, 7) == 1

    @test linear_equation(43, 7, 17) == diophantine_solution(17, -102, true)
end

main()
