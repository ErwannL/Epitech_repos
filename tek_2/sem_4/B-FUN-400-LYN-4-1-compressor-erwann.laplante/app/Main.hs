{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-LYN-4-1-compressor-erwann.laplante
-- File description:
-- Main
-}

module Main (main) where

import System.Environment

import Error

main :: IO ()
main = getArgs >>= checkErrors
