{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-LYN-4-1-compressor-erwann.laplante
-- File description:
-- Algo
-}

module Algo (startAlgo, checkTabDiff, parser) where

import System.Random
import Control.Monad
import Data.List (genericIndex, (\\))
import Text.Printf

import Struct
import Lib

parser :: [FilePath] -> IO ()
parser args = let filePath = head (drop 2 args)
    in readFile filePath >>= return . map replace >>= return . words
        >>= return . map (\\ "(") >>= return . map (\\ ")")
        >>= return . map stringToInt >>= return . splitEvery 2
        >>= \list -> let struct = Data {order=[], tabEucli=[],
            tabRandEucli=[], tabOldRandEucli=[], tabNewRandEucli=[],
            randArr=[], pixelList=[], tabRand=(fillListRand list), diff=0, i=0,
            backup=0, j=0}
            in startAlgo args list struct
    where
        replace ',' = ' '
        replace c = c

loopPrintOrder :: Data -> Int -> Int -> IO ()
loopPrintOrder struct x y =
    let orderList :: [Int]
        orderList = genericIndex (order struct) x
        pixelIndex1 = genericIndex orderList y * 2
        pixelIndex2 = pixelIndex1 + 1
        pixelVals = pixelList struct
    in printf "(%i,%i) (%i,%i,%i)\n" (genericIndex (genericIndex pixelVals
        pixelIndex1) (0 :: Int)) (genericIndex (genericIndex pixelVals
        pixelIndex1) (1 :: Int)) (genericIndex (genericIndex pixelVals
        pixelIndex2) (0 :: Int)) (genericIndex (genericIndex pixelVals
        pixelIndex2) (1 :: Int)) (genericIndex (genericIndex pixelVals
        pixelIndex2) (2 :: Int)) >>
        if y + 1 /= length orderList
            then loopPrintOrder struct x (y + 1)
            else printf ""

printResult :: Data -> Int -> IO ()
printResult struct x = printf "--\n" >>
    let arr = randArr struct in
        printf "(%i,%i,%i)\n" (toInt(genericIndex (genericIndex arr x) (0 ::
            Int))) (toInt(genericIndex (genericIndex arr x) (1 :: Int))) (toInt
            (genericIndex (genericIndex arr x) (2 :: Int))) >>
        printf "-\n" >> loopPrintOrder struct x 0 >>
        if ((x + 1) /= (length arr))
            then printResult struct (x + 1)
            else printf ""

checkPrintResult :: [String] -> Data -> IO ()
checkPrintResult args struct | (noEmptyTab struct 0) == 1 = parser args
                             | otherwise = printResult struct 0

distEucli :: [Int] -> [Float] -> [Float] -> [Float]
distEucli _ tab [] = tab
distEucli firstTab tab [x2,y2,z2] =
    let [x1, y1, z1] = map fromIntegral firstTab :: [Float]
        distance = sqrt ((x1 - x2) ** 2 + (y1 - y2) ** 2 + (z1 - z2) ** 2)
    in tab ++ [distance]
distEucli firstTab tab (x2:y2:z2:rest) =
    let [x1, y1, z1] = map fromIntegral firstTab :: [Float]
        distance = sqrt ((x1 - x2) ** 2 + (y1 - y2) ** 2 + (z1 - z2) ** 2)
    in distEucli firstTab (tab ++ [distance]) rest
distEucli _ _ _ = error "Invalid input"

tabDistEucli :: [[Int]] -> [Float] -> Int -> [Float]
tabDistEucli list tab x | (x - 1) /= length list = tabDistEucli list (distEucli
    (genericIndex list 1 :: [Int]) tab (toListFloat (genericIndex list x)))
    (x + 2)
                        | otherwise = tab

tabRandDistEucli :: [[Int]] -> Data -> [Float] -> Int -> [Float]
tabRandDistEucli array struct tab x | x /= length (randArr struct) =
    let nextTab = distEucli (index array 1) tab (index (randArr struct) x)
    in tabRandDistEucli array struct nextTab (x + 1)
                                    | otherwise = tab
    where index liste xBis = head $ drop xBis liste

fillOldTabEucli :: Data -> [Float]
fillOldTabEucli struct | (length (tabOldRandEucli struct)) == 0 = (tabRandEucli
                        struct)
                       | otherwise = (tabNewRandEucli struct)

createTabEucli :: [String] -> [[Int]] -> [Int] -> [[Int]] -> Data -> IO ()
createTabEucli args list rand tab struct = let
    orderS = checkTabDiff rand struct {pixelList=list, order=(fillOrder [] 0
        (length rand)), tabEucli=(tabDistEucli list [] 1), tabRandEucli=(
        tabRandDistEucli list struct [] 0), diff=0, i=(-1), backup=0, j=(-1)}
    finalStruct = orderS {randArr=(upAverageOrder orderS (-1) (randArr
        orderS)), j=(length (order finalStruct)), tabOldRandEucli=(
        fillOldTabEucli orderS)}
    structs = finalStruct {tabNewRandEucli=(tabRandDistEucli list finalStruct
        [] 0)}
    in if (loopDiffOldNew args structs 0) == 0
        then checkPrintResult args structs
        else createTabEucli args list rand tab structs

loopDiffOldNew :: [String] -> Data -> Int -> Int
loopDiffOldNew args struct x | x == (length (tabNewRandEucli struct)) = 0
                             | (abs(index (tabOldRandEucli struct) x - index (
                                tabNewRandEucli struct) x)) < (read :: String
                                -> Float) (index args 1) = loopDiffOldNew args
                                struct (x+1)
                             | otherwise = 1
    where
        index list xBis = head $ drop xBis list

modifMatrixAverage :: Int -> Float -> Float -> Float -> [[Float]] -> [[Float]]
modifMatrixAverage x r g b tab = updateMatrix (updateMatrix (updateMatrix tab r
    (x, 0)) g (x, 1)) b (x, 2)

calculAverage :: Data -> [[Float]] -> Int -> Int -> Float -> Float -> Float
                -> [[Float]]
calculAverage struct tab x y r g b | y /= (length (index (order struct) x)) =
    calculAverage struct tab x (y + 1) (r + (toFloat (pixelList struct `index`
    ((index (order struct) x `index` y) * 2 + 1) `index` 0))) (g + (toFloat (
    pixelList struct `index` ((index (order struct) x `index` y) * 2 + 1)
    `index` 1))) (b + (toFloat (pixelList struct `index` ((index (order struct)
    x `index` y) * 2 + 1) `index` 2)))
                                   | otherwise = modifMatrixAverage x (r /
    (toFloat(length (index (order struct) x)))) (g / (toFloat(length (index (
    order struct) x)))) (b / (toFloat(length (index (order struct) x)))) tab
    where
        index liste xBis = head $ drop xBis liste

upAverageOrder :: Data -> Int -> [[Float]] -> [[Float]]
upAverageOrder struct nb tab | (nb + 1) /= (length (order struct)) && (length
                                (index (order struct) (nb + 1))) /= 0 =
                                upAverageOrder struct (nb + 1) (calculAverage
                                struct tab (nb + 1) 0 0 0 0)
                             | (nb + 1) /= (length (order struct)) =
                                upAverageOrder struct (nb + 1) tab
                             | otherwise = tab
    where
        index list x = head $ drop x list

setupUpTabDif :: Data -> Data
setupUpTabDif struct = updateStruct struct diffValue backupValue
    where
        diffValue = abs ((tabEucli struct `index` i struct) - (tabRandEucli
            struct `index` j struct))
        backupValue = j struct
        updateStruct s dVal bVal | dVal <= (diff s) = s {diff=dVal,
                                        backup=bVal}
                                 | otherwise = s
        index list x = head $ drop x list

appendOrder :: Data -> [[Int]] -> [[Int]]
appendOrder struct tab = let (beginning, end) = splitAt (backup struct) tab
                             desired = head end
                             desired' = (i struct) : desired
                             end' = desired' : (tail end)
    in beginning ++ end'

updateTabDiff :: Data -> [Int] -> Data
updateTabDiff struct rand | ((j struct) + 1) /= (length rand) = updateTabDiff
                            (setupUpTabDif struct {j=((j struct)+1)}) rand
                          | otherwise = struct {order=(appendOrder struct
                            (order struct))}

checkTabDiff :: [Int] -> Data -> Data
checkTabDiff rand struct | ((i struct) + 1) /= (length (tabEucli struct)) = let
    nextElem = head (drop ((i struct) + 1) (tabEucli struct))
    myDiff = abs (nextElem - (head (tabRandEucli struct)))
    newStruct = struct {i=((i struct)+1), j=(-1), diff=myDiff}
                            in checkTabDiff rand (updateTabDiff newStruct rand)
                        | otherwise = struct

fillOrder :: [[Int]] -> Int -> Int -> [[Int]]
fillOrder myOrder x nb | x /= nb = fillOrder (myOrder ++ [[]]) (x + 1) nb
                       | otherwise = head (return myOrder)

getRandom :: [String] -> [[Int]] -> Int -> [Int] -> Data -> IO ()
getRandom args list nb lRand struct = let
                        genRandIdx = randomRIO (0, length (tabRand struct) - 1)
    in replicateM 1 genRandIdx >>= \randomList ->
        let randIdx = head randomList
            (tabRandLeft, randValue: tabRandRight) = splitAt randIdx
                (tabRand struct)
            newStruct = struct {tabRand=tabRandLeft++ tabRandRight,randArr=
                randArr struct++[ toListFloat( genericIndex list randValue)]}
        in if read (head args) /= nb
            then getRandom args list (nb + 1) (lRand ++ [randValue]) newStruct
            else createTabEucli args list (lRand ++ [randValue]) [[]] newStruct

startAlgo :: [FilePath] -> [[Int]] -> Data-> IO ()
startAlgo args list struct | (read :: String -> Float) (head (drop 1 args))
                            <= 0 = error "/!\\ the second argument must be > 0"
                           | (read :: String -> Int) (head args) * 2 > length
                            list = error "Error in list"
                           | otherwise = getRandom args list 1 [] struct
