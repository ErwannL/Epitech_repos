/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-erwann.laplante
** File description:
** IGraphicals
*/

#ifndef GRAPHICALS_HPP_
    #define GRAPHICALS_HPP_

    #include "IArcade.hpp"

    namespace Arcade {
        class Graphicals {
            public:
                virtual ~Graphicals() = default;

                virtual Arcade::Type getTypeClass (void) = 0;
                virtual void createWindow(void) = 0;
                virtual void createBackground(void) = 0;
                virtual void setTexte(void) = 0;
                virtual std::string getKey(void) = 0;
                virtual void updateTexte(void) = 0;
                virtual void updateWindow(void) = 0;
                virtual void addName(std::string x) = 0;
                virtual bool isOpen(void) = 0;

            private:
            protected:
        };
    }

#endif /* !GRAPHICALS_HPP_ */
