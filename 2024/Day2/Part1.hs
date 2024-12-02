main :: IO ()
main = do
    content <- readFile "input.txt"
    let reports = map (map read . words) (lines content)
    let safeReports = sum $ map (fromEnum . checkSafe) reports
    print safeReports

checkSafe :: [Int] -> Bool
checkSafe [] = True
checkSafe [_] = True
checkSafe (x:y:xs)
    | x < y = isIncreasing (x:y:xs)
    | y < x = isDecreasing (x:y:xs)
    | otherwise = False
    where
        isIncreasing (a:b:rest)
            | 1 <= b - a && b - a <= 3 = isIncreasing (b:rest)
            | otherwise = False
        isIncreasing _ = True

        isDecreasing (a:b:rest)
            | 1 <= a - b && a - b <= 3 = isDecreasing (b:rest)
            | otherwise = False
        isDecreasing _ = True
