/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD08-erwann.laplante
** File description:
** Carrier
*/

#ifndef CARRIER_HPP_
    #define CARRIER_HPP_

    #include "Droid.hpp"

    class Carrier {
        std::string Id = "";
        size_t Energy = 300;
        const size_t Attack = 100;
        const size_t Toughness = 90;
        size_t Speed = 0;
        Droid *Droids[5];

        public:
            Carrier(std::string id);
            ~Carrier();

            std::string getId() const;
            size_t getEnergy() const;
            size_t getSpeed() const;

            void setId(std::string new_id);
            void setEnergy(size_t  new_energy);
            void setSpeed(size_t new_speed);

            Carrier &operator<<(Droid *&droid);
            Carrier &operator>>(Droid *&droid);
            Droid *&operator[](const size_t &where);
            Carrier &operator~();
            bool operator()(const int &x, const int &y);
            Carrier &operator<<(size_t &want_reload);

            std::ostream &informations(std::ostream &stream) const;
    };
    std::ostream &operator<<(std::ostream &stream, Carrier const &carrier);

#endif /* !CARRIER_HPP_ */
