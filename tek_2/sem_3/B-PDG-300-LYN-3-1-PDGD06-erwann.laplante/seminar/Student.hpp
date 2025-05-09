/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD06-erwann.laplante
** File description:
** Student
*/

#ifndef STUDENT_HPP_
    #define STUDENT_HPP_

    #include <string>
    #include <iostream>

    class Student {
        std::string name;
        int energy;
        public:
            Student(std::string new_name);
            ~Student();
            bool learn(std::string text);
            void drink(std::string drink);
            std::string getName(void);
    };

#endif /* !STUDENT_HPP_ */
