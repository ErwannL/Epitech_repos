/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD07pm-erwann.laplante
** File description:
** Parts
*/

#ifndef PARTS_HPP_
    #define PARTS_HPP_

    #include <iostream>

    class Arms {
        std::string _serial;
        bool _functionnal;

        public:
            Arms(std::string serial = "A-01", bool functional = true);
            ~Arms();
            bool isFunctional() const;
            std::string serial() const;
            void informations() const;
    };

    class Legs {
        std::string _serial;
        bool _functionnal;

        public:
            Legs(std::string serial = "L-01", bool functional = true);
            ~Legs();
            bool isFunctional() const;
            std::string serial() const;
            void informations() const;
    };

    class Head {
        std::string _serial;
        bool _functionnal;

        public:
            Head(std::string serial = "H-01", bool functional = true);
            ~Head();
            bool isFunctional() const;
            std::string serial() const;
            void informations() const;
    };

#endif /* !PARTS_HPP_ */
