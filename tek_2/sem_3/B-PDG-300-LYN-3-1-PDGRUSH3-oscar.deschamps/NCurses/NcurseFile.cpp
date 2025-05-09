/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGRUSH3-oscar.deschamps
** File description:
** NcurseFile
*/

#include "NcurseFile.hpp"

NcurseFile::~NcurseFile(void)
{
    endwin();
}

NcurseFile::NcurseFile(void)
{
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, true);

    this->_user = new IMonitorModuleUser(0, 0, 50, 5);
    this->_cpu = new IMonitorModuleCPU(51, 0, 70, 8);
    this->_os = new IMonitorModuleOS(0, 6, 50, 5);
    this->_ram = new IMonitorModuleRAM(122, 0, 50, 6);
    this->_time = new IMonitorModuleTime(122, 7, 50, 4);
    this->_network = new IMonitorModuleNetwork(51, 9, 70, 4);
}

bool NcurseFile::diplsayAll(void)
{
    clear();

    if (COLS < 155 || LINES < 14) {
        printw("[ERROR]: window too small.");
        return continueRefresh();
    }

    this->_user->display();
    this->_time->display();
    this->_cpu->display();
    this->_ram->display();
    this->_os->display();
    this->_network->display();
    return continueRefresh();
}

void NcurseFile::refreshAll(void)
{
    this->diplsayAll();
    this->_os->refresh();
    this->_cpu->refresh();
    this->_ram->refresh();
    this->_time->refresh();
    this->_user->refresh();
    this->_network->refresh();
}

bool NcurseFile::getInput(void)
{
    int entry = getch();
    switch (entry) {
        case 'q':
        case 'Q':
            return false;
        default:
            return true;
    }
    return true;
}

bool NcurseFile::continueRefresh(void)
{
    if (getInput() == false) return false;

    usleep(99999);
    refreshAll();
    refresh();
    return true;
}
