package body Library is

    function factorial (n : Integer) return Integer is
        acc : Integer := 1;
    begin
        for i in 1 .. n loop
            acc := acc * i;
        end loop;

        return acc;
    end factorial;

    function gcd (a : Integer; b : Integer) return Integer is
        a0 : Integer;
        b0 : Integer;
    begin
        a0 := abs a;
        b0 := abs b;

        while a0 /= b0 loop
            if a0 > b0 then
                a0 := a0 - b0;
            else
                b0 := b0 - a0;
            end if;
        end loop;

        return a0;
    end gcd;

    function extended_gcd
       (a : Integer; b : Integer; x : out Integer; y : out Integer)
        return Integer
    is
        x1   : Integer := 0;
        y1   : Integer := 1;
        a1   : Integer;
        b1   : Integer;
        q    : Integer;
        temp : Integer;
    begin
        x := 1;
        y := 0;

        if b = 0 then
            return a;
        end if;

        a1 := a;
        b1 := b;

        while b1 /= 0 loop
            q := a1 / b1;

            temp := x;
            x    := x1;
            x1   := temp - q * x1;

            temp := y;
            y    := y1;
            y1   := temp - q * y1;

            temp := a1;
            a1   := b1;
            b1   := temp - q * b1;
        end loop;

        return a1;
    end extended_gcd;

    function linear_equation
       (a : Integer; b : Integer; c : Integer) return diophantine_solution
    is
        x0  : Integer := 0;
        y0  : Integer := 0;
        g   : Integer;
        sol : diophantine_solution;
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

        g := extended_gcd (abs a, abs b, x0, y0);
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

        sol := (x0, y0, True);
        return sol;
    end linear_equation;
end Library;
