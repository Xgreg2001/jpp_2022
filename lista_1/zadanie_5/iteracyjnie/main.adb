pragma Assertion_Policy (Check);

with Library;
with Ada.Text_IO;

procedure main is
    sol:Library.diophantine_solution;
begin
    pragma Assert (Library.factorial(5) = 120);

    pragma Assert (Library.gcd(12, 3) = 3);
    pragma Assert (Library.gcd(5, 7) = 1);

    sol := Library.linear_equation(43, 7, 17);

    Ada.Text_IO.Put_Line(Integer'Image(sol.x));
    Ada.Text_IO.Put_Line(Integer'Image(sol.y));
    Ada.Text_IO.Put_Line(Boolean'Image(sol.solution_exist));

    pragma Assert (sol.x = 17 and sol.y = -102 and sol.solution_exist = true);
end main;