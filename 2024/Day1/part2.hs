
main :: IO ()
main = do
    content <- readFile "input.txt"
    let (list1, list2) = unzip $ [(read x, read y) | [x, y] <- map words (lines content)]
    let counts = map (`instances` list2) list1
    let score = getScore list1 counts
    print score

getScore :: [Int] -> [Int] -> Int
getScore [] [] = 0
getScore list1 counts = sum [x * count | (x, count) <- zip list1 counts]

instances :: Eq a => a -> [a] -> Int
instances val = length . filter (== val)
