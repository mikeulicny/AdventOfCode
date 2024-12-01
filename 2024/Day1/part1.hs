import Data.List (sort)

main :: IO ()
main = do
    content <- readFile "input.txt"
    let (list1, list2) = unzip $ [(read x, read y) | [x, y] <- map words (lines content)]
    let totalDist = sum $ zipWith (\x y -> abs(x - y)) (sort list1) (sort list2)
    print totalDist
