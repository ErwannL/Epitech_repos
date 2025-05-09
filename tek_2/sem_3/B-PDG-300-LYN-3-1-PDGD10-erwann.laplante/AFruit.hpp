/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD10-erwann.laplante
** File description:
** AFruit
*/

#ifndef AFRUIT_HPP_
    #define AFRUIT_HPP_

    #include "IFruit.hpp"

    class AFruit : virtual public IFruit {
        public:
            AFruit();
            ~AFruit();

            unsigned int getVitamins() const;
            std::string getName() const;
            bool isPeeled() const;

            void peel();

        protected:
            int _vitamins;
            std::string _name;
            bool _peeled = false;
    };

#endif /* !AFRUIT_HPP_ */
