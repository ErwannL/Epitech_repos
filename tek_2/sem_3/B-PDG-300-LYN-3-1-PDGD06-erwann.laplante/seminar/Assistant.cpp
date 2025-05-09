/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD06-erwann.laplante
** File description:
** Assistant
*/

#include "Assistant.hpp"

Assistant::Assistant(int new_id)
{
    id = new_id;
    working_status = 0;
    std::cout << "Assistant " << id << ": 'morning everyone *sip coffee*" << std::endl;
}

Assistant::~Assistant()
{
    std::cout << "Assistant " << id << ": see you tomorrow at 9.00 *sip coffee*" << std::endl;
}

void Assistant::giveDrink(Student *student, std::string drink)
{
    std::cout << "Assistant " << id << ": drink this, " << student->getName() << " *sip coffee*" << std::endl;
    student->drink(drink);
}

std::string Assistant::readDrink(std::string student_name)
{
    std::string string_file_name = student_name + ".drink";
    std::ifstream filename(string_file_name);
    std::string drink;
    int status;

    if (std::getline(filename, drink)) {
        std::cout << string_file_name << std::endl;
        status = remove(const_cast<char*>(string_file_name.c_str()));
        if(status == 0) {
            std::cout << "Assistant " << id << ": " << student_name << " needs a " << drink << " *sip coffee*" << std::endl;
            return drink;
        }
    }
    return "";
}

void Assistant::helpStudent(Student *student)
{
    std::string drink = readDrink(student->getName());

    if (drink == "")
        std::cout << "Assistant " << id << ": " << student->getName() << " seems fine *sip coffee*" << std::endl;
    else
        giveDrink(student, drink);
}

void Assistant::timeCheck(void)
{
    if (working_status == 0) {
        working_status = 1;
        std::cout << "Assistant " << id << ": Time to teach some serious business *sip coffee*" << std::endl;;
    } else {
        working_status = 0;
        std::cout << "Assistant " << id << ": Enough teaching for today *sip coffee*" << std::endl;;
    }
}
