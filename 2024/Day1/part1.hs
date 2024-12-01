import Data.List (delete, minimum)

main :: IO ()
main = do
    content <- readFile "input.txt"
    let (list1, list2) = unzip $ [(read x, read y) | [x, y] <- map words (lines content)]
    let totalDist = getMins list1 list2
    print totalDist

getMins :: [Int] -> [Int] -> Int
getMins [] [] = 0
getMins list1 list2 = abs(min1 - min2) + getMins remain1 remain2
    where
        min1 = minimum list1
        min2 = minimum list2
        remain1 = delete min1 list1
        remain2 = delete min2 list2
