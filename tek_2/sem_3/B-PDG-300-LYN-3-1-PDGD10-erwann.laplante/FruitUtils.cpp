/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD10-erwann.laplante
** File description:
** FruitUtils
*/

#include "FruitUtils.hpp"

FruitUtils::FruitUtils()
{
}

FruitUtils::~FruitUtils()
{
}

void FruitUtils::sort(FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus, FruitBox &berry)
{
    FruitBox new_unsorted(unsorted.getSize());
    IFruit *temp_fruit;

    for (unsigned int i = 0; i != unsorted.getSize(); i++)
        new_unsorted.pushFruit(unsorted.popFruit());
    for (unsigned int i = 0; i != new_unsorted.getSize(); i++) {
        temp_fruit = new_unsorted.popFruit();
        if (temp_fruit->getName() == "lemon") {
            if (lemon.pushFruit(temp_fruit) == false)
                unsorted.pushFruit(temp_fruit);
        } else if (temp_fruit->getName()  == "citrus" || temp_fruit->getName()  == "orange" || temp_fruit->getName()  == "blood orange" || temp_fruit->getName()  == "grapefruit") {
            if (citrus.pushFruit(temp_fruit) == false)
                unsorted.pushFruit(temp_fruit);
        } else if (temp_fruit->getName() == "berry" || temp_fruit->getName()  == "raspberry"|| temp_fruit->getName()  == "strawberry") {
            if (berry.pushFruit(temp_fruit) == false)
                unsorted.pushFruit(temp_fruit);
        } else
            unsorted.pushFruit(temp_fruit);
    }
}
