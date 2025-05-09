/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD09-erwann.laplante
** File description:
** ICharacter
*/

#ifndef ICHARACTER_HPP_
    #define ICHARACTER_HPP_

    #include <iostream>
    #include "IPotion.hpp"
    #include "PoisonPotion.hpp"
    #include "HealthPotion.hpp"
    #include "PowerPotion.hpp"

    class ICharacter {
        public:
            virtual ~ICharacter() = default;

            virtual const std::string &getName() const = 0;
            virtual int getPower() const = 0;
            virtual int getHp() const = 0;

            virtual int attack() = 0;
            virtual int special() = 0;
            virtual void rest() = 0;
            virtual void damage(int damage) = 0;

            virtual void drink(const HealthPotion& potion) = 0;
            virtual void drink(const PoisonPotion& potion) = 0;
            virtual void drink(const PowerPotion& potion) = 0;
            virtual void drink(const IPotion &potion) = 0;
    };

#endif /* !ICHARACTER_HPP_ */
