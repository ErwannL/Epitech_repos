/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD09-erwann.laplante
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
    #define PRIEST_HPP_

    #include "Enchanter.hpp"

    class Priest : virtual public Enchanter {
        public:
            Priest(const std::string &name, int power);
            ~Priest();

            void rest();
    };

#endif /* !PRIEST_HPP_ */
