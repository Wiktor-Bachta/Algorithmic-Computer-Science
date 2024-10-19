-- ghci
-- :load functions.hs

import Data.List

binomial :: Integer -> Integer -> Integer
binomial n 0 = 1
binomial n k | n == k = 1
binomial n k = binomial (n-1) k + binomial (n-1) (k-1)

binomial2 :: Integer -> Integer -> Integer
binomial2 n k = pascal !! fromIntegral n !! fromIntegral k
  where
    pascal = iterate nextRow [1]
    nextRow row = zipWith (+) ([0] ++ row) (row ++ [0])

mergesort :: Ord a => [a] -> [a]
mergesort [] = []
mergesort [x] = [x]
mergesort xs = merge (mergesort left) (mergesort right)
  where
    (left, right) = splitAt (length xs `div` 2) xs
    merge [] ys = ys
    merge xs [] = xs
    merge (x:xs) (y:ys)
      | x <= y    = x : merge xs (y:ys)
      | otherwise = y : merge (x:xs) ys

de :: Integer -> Integer -> (Integer, Integer, Integer)
de a b = let (g, x, y) = extendedGCD a b in (x, y, g)
  where
    extendedGCD 0 b = (b, 0, 1)
    extendedGCD a b = 
      let (g, x1, y1) = extendedGCD (b `mod` a) a
      in (g, y1 - (b `div` a) * x1, x1)

primeFactors :: Integer -> [Integer]
primeFactors n = factorize n 2
  where
    factorize 1 _ = []
    factorize n f
      | n `mod` f == 0 = f : factorize (n `div` f) f
      | otherwise = factorize n (f + 1)

totient :: Integer -> Integer
totient n = fromIntegral (length [x | x <- [1..n], gcd x n == 1])

totient2 :: Integer -> Integer
totient2 n = floor (fromIntegral n * product [1 - (1 / fromIntegral p) | p <- nub (primeFactors n)])

primes :: Integer -> [Integer]
primes n = sieve [2..n]
  where
    sieve [] = []
    sieve (p:xs) = p : sieve [x | x <- xs, x `mod` p /= 0]
