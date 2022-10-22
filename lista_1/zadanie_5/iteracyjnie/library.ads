package Library is

   --  Declaration
   type diophantine_solution is record
      x: Integer;
      y: Integer;
      solution_exist: Boolean;
   end record;
   pragma Convention (C, diophantine_solution);

   function factorial(n : Integer) return Integer with
      import => True,
      Convention => C;

   function gcd(a : Integer; b : Integer) return Integer with
      import => True,
      Convention => C;

   function linear_equation(a: Integer; b: Integer; 
   c: Integer) return diophantine_solution with
      import => True,
      Convention => C;

end Library;