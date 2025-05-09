{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-LYN-4-1-wolfram-erwann.laplante
-- File description:
-- Error
-}

module Error (ExceptionType (..), myError) where

import Control.Exception
import System.Exit

data ExceptionType = BadArg String | NumArg | BadNum String | NoRule | Empty |
    Help | BadRule Int | EmptyList | Unknown deriving (Show)
instance Exception ExceptionType

nextPrintHelp :: String
nextPrintHelp = "(default = infinity)\n" ++
    "\t--window window          The number of cells to display on each line" ++
        "( = line width) (default = 80)\n" ++
    "\t--move move              Translation to apply on the window." ++
        "If move < 0 -> translated to the left else translated to the" ++
            "right. (default = 0)\n" ++
    "\t--generate first_line    Set the first line of the programme." ++
        "(default = \"*\") /!\\Need to be writtend between\""

printHelp :: String
printHelp = "USAGE\n" ++
    "\t./wolfram -h\n" ++
    "\t./wolfram --rule rule [--start start] [--lines lines]" ++
        "[--window window] [--move move] [--generate first_line]\n" ++
    "DESCRIPTION\n" ++
    "\t--rule rule              The ruleset to use\n" ++
    "\t--start start            The generation number at which to start the" ++
        "display (default = 0)\n" ++
    "\t--lines lines            The number of lines to display" ++
    nextPrintHelp

myError :: ExceptionType -> IO()
myError (BadArg arg) = putStrLn ("Bad argument = " ++ arg ++ "\nTrye -h") >>
    exitWith (ExitFailure 84)
myError NumArg = putStrLn "Invalid number of argument" >>
    exitWith (ExitFailure 84)
myError (BadNum "wolfram") = putStr ("Unexpected argument, ") >>
    putStr ("you've probably forgotten the \"\n") >> exitWith (ExitFailure 84)
myError (BadNum num) = putStrLn ("Bad number after " ++ num) >>
    exitWith (ExitFailure 84)
myError NoRule = putStrLn "No rule defined" >> exitWith (ExitFailure 84)
myError Empty = putStrLn "Need a rule" >> exitWith (ExitFailure 84)
myError Help = putStrLn printHelp >> exitSuccess
myError (BadRule rule) = putStrLn ("Bad rule = " ++ (show rule)) >>
    exitWith (ExitFailure 84)
myError EmptyList = putStrLn "Can't do operation in an empty list!" >>
    exitWith (ExitFailure 84)
myError Unknown = putStrLn "Unknown error occured!" >>
    exitWith (ExitFailure 84)
