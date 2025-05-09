{-
-- EPITECH PROJECT, 2023
-- B-PDG-300-LYN-3-1-PDGD02-erwann.laplante
-- File description:
-- DoOp
-}

import Data.Char

myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem x (var:list) = if var == x
    then True
    else myElem x list

safeDiv :: Int -> Int -> Maybe Int
safeDiv x 0 = Nothing
safeDiv x y = Just (x `div` y)

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (var:rest) 0 = Just var
safeNth (_:rest) num = safeNth rest (num - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just n) = Just (n + 1)

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing
myLookup num ((x,y):list) = if num == x
    then Just (y)
    else myLookup num list

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo fonction Nothing num = Nothing
maybeDo fonction n Nothing = Nothing
maybeDo fonction n num = (Just fonction) <*> n <*> num

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt str = if all isDigit(str) == True
    then Just(read str::Int)
    else Nothing

getLineLength :: IO Int
getLineLength = fmap length(getLine)

printAndGetLength :: String -> IO Int
printAndGetLength str = putStrLn(str) >> return (length str)

drawline :: Int -> String -> IO ()
drawline 0 _ = return ()
drawline x str = putStr(str) >> drawline (x-1) str

draw :: Int -> Int -> String -> String -> IO ()
draw 0 _ _ _ = return ()
draw x y start center = putStr(start) >> drawline (y-2) center >>
    putStrLn(start) >> draw (x-1) y start center

printBox :: Int -> IO ()
printBox 1 = putStrLn("++")
printBox x | x < 1 = return ()
    | otherwise = draw 1 (x * 2) "+" "-" >> draw (x-2) (x * 2) "|" " " >>
        draw 1 (x * 2) "+" "-"

concatLines :: Int -> IO String
concatLines 0 = return ""
concatLines x = getLine <> concatLines (x-1)

getInt :: IO (Maybe Int)
getInt = readInt <$> getLine