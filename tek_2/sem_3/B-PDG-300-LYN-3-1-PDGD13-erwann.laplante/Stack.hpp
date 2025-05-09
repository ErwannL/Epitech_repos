/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD13-erwann.laplante
** File description:
** Stack
*/

#ifndef STACK_HPP_
    #define STACK_HPP_

    #include <iostream>
    #include <stack>

    class Stack {
        public:
            Stack();
            ~Stack();

            void push(double value);
            double pop();
            double top() const;

            void add();
            void sub();
            void mul();
            void div();

            class Error : public std::exception {
                public:
                    enum ErrorType {
                        EMPTY,
                        NOT_ENOUGH,
                        ZERO
                    };

                    Error(ErrorType erreur);
                    Error();
                    ~Error();

                    const char *what() const noexcept;

                    ErrorType type;
            };

        private:
            std::stack<double> _stack;
            Error error;
    };

#endif /* !STACK_HPP_ */
