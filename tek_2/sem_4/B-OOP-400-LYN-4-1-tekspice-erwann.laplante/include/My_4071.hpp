/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** My_4071
*/

#ifndef MY_4071_HPP_
    #define MY_4071_HPP_

    #include "Or.hpp"

    class My_4071 : virtual public Or {
        public:
            My_4071();
            ~My_4071();

            void simulation(size_t first, nts::Tristate new_state, size_t pin);

        protected:
        private:
    };

#endif /* !MY_4071_HPP_ */
