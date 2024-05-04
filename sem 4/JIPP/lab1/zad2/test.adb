with Ada.Text_IO; use Ada.Text_IO;
with Libada; use Libada;

procedure Test IS

begin
   -- Test cases for Factorial_Loop
   Put_Line("Testing Factorial_Loop...");
   Put_Line("Factorial of 0: " & Integer'Image(Factorial_Loop(0))); -- Expected: 1
   Put_Line("Factorial of 5: " & Integer'Image(Factorial_Loop(5))); -- Expected: 120
   Put_Line("");

   -- Test cases for Gcd_Loop
   Put_Line("Testing Gcd_Loop...");
   declare
      A : Integer := 12;
      B : Integer := 18;
   begin
      Put_Line("GCD of " & Integer'Image(A) & " and " & Integer'Image(B) & ": " & Integer'Image(Gcd_Loop(A, B))); -- Expected: 6
   end;
   declare
      A : Integer := 35;
      B : Integer := 49;
   begin
      Put_Line("GCD of " & Integer'Image(A) & " and " & Integer'Image(B) & ": " & Integer'Image(Gcd_Loop(A, B))); -- Expected: 7
   end;
   Put_Line("");

   -- Test cases for Diophantine_Loop
   Put_Line("Testing Diophantine_Loop...");
   declare
      A : Integer := 2;
      B : Integer := 3;
      C : Integer := 5;
      Sol : Solution;
   begin
      Sol := Diophantine_Loop(A, B, C);
      Put_Line("Diophantine solution for " & Integer'Image(A) & ", " & Integer'Image(B) & ", " & Integer'Image(C) & ": Exists=" & Boolean'Image(Sol.Exists) & ", X=" & Integer'Image(Sol.X) & ", Y=" & Integer'Image(Sol.Y)); -- Expected: Exists=True, X=5, Y=-3
   end;
   declare
      A : Integer := 3;
      B : Integer := 6;
      C : Integer := 9;
      Sol : Solution;
   begin
      Sol := Diophantine_Loop(A, B, C);
      Put_Line("Diophantine solution for " & Integer'Image(A) & ", " & Integer'Image(B) & ", " & Integer'Image(C) & ": Exists=" & Boolean'Image(Sol.Exists) & ", X=" & Integer'Image(Sol.X) & ", Y=" & Integer'Image(Sol.Y)); -- Expected: Exists=False, X=0, Y=0
   end;
   Put_Line("");

   -- Test cases for Factorial_Rec
   Put_Line("Testing Factorial_Rec...");
   Put_Line("Factorial of 0: " & Integer'Image(Factorial_Rec(0))); -- Expected: 1
   Put_Line("Factorial of 5: " & Integer'Image(Factorial_Rec(5))); -- Expected: 120
   Put_Line("");

   -- Test cases for Gcd_Rec
   Put_Line("Testing Gcd_Rec...");
   Put_Line("GCD of 12 and 18: " & Integer'Image(Gcd_Rec(12, 18))); -- Expected: 6
   Put_Line("GCD of 35 and 49: " & Integer'Image(Gcd_Rec(35, 49))); -- Expected: 7
   Put_Line("");

   -- Test cases for Diophantine_Rec
   Put_Line("Testing Diophantine_Rec...");
   declare
      A : Integer := 2;
      B : Integer := 3;
      C : Integer := 5;
      Sol : Solution;
   begin
      Sol := Diophantine_Rec(A, B, C);
      Put_Line("Diophantine solution for " & Integer'Image(A) & ", " & Integer'Image(B) & ", " & Integer'Image(C) & ": Exists=" & Boolean'Image(Sol.Exists) & ", X=" & Integer'Image(Sol.X) & ", Y=" & Integer'Image(Sol.Y)); -- Expected: Exists=True, X=5, Y=-3
   end;
   declare
      A : Integer := 3;
      B : Integer := 6;
      C : Integer := 9;
      Sol : Solution;
   begin
      Sol := Diophantine_Rec(A, B, C);
      Put_Line("Diophantine solution for " & Integer'Image(A) & ", " & Integer'Image(B) & ", " & Integer'Image(C) & ": Exists=" & Boolean'Image(Sol.Exists) & ", X=" & Integer'Image(Sol.X) & ", Y=" & Integer'Image(Sol.Y)); -- Expected: Exists=False, X=0, Y=0
   end;
   Put_Line("");

end Test;
-- gnatmake test.adb -largs -L. -lada