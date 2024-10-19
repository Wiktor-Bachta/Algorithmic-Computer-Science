(* sml *)
(* use "functions.sml"; *)

(* 1. binomial - Dwumian Newtona *)
fun binomial (n, k) =
  if k = 0 orelse k = n then 1
  else binomial (n - 1, k) + binomial (n - 1, k - 1)

(* 2. binomial2 - Dwumian Newtona wykorzystujący trójkąt Pascala *)
fun pascalRow [] = [1]
  | pascalRow row = let
      fun pairwise [] = []
        | pairwise [_] = []
        | pairwise (x::y::rest) = (x + y)::(pairwise (y::rest))
    in
      1::(pairwise row)@[1]
    end

fun pascal 0 = [1]
  | pascal n = pascalRow (pascal (n - 1))

fun binomial2 (n, k) = List.nth (pascal n, k)

(* 3. mergeSort - Sortowanie przez scalanie *)
fun merge ([], ys) = ys
  | merge (xs, []) = xs
  | merge (x::xs, y::ys) =
      if x <= y then x::(merge (xs, y::ys))
      else y::(merge (x::xs, ys))

fun mergeSort [] = []
  | mergeSort [x] = [x]
  | mergeSort xs =
      let
        val mid = List.length xs div 2
        val left = List.take(xs, mid)
        val right = List.drop(xs, mid)
      in
        merge (mergeSort left, mergeSort right)
      end

(* 4. de - Równanie diofantyczne *)
fun extendedGCD (0, b) = (b, 0, 1)
  | extendedGCD (a, b) =
      let
        val (g, x1, y1) = extendedGCD (b mod a, a)
      in
        (g, y1 - (b div a) * x1, x1)
      end

fun de (a, b) = extendedGCD (a, b)

(* 5. primeFactors - Rozkład na czynniki pierwsze *)
fun primeFactors n =
  let
    fun factorize (1, _) = []
      | factorize (n, f) =
          if n mod f = 0 then f::(factorize (n div f, f))
          else factorize (n, f + 1)
  in
    factorize (n, 2)
  end

(* 6. totient - Funkcja Eulera *)
fun gcd (a, 0) = a
  | gcd (a, b) = gcd (b, a mod b)

fun totient n =
  List.length (List.filter (fn x => gcd (x, n) = 1) (List.tabulate (n, fn i => i + 1)))

(* 7. totient2 - Funkcja Eulera na podstawie czynników pierwszych *)
fun unique [] = []
  | unique (x::xs) =
      if List.exists (fn y => x = y) xs then unique xs
      else x::(unique xs)

fun totient2 n =
  let
    val primeFactors = unique (primeFactors n)
    val productTerm = List.foldl (fn (p, acc) => acc * (1.0 - 1.0 / Real.fromInt p)) 1.0 primeFactors
  in
    Real.floor (Real.fromInt n * productTerm)
  end

(* 8. primes - Lista wszystkich liczb pierwszych między 2 a n *)
fun sieve [] = []
  | sieve (x::xs) = x::(sieve (List.filter (fn y => y mod x <> 0) xs))

fun primes n = sieve (List.tabulate (n - 1, fn i => i + 2))