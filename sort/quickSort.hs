-- runhaskell quickSort.hs

qs :: (Ord a) => [a] -> [a]
qs [] = []
qs (x:xs) = qs [y | y <- xs, y <= x] ++ [x] ++ qs [y | y <- xs, y > x]

main :: IO ()
main = putStrLn . show $ qs [1, 3, 5, 3, 2, 7]
