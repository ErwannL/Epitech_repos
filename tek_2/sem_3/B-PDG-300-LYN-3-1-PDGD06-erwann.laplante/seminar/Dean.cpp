/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD06-erwann.laplante
** File description:
** Dean
*/

#include "Dean.hpp"

Dean::Dean(std::string new_name)
{
    name = new_name;
    working_status = 0;
    std::cout << "Dean " << name << ": I'm Dean " << name << "! How do you do, fellow kids?" << std::endl;
}

Dean::~Dean()
{
    std::cout << "Dean  "<< name <<": Time to go home." << std::endl;
}

void Dean::teachStudent(Student *student, std::string lesson)
{
    bool learn = student->learn(lesson);
    std::ofstream file(student->getName() + ".drink");
    std::string drink[5] = {"Cristaline", "Monster", "Evian", "Red Bull", "Sierra Springs"};

    if (learn == true)
        return;
    std::cout << "Dean " << name << ": All work and no play makes " << student->getName() << " a dull student." << std::endl;
    file << drink[std::rand() % 5] << std::endl;
    file.close();
}

void Dean::timeCheck(void)
{
    if (working_status == 0) {
        working_status = 1;
        std::cout << "Dean " << name << ": Where is everyone ?" << std::endl;;
    } else {
        working_status = 0;
        std::cout << "Dean " << name << ": Don ' t forget to close the windows when you leave " << std::endl;;
    }
}
