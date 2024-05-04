with Interfaces.C; use Interfaces.C;
with Interfaces.C.Extensions;
with Ada.Text_IO; use Ada.Text_IO;
with library_h; use library_h;

procedure Test is
   S : solution;
   X : int;
begin
   -- Test cases for factorial_loop
   Put_Line("Testing factorial_loop...");
   X := factorial_loop(5);
   Put_Line("Factorial of 5: " & int'Image(X)); -- Expected: 120

   X := factorial_loop(0);
   Put_Line("Factorial of 0: " & int'Image(X)); -- Expected: 1
   Put_Line("");

   -- Test cases for gcd_loop
   Put_Line("Testing gcd_loop...");
   X := gcd_loop(12, 18);
   Put_Line("GCD of 12 and 18: " & int'Image(X)); -- Expected: 6

   X := gcd_loop(35, 49);
   Put_Line("GCD of 35 and 49: " & int'Image(X)); -- Expected: 7
   Put_Line("");

   -- Test cases for diophantine_loop
   Put_Line("Testing diophantine_loop...");
   S := diophantine_loop(2, 3, 5);
   Put_Line("Solution for diophantine equation 2x + 3y = 5:");
   Put_Line("Exists: " & Extensions.bool'Image(S.exists) & ", X: " & int'Image(S.x) & ", Y: " & int'Image(S.y)); -- Expected: Exists=True, X=5, Y=-3

   S := diophantine_loop(3, 6, 9);
   Put_Line("Solution for diophantine equation 3x + 6y = 9:");
   Put_Line("Exists: " & Extensions.bool'Image(S.exists) & ", X: " & int'Image(S.x) & ", Y: " & int'Image(S.y)); -- Expected: Exists=False, X=0, Y=0
   Put_Line("");

   -- Test cases for factorial_rec
   Put_Line("Testing factorial_rec...");
   X := factorial_rec(5);
   Put_Line("Factorial of 5: " & int'Image(X)); -- Expected: 120

   X := factorial_rec(0);
   Put_Line("Factorial of 0: " & int'Image(X)); -- Expected: 1
   Put_Line("");

   -- Test cases for gcd_rec
   Put_Line("Testing gcd_rec...");
   X := gcd_rec(12, 18);
   Put_Line("GCD of 12 and 18: " & int'Image(X)); -- Expected: 6

   X := gcd_rec(35, 49);
   Put_Line("GCD of 35 and 49: " & int'Image(X)); -- Expected: 7
   Put_Line("");

   -- Test cases for diophantine_rec
   Put_Line("Testing diophantine_rec...");
   S := diophantine_rec(2, 3, 5);
   Put_Line("Solution for diophantine equation 2x + 3y = 5:");
   Put_Line("Exists: " & Extensions.bool'Image(S.exists) & ", X: " & int'Image(S.x) & ", Y: " & int'Image(S.y)); -- Expected: Exists=True, X=5, Y=-3

   S := diophantine_rec(3, 6, 9);
   Put_Line("Solution for diophantine equation 3x + 6y = 9:");
   Put_Line("Exists: " & Extensions.bool'Image(S.exists) & ", X: " & int'Image(S.x) & ", Y: " & int'Image(S.y)); -- Expected: Exists=False, X=0, Y=0
   Put_Line("");
end Test;

--gnatmake test.adb -largs -L. -l:libccc.a