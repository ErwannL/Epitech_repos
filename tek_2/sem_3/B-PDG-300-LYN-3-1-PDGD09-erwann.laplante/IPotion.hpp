/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD09-erwann.laplante
** File description:
** IPotion
*/

#ifndef IPOTION_HPP_
    #define IPOTION_HPP_

    class IPotion {
        public:
            virtual ~IPotion() = default;

            virtual int getValue() const = 0;
            virtual int getType() const = 0;
    };

#endif /* !IPOTION_HPP_ */
