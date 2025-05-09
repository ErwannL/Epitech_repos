/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** My_4069
*/

#ifndef MY_4069_HPP_
    #define MY_4069_HPP_

    #include "Not.hpp"

    class My_4069 : virtual public Not {
        public:
            My_4069();
            ~My_4069();

            void simulation(size_t first, nts::Tristate new_state, size_t pin);

        protected:
        private:
    };

#endif /* !MY_4069_HPP_ */
