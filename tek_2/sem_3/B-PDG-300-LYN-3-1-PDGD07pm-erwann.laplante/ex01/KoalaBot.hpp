/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD07pm-erwann.laplante
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
    #define KOALABOT_HPP_

    #include <iostream>
    #include "Parts.hpp"

    class KoalaBot {
        Arms _arms;
        Legs _legs;
        Head _head;
        std::string _serial = "Bob-01";;

        public:
            KoalaBot();
            ~KoalaBot();
            void setParts(Arms arms);
            void setParts(Legs legs);
            void setParts(Head head);
            void swapParts(Arms &arms);
            void swapParts(Legs &legs);
            void swapParts(Head &head);
            void informations() const;
            bool status() const;
    };

#endif /* !KOALABOT_HPP_ */
