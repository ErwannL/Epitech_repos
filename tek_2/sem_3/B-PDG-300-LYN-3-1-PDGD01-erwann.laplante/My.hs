{-
-- EPITECH PROJECT, 2023
-- B-PDG-300-LYN-3-1-PDGD01-erwann.laplante
-- File description:
-- My
-}

mySucc :: Int -> Int
mySucc n = n + 1

myIsNeg :: Int -> Bool
myIsNeg n = if n < 0 then True else False

myAbs :: Int -> Int
myAbs n = if n < 0 then n * (-1) else n

myMin :: Int -> Int -> Int
myMin a b = if a < b then a else b

myMax :: Int -> Int -> Int
myMax a b = if a > b then a else b

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (x, _) = x

mySnd :: (a, b ) -> b
mySnd (_, x) = x

mySwap :: (a, b) -> (b, a)
mySwap (x, y) = (y, x)

myHead :: [a] -> a
myHead [] = error "empty list"
myHead (a:b) = a

myTail :: [a] -> [a]
myTail [] = error "empty list"
myTail (a:b) = b

myLength :: [a] -> Int
myLength [] = 0
myLength (_:x) = 1 + myLength x

myNth :: [a] -> Int -> a
myNth [] _ = error "out of range"
myNth (var:rest) 0 = var
myNth (_:rest) num = myNth rest (num - 1)

myTake :: Int -> [a] -> [a]
myTake _ [] = []
myTake 0 _ = []
myTake n (var:fin) = var:(myTake (n-1) fin)

myDrop :: Int -> [a] -> [a]
myDrop _ [] = []
myDrop 0 a = a
myDrop n (_:fin) = myDrop (n-1) fin

myAppend :: [a] -> [a] -> [a]
myAppend lista [] = lista
myAppend [] listb = listb
myAppend (var:lista) listb = var:myAppend lista listb

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (var:list) = myAppend (myReverse list) [var]

myInit :: [a] -> [a]
myInit x = if myLength x > 1
    then myTake ((myLength x)-1) x
    else error "empty list"

myLast :: [a] -> a
myLast [] = error "empty list"
myLast [n] = n
myLast (x:rest) = myLast rest

myZip :: [a] -> [b] -> [(a, b)]
myZip _ [] = []
myZip [] _ = []
myZip (n:lista) (num:listb) = (n,num):(myZip lista listb)

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((n,num):rest) = (n:lista, num:listb)
    where (lista,listb) = myUnzip rest

myMap :: (a -> b) -> [a] -> [b]
myMap fonction [] = []
myMap fonction (var:list) = (fonction var):(myMap fonction list)

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter fonction [] = []
myFilter fonction (var:list) = if (fonction var) == True
    then var:(myFilter fonction list)
    else (myFilter fonction list)

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl fonction num [] = num
myFoldl fonction num (var:list) = myFoldl fonction (fonction num var) list

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr fonction num [] = num
myFoldr fonction num (var:list) = fonction var (myFoldr fonction num list)