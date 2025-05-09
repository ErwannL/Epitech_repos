{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-LYN-4-1-compressor-erwann.laplante
-- File description:
-- Lib
-}

module Lib (toInt, noEmptyTab, stringToInt, splitEvery, fillListRand,
            toListFloat, updateMatrix, toFloat, isNum, isFloat) where

import Text.Read
import Data.Char

import Struct

toInt :: Float -> Int
toInt x | (x - (toFloat (floor x))) == 0.5 = floor x
        | otherwise = round x

toFloat :: Int -> Float
toFloat x = (fromIntegral x)

toListFloat :: [Int] -> [Float]
toListFloat xs = map (\x -> fromIntegral x) xs

updateMatrix :: [[a]] -> a -> (Int, Int) -> [[a]]
updateMatrix m x (r, c) = let row = index m r
                              before = take c row
                              after = drop (c + 1) row
                              newRow = before ++ [x] ++ after
    in let above = take r m
           below = drop (r + 1) m in above ++ [newRow] ++ below
    where
        index list xBis = head $ drop xBis list

noEmptyTab :: Data -> Int -> Int
noEmptyTab struct x | x == (length (order struct)) = 0
                    | ((length (index (order struct) x) == 0)) = 1
                    | x /= (length (order struct)) && ((length (index (order
                        struct) x) /= 0)) = noEmptyTab struct (x + 1)
                    | otherwise = 1
    where
        index list xBis = head $ drop xBis list

stringToInt :: String -> Int
stringToInt input
    | Just age <- readMaybe input = age
    | otherwise = error "error in list"

isNum :: [Char] -> Bool
isNum [] = True
isNum (x:xs) | x == '-' = False
             | isDigit x == False = False
             | otherwise = isNum(xs)

isFloat :: String -> Bool
isFloat ""  = False
isFloat "." = False
isFloat xs  | "" <- dropWhile isDigit xs = True
            | ('.':ys) <- dropWhile isDigit xs = all isDigit ys
            | otherwise = False

splitEvery2 :: Int -> [a] -> [[a]]
splitEvery2 _ [] = []
splitEvery2 n xs = as : splitEvery (n - 1) bs
    where (as,bs) = splitAt n xs

splitEvery :: Int -> [a] -> [[a]]
splitEvery _ [] = []
splitEvery n xs = as : splitEvery2 (n + 1) bs
    where (as,bs) = splitAt n xs

fillListRand :: [[Int]] -> [Int]
fillListRand list = filter odd [0..(length list)]
