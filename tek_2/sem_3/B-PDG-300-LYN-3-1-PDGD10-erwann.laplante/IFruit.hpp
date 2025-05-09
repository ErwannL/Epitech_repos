/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD10-erwann.laplante
** File description:
** IFruit
*/

#ifndef IFRUIT_HPP_
    #define IFRUIT_HPP_

    #include <iostream>

    class IFruit {
        public:
            virtual ~IFruit() = default;

            virtual unsigned int getVitamins() const = 0;
            virtual std::string getName() const = 0;
            virtual bool isPeeled() const = 0;

            virtual void peel() = 0;
    };

    std::ostream &operator<<(std::ostream &stream, IFruit const &fruit);

#endif /* !IFRUIT_HPP_ */
