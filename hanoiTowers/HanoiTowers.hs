{-| Solve hanoi for n given disks by moving them from source
 - through helper on the destination rod
 -}
h :: Int -> String -> String -> String -> [String]
h n source helper dest
 | n == 1 = [source ++ "-" ++ dest]
 | otherwise = h (n-1) source dest helper ++
    [source ++ "-" ++ dest] ++
    h (n-1) helper source dest

main :: IO()
main = do
    n <- getLine
    let (discs,_) = (reads n) !! 0
    putStrLn $ unwords (h discs "A" "B" "C")
