package Library is

   --  Declaration
   type diophantine_solution is record
      x: Integer;
      y: Integer;
      solution_exist: Boolean;
   end record;

   function factorial(n : Integer) return Integer with
       Export        => True,
       Convention    => C,
       External_Name => "factorail";

   function gcd(a : Integer; b : Integer) return Integer with
       Export        => True,
       Convention    => C,
       External_Name => "gcd";

   function linear_equation(a: Integer; b: Integer; 
   c: Integer) return diophantine_solution with
       Export        => True,
       Convention    => C,
       External_Name => "linear_equation";

end Library;