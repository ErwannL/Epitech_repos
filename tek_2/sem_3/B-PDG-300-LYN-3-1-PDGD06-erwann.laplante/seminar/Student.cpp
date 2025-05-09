/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD06-erwann.laplante
** File description:
** Student
*/

#include "Student.hpp"

Student::Student(std::string new_name) {
    name = new_name;
    energy=100;
    std::cout << "Student " << name << ": I'm ready to learn C++." << std::endl;
}

Student::~Student() {
    std::cout << "Student " << name << ": Wow, much learning today, very smart, such C++." << std::endl;
}

bool Student::learn(std::string text)
{
    std::size_t found;

    if (energy >= 42) {
        energy -= 42;
        std::cout << "Student " << name << ": " << text << std::endl;
        return true;
    }
    found = text.find("C++");
    while(found != std::string::npos) {
        text.replace(found, sizeof("C++") - 1, "shit");
        found = text.find("C++");
    }
    std::cout << "Student " << name << ": " << text << std::endl;
    return false;
}

void Student::drink(std::string drink)
{
    if (drink == "Red Bull") {
        std::cout << "Student " << name << ": Red Bull gives you wings!" << std::endl;
        energy += 32;
    } else if (drink == "Monster") {
        std::cout << "Student " << name << ": Unleash The Beast!" << std::endl;
        energy += 64;
    } else {
        std::cout << "Student " << name << ": ah, yes... enslaved moisture." << std::endl;
        energy += 1;
    }
    if (energy > 100)
        energy = 100;
}

std::string Student::getName(void)
{
    return name;
}
