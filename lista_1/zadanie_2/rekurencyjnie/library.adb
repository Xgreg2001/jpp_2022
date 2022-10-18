package body Library is
    function factorial (n: Integer) return Integer is
    begin
        if n = 1 then
            return 1;
        end if;

        return n * factorial(n - 1);
    end factorial;

    function gcd (a: Integer; b: Integer) return Integer is
    begin
        if b /= 0 then
            return gcd(b, a mod b);
        else
            return a;
        end if;
    end gcd;

    function extended_gcd(a: Integer; b: Integer;
     x: out Integer; y: out Integer) return Integer is
        x1:Integer;
        y1:Integer;
        d: Integer;
    begin
        if b = 0 then
            x := 1;
            y := 0;
            return a;
        end if;

        d := extended_gcd(b, a mod b, x1, y1);
        x := y1;
        y := x1 - y1 * (a / b);
        return d;
    end extended_gcd;

    function linear_equation(a: Integer; b: Integer; 
    c: Integer) return diophantine_solution is
        x0: Integer := 0;
        y0: Integer := 0;
        g: Integer;
        sol: diophantine_solution;
    begin
        if a = 0 and b = 0 then
            if c = 0 then
                sol := (0, 0, True);
                return sol;
            else
                sol := (0, 0, False);
                return sol;
            end if;
        end if;

        g := extended_gcd(abs a, abs b, x0, y0);
        if (c mod g) /= 0 then
            sol := (0, 0, False);
            return sol;
        end if;

        x0 := x0 * c / g;
        y0 := y0 * c / g;
        if a < 0 then
            x0 := -x0;
        end if;
        if b < 0 then
            y0 := -y0;
        end if;

        sol := (x0, y0, true);
        return sol;
    end linear_equation;
end library;