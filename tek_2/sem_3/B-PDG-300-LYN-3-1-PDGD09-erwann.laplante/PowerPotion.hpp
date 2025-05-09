/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD09-erwann.laplante
** File description:
** PowerPotion
*/

#ifndef POWERPOTION_HPP_
    #define POWERPOTION_HPP_

    #include "IPotion.hpp"

    class PowerPotion : virtual public IPotion {
        public:
            PowerPotion();
            ~PowerPotion();

            int getValue() const;
            int getType() const;

        private:
            int value = 50;
            int type = 2;
    };

#endif /* !POWERPOTION_HPP_ */
