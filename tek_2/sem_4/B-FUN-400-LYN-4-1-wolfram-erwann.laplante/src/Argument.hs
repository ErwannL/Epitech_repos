{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-LYN-4-1-wolfram-erwann.laplante
-- File description:
-- Argument
-}

module Argument (Param (..), checkArgs, parameters, checkRule, args) where

import Control.Exception

import Error
import Lib

data Param = Param (Maybe Int) Int Int Int Int String deriving (Eq, Show)

parameters :: Param
parameters = Param Nothing 0 (-1) 80 0 "*"

checkRule :: Int -> Maybe Int
checkRule rule | rule < 0 || rule > 255 = throw (BadRule rule)
               | otherwise = (Just rule)

args :: String -> Maybe String -> Param -> Param
args arg Nothing _ = throw (BadNum arg)
args "--rule" (Just value) (Param _ start myLines window move first_line) =
    (Param (checkRule (read value :: Int)) start myLines window move
        first_line)
args "--start" (Just value) (Param rule _ myLines window move first_line) =
    (Param rule (read value :: Int) myLines window move first_line)
args "--lines" (Just value) (Param rule start _ window move first_line) =
    (Param rule start (read value :: Int) window move first_line)
args "--window" (Just value) (Param rule start myLines _ move first_line) =
    (Param rule start myLines (read value :: Int) move first_line)
args "--move" (Just value) (Param rule start myLines window _ first_line) =
    (Param rule start myLines window (read value :: Int) first_line)
args "--generate" (Just value) (Param rule start myLines window move _) =
    (Param rule start myLines window move value)
args arg _ _ = throw (BadArg arg)

checkArgs :: [String] -> Param
checkArgs [] = throw Empty
checkArgs ("-h":_) = throw Help
checkArgs ("--generate":value:[]) = args "--generate" (Just value) parameters
checkArgs ("--generate":value:xs) = args "--generate" (Just value) (checkArgs
    xs)
checkArgs (arg:value:[]) = args arg (checkValue value) parameters
checkArgs (arg:value:xs) = args arg (checkValue value) (checkArgs xs)
checkArgs (_:[]) = throw NumArg
