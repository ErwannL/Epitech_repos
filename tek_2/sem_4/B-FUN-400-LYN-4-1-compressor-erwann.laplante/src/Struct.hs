{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-LYN-4-1-compressor-erwann.laplante
-- File description:
-- Lib
-}

module Struct (Data(..)) where

data Data = Data {
    order :: [[Int]],
    randArr :: [[Float]],
    pixelList :: [[Int]],
    tabEucli :: [Float],
    tabRandEucli :: [Float],
    tabOldRandEucli :: [Float],
    tabNewRandEucli :: [Float],
    tabRand :: [Int],
    diff :: Float,
    i :: Int,
    j :: Int,
    backup :: Int
} deriving (Show)
