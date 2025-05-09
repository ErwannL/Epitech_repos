{-
-- EPITECH PROJECT, 2023
-- B-PDG-300-LYN-3-1-PDGD03-erwann.laplante
-- File description:
-- Tree
-}

data Tree a = Empty | Node (Tree a) a (Tree a) deriving (Show)
instance Functor Tree where
    fmap f Empty = Empty
    fmap f (Node left x right) = Node (fmap f left) (f x) (fmap f right)
instance Foldable Tree where
    foldr f val Empty = val
    foldr f val (Node left x right) = foldr f (f x (foldr f val right)) left

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree value Empty = Node Empty value Empty
addInTree value (Node tree_left x tree_right) | value == x =
    Node tree_left value tree_right
    | value > x = Node tree_left x (addInTree value tree_right)
    | otherwise = Node (addInTree value tree_left) x tree_right

listToTree :: Ord a => [a] -> Tree a
listToTree = addInTree `foldr` Empty

treeToList :: Tree a -> [a]
treeToList Empty = []
treeToList (Node l x r) = (treeToList l) ++ [x] ++ (treeToList r)

treeSort :: Ord a => [a] -> [a]
treeSort = treeToList . listToTree