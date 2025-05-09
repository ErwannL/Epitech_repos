/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD09-erwann.laplante
** File description:
** HealthPotion
*/

#ifndef HEALTHPOTION_HPP_
    #define HEALTHPOTION_HPP_

    #include "IPotion.hpp"

    class HealthPotion : virtual public IPotion {
        public:
            HealthPotion();
            ~HealthPotion();

            int getValue() const;
            int getType() const;

        private:
            int value = 50;
            int type = 0;
    };

#endif /* !HEALTHPOTION_HPP_ */
