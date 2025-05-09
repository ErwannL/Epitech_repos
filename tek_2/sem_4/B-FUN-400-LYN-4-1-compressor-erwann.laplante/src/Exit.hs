{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-LYN-4-1-compressor-erwann.laplante
-- File description:
-- Exit
-}

module Exit (exitHelp) where

import System.Exit
import System.IO

exitWithErrorMessage :: String -> ExitCode -> IO a
exitWithErrorMessage str e = hPutStrLn stderr str >> exitWith e

printHelp :: String
printHelp = "USAGE: ./imageCompressor -n N -l L -f F\n\n\t" ++
    "N\tnumber of colors in the final image\n\t" ++
    "L\tconvergence limit\n\t" ++
    "F\tpath to the file containing the colors of the pixels"

exitHelp :: IO a
exitHelp = exitWithErrorMessage printHelp (ExitFailure 84)
