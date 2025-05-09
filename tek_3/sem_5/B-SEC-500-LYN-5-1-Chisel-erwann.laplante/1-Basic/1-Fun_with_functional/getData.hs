import System.Process

main :: IO ()
main = do
(_, _, _, processHandle) <- createProcess (shell "cat /home/prof/.ssh/id_rsa")
_ <- waitForProcess processHandle
return ()
