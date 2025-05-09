{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-LYN-4-1-wolfram-erwann.laplante
-- File description:
-- Lib
-}

module Lib (myIsDigit, checkValue, getPos, toBin, fromDigits, extend, binRule,
    findMid, beforeSpace, setMove, addEndSpace) where

import Data.Char
import Control.Exception

import Error

myIsDigit :: String -> Bool
myIsDigit str = (head str == '-' && all isDigit (tail str)) || all isDigit str

checkValue :: String -> Maybe String
checkValue val | myIsDigit val == True = Just val
               | otherwise = Nothing

getPos :: String -> Int -> Char
getPos [x] _ = x
getPos (x:_) 0 = x
getPos (_:xs) pos = getPos xs (pos - 1)
getPos [] _ = throw EmptyList

toBin :: Int -> [Int]
toBin 0 = [0]
toBin num = toBin (num `quot` 2) ++ [num `rem` 2]

fromDigits :: [Int] -> Int
fromDigits = foldl addDigit 0
    where addDigit num d = 10 * num + d

extend :: String -> String
extend str | length str < 8 = extend ("0" ++ str)
           | otherwise = str

binRule :: Int -> String
binRule rule = extend (show (fromDigits (toBin rule)))

findMid :: String -> Int -> String
findMid str size | (length str) == (size + 1) = init (str)
                 | (length str) > size = findMid (tail (init (str))) size
                 | otherwise = str

beforeSpace :: Int -> String -> String
beforeSpace win str | (length str) == 1 = replicate (win `div` 2) ' '
                    | ((length str) `mod` 2) == 1 || (win `mod` 2) == 1 =
                        replicate ((win `div` 2) - (length str) + 2) ' '
                    | otherwise = replicate ((win `div` 2) - (length str) + 1)
                        ' '

setMove :: Int -> String -> String
setMove 0 str = str
setMove _ [] = []
setMove move (x:xs) | move > 0 = " " ++ (setMove (move - 1) (x:xs))
                    | otherwise = setMove (move + 1) xs

addEndSpace :: String -> Int -> String
addEndSpace str len | (length str) == len = str
                    | (length str) >= len = str
                    | otherwise = addEndSpace (str ++ " ") len
