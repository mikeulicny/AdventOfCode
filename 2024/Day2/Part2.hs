main :: IO ()
main = do
    content <- readFile "input.txt"
    let reports = map (map read . words) (lines content)
    print $ length . filter id . map validMinus1 $ reports


valid :: [Int] -> Bool
valid (x:y:xs) =
    let diffs = zipWith (-) (y:xs) (x:y:xs)
    in (all (>0) diffs || all (<0) diffs) && all (flip elem [1..3] . abs) diffs

validMinus1 :: [Int] -> Bool
validMinus1 xs = any valid [take i xs ++ drop (i + 1) xs | i <- [0..length xs - 1]]
