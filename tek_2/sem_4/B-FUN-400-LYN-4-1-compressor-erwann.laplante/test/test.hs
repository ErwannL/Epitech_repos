{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-LYN-4-1-compressor-erwann.laplante
-- File description:
-- Spec
-}

import Test.HUnit

import Lib

testToInt :: Test
testToInt = TestCase (assertEqual "convert float to int" 3 (toInt 3.28))

testToFloat :: Test
testToFloat = TestCase (assertEqual "convert int to float" 7.00 (toFloat 7))

testToListFloat :: Test
testToListFloat = TestCase (assertEqual "convert list int to list float"
    [5.00, 4.00, 8.00] (toListFloat [5, 4, 8]))

testUpdateMatrix :: Test
testUpdateMatrix = TestCase (assertEqual "update matrix" [[1,2], [5,4]]
    (updateMatrix [[1,2], [3,4]] 5 (1,0) :: [[Int]]))

testStringToInt :: Test
testStringToInt = TestCase (assertEqual "convert string to int" 88
    (stringToInt "88"))

testIsNumTrue :: Test
testIsNumTrue = TestCase (assertEqual "verify string is num => true" True
    (isNum "88"))

testIsNumFalse :: Test
testIsNumFalse = TestCase (assertEqual "verify string is num => false" False
    (isNum "8a"))

testIsFloatTrue :: Test
testIsFloatTrue = TestCase (assertEqual "verify string is float => true" True
    (isFloat "88.88"))

testIsFloatFalse :: Test
testIsFloatFalse = TestCase (assertEqual "verify string is float => false"
    False (isFloat "8a.zz"))

testSplitEvery :: Test
testSplitEvery = TestCase (assertEqual "test split"
    [["a", "b", "c", "d"], ["e"]] (splitEvery 4 ["a", "b", "c", "d", "e"]))

initTest :: Test
initTest = TestList [testToInt, testToFloat, testToListFloat, testUpdateMatrix,
    testStringToInt, testIsNumTrue, testIsNumFalse, testIsFloatTrue,
    testIsFloatFalse, testSplitEvery]

main :: IO Counts
main = runTestTT initTest
