/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** My_4030
*/

#ifndef MY_4030_HPP_
    #define MY_4030_HPP_

    #include "Xor.hpp"

    class My_4030 : virtual public Xor {
        public:
            My_4030();
            ~My_4030();

            void simulation(size_t first, nts::Tristate new_state, size_t pin);

        protected:
        private:
    };

#endif /* !MY_4030_HPP_ */
