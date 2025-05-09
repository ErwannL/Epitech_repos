/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD10-erwann.laplante
** File description:
** FruitUtils
*/

#ifndef FRUITUTILS_HPP_
    #define FRUITUTILS_HPP_

    #include "FruitBox.hpp"

    class FruitUtils {
        public:
            FruitUtils();
            ~FruitUtils();

            static void sort(FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus, FruitBox &berry);
    };

    

#endif /* !FRUITUTILS_HPP_ */
