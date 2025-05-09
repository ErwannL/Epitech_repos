/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** My_4011
*/

#ifndef MY_4011_HPP_
    #define MY_4011_HPP_

    #include "And.hpp"
    #include "Not.hpp"

    class My_4011 : virtual public And, Not {
        public:
            My_4011();
            ~My_4011();

            void simulation(size_t first, nts::Tristate new_state, size_t pin);

        protected:
        private:
    };

#endif /* !MY_4011_HPP_ */
