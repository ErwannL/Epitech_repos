{-
-- EPITECH PROJECT, 2023
-- B-PDG-300-LYN-3-1-PDGRUSH1-erwann.laplante
-- File description:
-- pushswap
-}

import System.Exit
import System.Environment
import System.IO
import Data.List
import Data.Char
import Data.Function

swap :: [a] -> [a]
swap [] = []
swap [a] = [a]
swap (a:b:bs) = (b:a:bs)

swapA :: ([a], [a]) -> ([a], [a])
swapA ([], listB) = ([], listB)
swapA ([a], listB) = ([a], listB)
swapA ((a:b:bs), listB) = ((b:a:bs), listB)

swapB :: ([a], [a]) -> ([a], [a])
swapB (listA, []) = (listA, [])
swapB (listA, [a]) = (listA, [a])
swapB (listA, (a:b:bs)) = (listA, (b:a:bs))

swapC :: ([a], [a]) -> ([a], [a])
swapC (listA, listB) = (swap listA, swap listB)

rotate :: [a] -> [a]
rotate [] = []
rotate list = tail list ++ [head list]

rotateA :: ([a], [a]) -> ([a], [a])
rotateA ([], listB) = ([], listB)
rotateA (listA, listB) = (tail listA ++ [head listA], listB)

rotateB :: ([a], [a]) -> ([a], [a])
rotateB (listA, []) = (listA, [])
rotateB (listA, listB) = (listA, tail listB ++ [head listB])

rotateR :: ([a], [a]) -> ([a], [a])
rotateR (listA, listB) = (rotate listA, rotate listB)

reverseRotate :: [a] -> [a]
reverseRotate [] = []
reverseRotate list = reverse (rotate (reverse list))

reverseRotateA :: ([a], [a]) -> ([a], [a])
reverseRotateA ([], listB) = ([], listB)
reverseRotateA (listA, listB) = ((reverse (rotate (reverse listA))), listB)

reverseRotateB :: ([a], [a]) -> ([a], [a])
reverseRotateB (listA, []) = (listA, [])
reverseRotateB (listA, listB) = (listA, (reverse (rotate (reverse listB))))

reverseRotateR :: ([a], [a]) -> ([a], [a])
reverseRotateR (listA, listB) = (reverseRotate listA, reverseRotate listB)

pushA :: ([a], [a]) -> ([a], [a])
pushA ([], (a:as)) = ([a], as)
pushA (x, []) = (x, [])
pushA ((a:as), (b:bs)) = ((b:a:as), bs)

pushB :: ([a], [a]) -> ([a], [a])
pushB ((a:as), []) = (as, [a])
pushB ([], x) = ([], x)
pushB ((a:as), (b:bs)) = (as, (a:b:bs))

split :: String -> [String]
split [] = [""]
split (' ':rest) = "":(split rest)
split (value:rest) = (value:head (split rest)):tail (split rest)

myParseBis :: [String] -> ([String], [String]) -> ([String], [String])
myParseBis (first:commands) lists = case first of
    "ra" ->  myParse commands (rotateA lists)
    "rb" ->  myParse commands (rotateB lists)
    "rr" ->  myParse commands (rotateR lists)
    "rra" ->  myParse commands (reverseRotateA lists)
    "rrb" ->  myParse commands (reverseRotateB lists)
    "rrr" ->  myParse commands (reverseRotateR lists)
    _ -> ([], [])

myParse :: [String] -> ([String], [String]) -> ([String], [String])
myParse [""] lists = lists
myParse [] lists = lists
myParse (first:commands) lists = case first of
    "sa" -> myParse commands (swapA lists)
    "sb" ->  myParse commands (swapB lists)
    "sc" ->  myParse commands (swapC lists)
    "pa" ->  myParse commands (pushA lists)
    "pb" ->  myParse commands (pushB lists)
    _ -> myParseBis (first:commands) lists

myComp :: [String] -> ([String], [String]) -> [String]
myComp _ ([], []) = []
myComp comp (lista, listb) | listb /= [] = []
    | lista /= ((sortBy (compare `on` (read :: String -> Int))) comp) = []
    | otherwise = lista

myIsDigit :: String -> Bool
myIsDigit str = (head str == '-' && all isDigit (tail str)) || all isDigit str

check :: [String] -> Bool
check [] = True
check (x:xs) = if myIsDigit x == False
    then False
    else check xs

myError :: [String] -> IO ()
myError [] = putStrLn "KO => no sorted or no numbers or bad command" >>
    exitWith (ExitFailure 84)
myError x = putStrLn "OK" >> exitWith ExitSuccess

checkError :: [String] -> IO ()
checkError [] = putStrLn "OK" >> exitWith ExitSuccess
checkError list | check list == False = putStrLn "KO => no only int" >>
        exitWith (ExitFailure 84)
    | otherwise = return ()

main :: IO ()
main = do
    command <- getLine
    list <- getArgs
    checkError list
    let x = myComp list (myParse (split command) (list, []))
    myError x
