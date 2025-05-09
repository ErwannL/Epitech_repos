{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-LYN-4-1-compressor-erwann.laplante
-- File description:
-- Error
-}

module Error (checkErrors) where

import Control.Exception
import System.Exit
import Control.Monad

import Algo
import Exit
import Lib

startParser :: [String] -> IO ()
startParser args = either
    (\err -> print (err :: SomeException) >> exitFailure)
    (\_ -> exitSuccess) =<< (try
        (parser args :: IO ()) :: IO (Either SomeException ()))

checkErrors :: [String] -> IO ()
checkErrors args = case args of
    ["-n", n, "-l", l, "-f", f] -> do
        unless (length args == 6) $ exitHelp
        unless (isNum n) $ exitHelp
        unless (isFloat l) $ exitHelp
        unless (f /= "") $ exitHelp
        startParser (onlyArgs args)
    _ -> exitHelp
    where onlyArgs = filter (\x -> head x /= '-')
