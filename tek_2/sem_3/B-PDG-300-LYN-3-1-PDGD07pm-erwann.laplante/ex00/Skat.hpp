/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD07pm-erwann.laplante
** File description:
** Skat
*/

#ifndef SKAT_HPP_
    #define SKAT_HPP_

    #include <iostream>

    class Skat
    {
        public :
            Skat (const std::string &name, int stimPaks);
            Skat();
            ~ Skat ();

            int &stimPaks ();
            const std::string &name ();

            void shareStimPaks (int number, int &stock);
            void addStimPaks (unsigned int number);
            void useStimPaks ();
            void status ();

        private :
            std::string _name;
            int _stimPaks;
    };

#endif /* !SKAT_HPP_ */
