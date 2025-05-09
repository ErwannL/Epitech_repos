/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD06-erwann.laplante
** File description:
** Assistant
*/

#ifndef ASSISTANT_HPP_
    #define ASSISTANT_HPP_

    #include <iostream>
    #include "Student.hpp"
    #include <fstream>
    #include <cstdio>
    #include <stdio.h>
    #include <string.h>

    class Assistant {
        int id;
        int working_status;
        public:
            Assistant(int new_id);
            ~Assistant();
            void giveDrink(Student *student, std::string drink);
            std::string readDrink(std::string student_name);
            void helpStudent(Student *student);
            void timeCheck(void);
    };

#endif /* !ASSISTANT_HPP_ */
