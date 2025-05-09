{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-LYN-4-1-wolfram-erwann.laplante
-- File description:
-- test
-}

import Test.HUnit
import Control.Exception

import Lib
import Argument
import Error
import Line

testAddEndSpace :: Test
testAddEndSpace = TestCase (assertEqual "calcule first line failed" "*  "
    (addEndSpace "*" 3))

testStartLine :: Test
testStartLine = TestCase (assertEqual "calcule first line failed" "**  *"
    (startLine "***" 30))

testLine :: Test
testLine = TestCase (assertEqual "generate line failed" "**  *" (line "  ***  "
    "   **** "))

testGenerateRule :: Test
testGenerateRule = TestCase (assertEqual "generation rule failed" "  * "
    (generateRule "0010"))

testGetRes :: Test
testGetRes = TestCase (assertEqual "calcule line failed" '2' (getRes '*' ' '
    '*' "012345678"))

testCheckArgs :: Test
testCheckArgs = TestCase (assertEqual "test all argument parsing failed" (Param
    (Just 33) 12 85 522 (-9) "*") (checkArgs ["--rule", "33", "--start", "12",
        "--lines", "85", "--window", "522", "--move", "-9"]))

testArgsBadArg :: Test
testArgsBadArg = TestCase $ do
    result <- try (evaluate (args "lol" (Just "2") (Param Nothing 0 (-1) 80 0
        "*"))) :: IO (Either SomeException (Param))
    case result of
        Left ex -> assertEqual "test bad argument failed" (show (BadArg "lol"))
            (show ex)
        Right _ -> assertFailure "Unknown problem"

testArgsNothing :: Test
testArgsNothing = TestCase $ do
    result <- try (evaluate (args "lol" Nothing (Param Nothing 0 (-1) 80 0
        "*"))) :: IO (Either SomeException (Param))
    case result of
        Left ex -> assertEqual "test no string failed" (show (BadNum "lol"))
            (show ex)
        Right _ -> assertFailure "Unknown problem"

testArgsGenerate :: Test
testArgsGenerate = TestCase (assertEqual "test argument generate parsing failed"
    (Param Nothing 0 (-1) 80 0 "**  *") (args "--generate" (Just "**  *") (Param
        Nothing 0 (-1) 80 0 "*")))

testArgsMove :: Test
testArgsMove = TestCase (assertEqual "test argument move parsing failed"
    (Param Nothing 0 (-1) 80 (-33) "*") (args "--move" (Just "-33") (Param
        Nothing 0 (-1) 80 0 "*")))

testArgsWindow :: Test
testArgsWindow = TestCase (assertEqual "test argument window parsing failed"
    (Param Nothing 0 (-1) 122 0 "*") (args "--window" (Just "122") (Param
        Nothing 0 (-1) 80 0 "*")))

testArgsLines :: Test
testArgsLines = TestCase (assertEqual "test argument lines parsing failed"
    (Param Nothing 0 35 80 0 "*") (args "--lines" (Just "35") (Param Nothing 0
        (-1) 80 0 "*")))

testArgsStart :: Test
testArgsStart = TestCase (assertEqual "test argument start parsing failed"
    (Param Nothing 12 (-1) 80 0 "*") (args "--start" (Just "12") (Param Nothing
        0 (-1) 80 0 "*")))

testArgsRule :: Test
testArgsRule = TestCase (assertEqual "test argument rule parsing failed" (Param
    (Just 3) 0 (-1) 80 0 "*") (args "--rule" (Just "3") (Param Nothing 0 (-1)
        80 0 "*")))

testCheckRuleNeg :: Test
testCheckRuleNeg = TestCase $ do
    result <- try (evaluate (checkRule (-5))) :: IO (Either SomeException
        (Maybe Int))
    case result of
        Left ex -> assertEqual "test negative rule failed" (show (BadRule
            (-5))) (show ex)
        Right _ -> assertFailure "Unknown problem"

testCheckRuleBig :: Test
testCheckRuleBig = TestCase $ do
    result <- try (evaluate (checkRule 789)) :: IO (Either SomeException (Maybe
        Int))
    case result of
        Left ex -> assertEqual "test big rule failed" (show (BadRule 789))
            (show ex)
        Right _ -> assertFailure "Unknown problem"

testCheckRule :: Test
testCheckRule = TestCase (assertEqual "test rule failed" (Just 4) (checkRule
    4))

testParameters :: Test
testParameters = TestCase (assertEqual "initial values failed" (Param Nothing 0
    (-1) 80 0 "*") parameters)

testSetMove :: Test
testSetMove = TestCase (assertEqual "move adder failed" "     lol" (setMove 5
    "lol"))

testBeforeSpace :: Test
testBeforeSpace = TestCase (assertEqual "add space failed" "   " (beforeSpace 9
    "777"))

testFindMid :: Test
testFindMid = TestCase (assertEqual "mid finder failed" "234" (findMid "12345"
    3))

testBinRule :: Test
testBinRule = TestCase (assertEqual "rule generator failed" "01110010" (binRule
    114))

testExtend :: Test
testExtend = TestCase (assertEqual "extension string failed" "00123456"
    (extend "123456"))

testFromDigits :: Test
testFromDigits = TestCase (assertEqual "join number failed" 010001 (fromDigits
    [0,1,0,0,0,1]))

testToBin :: Test
testToBin = TestCase (assertEqual "binary convertion failed" [0,1,0,0,0,1]
    (toBin 17))

testGetPos :: Test
testGetPos = TestCase (assertEqual "position string failed" 'h' (getPos
    "hello" 0))

testCheckValueNothing :: Test
testCheckValueNothing = TestCase (assertEqual "bad value verification failed"
    Nothing (checkValue "a"))

testCheckValue :: Test
testCheckValue = TestCase (assertEqual "value verification failed" (Just "1")
    (checkValue "1"))

testMyIsDigitNeg :: Test
testMyIsDigitNeg = TestCase (assertEqual "negative digit verification failed"
    True (myIsDigit "-4"))

testMyIsDigitBad :: Test
testMyIsDigitBad = TestCase (assertEqual "bad digit verification failed" False
    (myIsDigit "a"))

testMyIsDigitGood :: Test
testMyIsDigitGood = TestCase (assertEqual "normal digit verification failed"
    True (myIsDigit "2"))

initTest :: Test
initTest = TestList [testMyIsDigitGood, testMyIsDigitBad, testMyIsDigitNeg,
    testCheckValue, testCheckValueNothing, testGetPos, testToBin,
    testFromDigits, testExtend, testBinRule, testFindMid, testBeforeSpace,
    testSetMove, testParameters, testCheckRule, testCheckRuleBig,
    testCheckRuleNeg, testArgsRule, testArgsStart, testArgsLines,
    testArgsWindow, testArgsMove, testArgsGenerate, testArgsNothing,
    testArgsBadArg, testCheckArgs, testGetRes, testGenerateRule, testLine,
    testStartLine, testAddEndSpace]

main :: IO Counts
main = runTestTT initTest
