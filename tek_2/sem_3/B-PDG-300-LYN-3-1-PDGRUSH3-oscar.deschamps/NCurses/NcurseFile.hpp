/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGRUSH3-oscar.deschamps
** File description:
** NcurseFile
*/

#ifndef NCURSEFILE_HPP_
    #define NCURSEFILE_HPP_
    #include <iostream>
    #include <ncurses.h>
    #include "../IMonitorDisplay.hpp"

    class NcurseFile : public IMonitorDisplay {
        public:
            NcurseFile(void);
            ~NcurseFile(void);

            bool continueRefresh(void);
            void refresh_all(void);
            bool diplsayAll(void);
            void refreshAll(void);
            bool getInput(void);
    };

#endif /* !NCURSEFILE_HPP_ */
