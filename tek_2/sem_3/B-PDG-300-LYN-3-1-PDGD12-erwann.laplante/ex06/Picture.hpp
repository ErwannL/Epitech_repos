/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD12-erwann.laplante
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
    #define PICTURE_HPP_

    #include <iostream>
    #include <fstream>
    #include <string>

    class Picture {
        public:
            std::string data;

            Picture();
            Picture(const std::string &file);
            ~Picture();

            bool getPictureFromFile(const std::string &file);

            Picture &operator=(Picture const &picture);
    };

#endif /* !PICTURE_HPP_ */
