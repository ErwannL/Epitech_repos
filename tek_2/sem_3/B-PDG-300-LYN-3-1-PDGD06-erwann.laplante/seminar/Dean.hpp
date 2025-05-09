/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD06-erwann.laplante
** File description:
** Dean
*/

#ifndef DEAN_HPP_
    #define DEAN_HPP_

    #include <iostream>
    #include "Student.hpp"
    #include "Assistant.hpp"
    #include <iostream>
    #include <fstream>
    #include <cstdlib>

    class Dean {
        std::string name;
        int working_status;
        public:
            Dean(std::string new_name);
            ~Dean();
            void teachStudent(Student *student, std::string lesson);
            void timeCheck(void);
    };

#endif /* !DEAN_HPP_ */
