pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with Interfaces.C.Extensions;

package library_h is

   type solution is record
      exists : aliased Extensions.bool;  -- ./library.h:8
      x : aliased int;  -- ./library.h:9
      y : aliased int;  -- ./library.h:10
   end record
   with Convention => C_Pass_By_Copy;  -- ./library.h:7

   function factorial_loop (n : int) return int  -- ./library.h:13
   with Import => True, 
        Convention => C, 
        External_Name => "factorial_loop";

   function gcd_loop (a : int; b : int) return int  -- ./library.h:15
   with Import => True, 
        Convention => C, 
        External_Name => "gcd_loop";

   function diophantine_loop
     (a : int;
      b : int;
      c : int) return solution  -- ./library.h:17
   with Import => True, 
        Convention => C, 
        External_Name => "diophantine_loop";

   function factorial_rec (n : int) return int  -- ./library.h:19
   with Import => True, 
        Convention => C, 
        External_Name => "factorial_rec";

   function gcd_rec (a : int; b : int) return int  -- ./library.h:21
   with Import => True, 
        Convention => C, 
        External_Name => "gcd_rec";

   function diophantine_rec
     (a : int;
      b : int;
      c : int) return solution  -- ./library.h:23
   with Import => True, 
        Convention => C, 
        External_Name => "diophantine_rec";

end library_h;
