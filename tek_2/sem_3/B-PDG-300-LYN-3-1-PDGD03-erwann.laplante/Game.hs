{-
-- EPITECH PROJECT, 2023
-- B-PDG-300-LYN-3-1-PDGD03-erwann.laplante
-- File description:
-- Game
-}

data Item = Sword | Bow | MagicWand deriving (Eq)
instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

data Mob =  Mummy | Skeleton Item | Witch (Maybe Item) deriving (Eq)
instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton x) = "skeleton holding a " ++ show x
    show (Witch Nothing) = "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just x)) = "witch holding a " ++ show x

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create "mummy" = Just(createMummy)
create "doomed archer" = Just(createArcher)
create "dead knight" = Just(createKnight)
create "witch" = Just(createWitch)
create "sorceress" = Just(createSorceress)
create _ = Nothing

equip :: Item -> Mob -> Maybe Mob
equip weapon Mummy = Nothing
equip weapon (Skeleton _) = Just(Skeleton weapon)
equip weapon (Witch _) = Just(Witch (Just weapon))

class HasItem mymob where
    getItem :: mymob -> Maybe Item
    getItem x = Nothing
    hasItem :: mymob -> Bool
    hasItem x = False
instance HasItem Mob where
    getItem Mummy = Nothing
    getItem (Skeleton x) = Just(x)
    getItem (Witch x) = x
    hasItem Mummy = False
    hasItem (Skeleton _) = True
    hasItem (Witch Nothing) = False
    hasItem (Witch _) = True