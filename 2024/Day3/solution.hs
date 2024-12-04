-- Install the dependency
-- $ cabal install --lib regex-posix
-- $ cabal install --lib split
-- TODO: Rewrite using Megaparsec
import Text.Regex.Posix
import Data.List.Split

parseMul :: String -> Int
parseMul str = sum [read n1 * read n2 | (_:n1:n2:_) <- matches]
    where matches = str =~ "mul\\(([0-9]+),\\s*([0-9]+)\\)"

splitOnDoDont :: String -> Int
splitOnDoDont = parseMul . concatMap (head . splitOn "don't()") . splitOn "do()"

main :: IO ()
main = do
    input <- concat . lines <$> readFile "input.txt"
    print $ parseMul input
    print $ splitOnDoDont input
