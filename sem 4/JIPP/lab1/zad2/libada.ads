package Libada is

    type Solution is record
        Exists : Boolean;
        X, Y   : Integer;
    end record;

    function Factorial_Loop (N : in Integer) return Integer;
    pragma Export (C, Factorial_Loop, "factorial_loop");

    function Gcd_Loop (A, B : in out Integer) return Integer;
    pragma Export (C, Gcd_Loop, "gcd_loop");

    function Diophantine_Loop (A, B, C : in out Integer) return Solution;
    pragma Export (C, Diophantine_Loop, "diophantine_loop");

    function Factorial_Rec (N : in Integer) return Integer;
    pragma Export (C, Factorial_Rec, "factorial_rec");

    function Gcd_Rec (A, B : in Integer) return Integer;
    pragma Export (C, Gcd_Rec, "gcd_rec");

    function Diophantine_Rec (A, B, C : in out Integer) return Solution;
    pragma Export (C, Diophantine_Rec, "diophantine_rec");

end Libada;
