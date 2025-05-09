/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD08-erwann.laplante
** File description:
** Droid
*/

#ifndef DROID_HPP_
    #define DROID_HPP_

    #include <iostream>
    #include <string>

    class Droid {
        std::string Id;
        size_t Energy;
        const size_t Attack;
        const size_t Toughness;
        std::string *Status;
        public:
            Droid(std::string id = "");
            Droid(Droid const &droid);
            ~Droid();
            std::string getId() const;
            void setId(std::string id);
            size_t getEnergy() const;
            void setEnergy(size_t energy);
            std::string *getStatus() const;
            void setStatus(std::string *status);
            size_t getAttack() const;
            size_t getToughness() const;
            bool operator==(Droid const &droid) const;
            bool operator!=(Droid const &droid) const;
            Droid &operator<<(size_t &want_reload);
            Droid &operator=(Droid const &droid);
    };

    std::ostream &operator<<(std::ostream &stream, Droid const &droid);
#endif /* !DROID_HPP_ */
