package Library is

   --  Declaration
   type diophantine_solution is record
      x: Integer;
      y: Integer;
      solution_exist: Boolean;
   end record;

   function factorial(n : Integer) return Integer;

   function gcd(a : Integer; b : Integer) return Integer;

   function linear_equation(a: Integer; b: Integer; 
   c: Integer) return diophantine_solution;

end Library;