{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-LYN-4-1-wolfram-erwann.laplante
-- File description:
-- Line
-}

module Line (getRes, generateRule, line, startLine, loopLines,
    printLines) where

import Control.Exception
import Text.Printf

import Lib
import Argument
import Error

getRes :: Char -> Char -> Char -> String -> Char
getRes ' ' ' ' ' ' str = getPos str 7
getRes ' ' ' ' '*' str = getPos str 6
getRes ' ' '*' ' ' str = getPos str 5
getRes ' ' '*' '*' str = getPos str 4
getRes '*' ' ' ' ' str = getPos str 3
getRes '*' ' ' '*' str = getPos str 2
getRes '*' '*' ' ' str = getPos str 1
getRes '*' '*' '*' str = getPos str 0
getRes _ _ _ _ = throw Unknown

generateRule :: String -> String
generateRule ('0':xs) = " " ++ (generateRule xs)
generateRule ('1':xs) = "*" ++ (generateRule xs)
generateRule (_) = []

line :: String -> String -> String
line str rule | length str < 3 = []
              | otherwise = [(getRes (getPos str 0) (getPos str 1) (getPos str
                    2) rule)] ++ (line (tail str) rule)

startLine :: String -> Int -> String
startLine x rule = line ("  " ++ x ++ "  ") (generateRule (binRule rule))

loopLines :: Param -> String -> Int -> String
loopLines (Param Nothing _ _ _ _ _) _ _ = throw NoRule
loopLines (Param _ 0 1 _ _ _) _ _ = ""
loopLines (Param (Just rule) 0 myLines window move first_line) l win =
    (addEndSpace (setMove move (findMid ((beforeSpace window first_line) ++
        (startLine l rule)) win)) win) ++ "\n" ++ (loopLines (Param (Just rule)
        0 (myLines - 1) (window - 2) move first_line) (startLine l rule) win)
loopLines (Param (Just rule) start myLines window move first_line) l win =
    (loopLines (Param (Just rule) (start - 1) myLines (window - 2) move
        first_line) (startLine l rule) win)

infinitLoop :: Param -> String -> Int -> IO ()
infinitLoop (Param Nothing _ _ _ _ _) _ _ = throw NoRule
infinitLoop (Param (Just rule) 0 myLines window move first_line) l win = printf
    "%s" ((addEndSpace(setMove move (findMid ((beforeSpace window first_line)
        ++ (startLine l rule)) win)) win) ++ "\n") >> (infinitLoop (Param (Just
        rule) 0 myLines (window - 2) move first_line) (startLine l rule) win)
infinitLoop (Param (Just rule) start myLines window move first_line) l win =
    (infinitLoop (Param (Just rule) (start - 1) myLines (window - 2) move
        first_line) (startLine l rule) win)

printLines :: Param -> IO()
printLines (Param Nothing _ _ _ _ _) = throw NoRule
printLines (Param (Just rule) 0 (-1) window move first_line) = printf "%s\n"
    (addEndSpace (setMove move ((findMid (beforeSpace window first_line)
        window) ++ first_line)) window) >> infinitLoop (Param (Just rule) 0
        (-1) (window - 2) move first_line) first_line window
printLines (Param (Just rule) start (-1) window move first_line) = infinitLoop
    (Param (Just rule) (start - 1) (-1) (window - 2) move first_line)
        first_line window
printLines (Param (Just rule) 0 myLines window move first_line) = printf
    "%s\n%s" (addEndSpace (setMove move ((findMid (beforeSpace window
        first_line) window) ++ first_line)) window) (loopLines (Param (Just
        rule) 0 myLines (window - 2) move first_line) first_line window)
printLines (Param (Just rule) start myLines window move first_line) = printf
    "%s" (loopLines (Param (Just rule) (start - 1) (myLines + 1) (window - 2)
        move first_line) first_line window)
