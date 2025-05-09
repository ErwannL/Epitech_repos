/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD09-erwann.laplante
** File description:
** PoisonPotion
*/

#ifndef POISONPOTION_HPP_
    #define POISONPOTION_HPP_

    #include "IPotion.hpp"

    class PoisonPotion : virtual public IPotion {
        public:
            PoisonPotion();
            ~PoisonPotion();

            int getValue() const;
            int getType() const;

        private:
            int value = 50;
            int type = 1;
    };

#endif /* !POISONPOTION_HPP_ */
