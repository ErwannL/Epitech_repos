{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-LYN-4-1-wolfram-erwann.laplante
-- File description:
-- Main
-}

module Main (main) where

import System.Environment
import Control.Exception

import Argument
import Error
import Line

main :: IO ()
main = handle myError (getArgs >>= (printLines . checkArgs))
