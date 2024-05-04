with Ada.Text_IO; use Ada.Text_IO;

package body Libada is

   function Factorial_Loop (N : in Integer) return Integer is
      Result : Integer := 1;
   begin
      for I in 2 .. N loop
         Result := Result * I;
      end loop;
      return Result;
   end Factorial_Loop;

   function Gcd_Loop (A, B : in out Integer) return Integer is
      Tmp : Integer;
   begin
      while B /= 0 loop
         Tmp := B;
         B   := A mod B;
         A   := Tmp;
      end loop;
      return A;
   end Gcd_Loop;

   function Diophantine_Loop (A, B, C : in out Integer) return Solution is
      GCD_AB                         : Integer;
      Result                         : Solution;
      X, Y, U, V, R, Q, M, N, Factor : Integer;
   begin
      Result.Exists := False;
      X             := A;
      Y             := B;
      GCD_AB        := Gcd_Loop (X, Y);
      if C mod GCD_AB /= 0 then
         return Result;
      end if;

      X := 0;
      Y := 1;
      U := 1;
      V := 0;

      while A /= 0 loop
         R := B mod A;
         Q := B / A;
         M := X - U * Q;
         N := Y - V * Q;

         B := A;
         A := R;
         X := U;
         Y := V;
         U := M;
         V := N;
      end loop;

      Factor := C / GCD_AB;

      Result.Exists := True;
      Result.X      := X * Factor;
      Result.Y      := Y * Factor;
      return Result;
   end Diophantine_Loop;

   function Factorial_Rec (N : in Integer) return Integer is
   begin
      if N = 0 then
         return 1;
      end if;
      return N * Factorial_Rec (N - 1);
   end Factorial_Rec;

   function Gcd_Rec (A, B : in Integer) return Integer is
   begin
      if B = 0 then
         return A;
      end if;
      return Gcd_Rec (B, A mod B);
   end Gcd_Rec;

   function Diophantine_Rec (A, B, C : in out Integer) return Solution is
      GCD_AB       : Integer;
      Result       : Solution;
      X, Y, Factor : Integer;

      function Diophantine_Recursive
        (A, B, X, Y, U, V : Integer) return Solution
      is
         R, Q, M, N : Integer;
         Result     : Solution;
      begin
         if A = 0 then
            Result.Exists := True;
            Result.X      := X;
            Result.Y      := Y;
            return Result;
         end if;

         R := B mod A;
         Q := B / A;
         M := X - U * Q;
         N := Y - V * Q;
         return Diophantine_Recursive (R, A, U, V, M, N);
      end Diophantine_Recursive;

   begin
      Result.Exists := False;
      X             := A;
      Y             := B;
      GCD_AB        := Gcd_Loop (X, Y);

      if C mod GCD_AB /= 0 then
         return Result;
      end if;

      Result := Diophantine_Recursive (A, B, 0, 1, 1, 0);

      Factor   := C / GCD_AB;
      Result.X := Result.X * Factor;
      Result.Y := Result.Y * Factor;
      return Result;
   end Diophantine_Rec;
end Libada;
