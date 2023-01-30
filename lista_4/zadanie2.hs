factorial :: Integer -> Integer
factorial 0 = 1
factorial n = n * factorial (n - 1)

mygcd :: Integer -> Integer -> Integer
mygcd a 0 = a
mygcd a b = mygcd b (a `mod` b)

extendedGCD :: Integer -> Integer -> (Integer, Integer, Integer)
extendedGCD a 0 = (a, 1, 0)
extendedGCD a b = (d, t, s - (a `div` b) * t)
  where
    (d, s, t) = extendedGCD b (a `mod` b)

solveEquation :: Integer -> Integer -> Integer -> (Integer, Integer)
solveEquation 0 0 0 = (0, 0)
solveEquation 0 0 _ = error "No solution"
solveEquation 0 b c = (0, c `div` b)
solveEquation a 0 c = (c `div` a, 0)
solveEquation a b c = do
  let (d, s, t) = extendedGCD a b
  if c `mod` d /= 0
    then error "No solution"
    else (s * (c `div` d), t * (c `div` d))