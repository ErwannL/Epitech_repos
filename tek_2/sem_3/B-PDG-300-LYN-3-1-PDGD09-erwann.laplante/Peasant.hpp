/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD09-erwann.laplante
** File description:
** Peasant
*/

#ifndef PEASANT_HPP_
    #define PEASANT_HPP_

    #include "ICharacter.hpp"

    class Peasant : virtual public ICharacter {
        public:
            Peasant(const std::string &name, int power);
            ~Peasant();

            const std::string &getName() const;
            int getPower() const;
            int getHp() const;

            int attack();
            int special();
            void rest();
            void damage(int damage);

            void drink(const HealthPotion& potion);
            void drink(const PoisonPotion& potion);
            void drink(const PowerPotion& potion);
            void drink(const IPotion &potion);

        protected:
            const std::string _name;
            int _power;
            int _hp = 100;
    };

#endif /* !PEASANT_HPP_ */
