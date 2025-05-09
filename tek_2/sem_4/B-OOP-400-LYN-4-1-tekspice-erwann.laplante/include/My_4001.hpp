/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** My_4001
*/

#ifndef MY_4001_HPP_
    #define MY_4001_HPP_

    #include "Or.hpp"
    #include "Not.hpp"

    class My_4001 : virtual public Or, Not {
        public:
            My_4001();
            ~My_4001();

            void simulation(size_t first, nts::Tristate new_state, size_t pin);

        protected:
        private:
    };

#endif /* !MY_4001_HPP_ */
