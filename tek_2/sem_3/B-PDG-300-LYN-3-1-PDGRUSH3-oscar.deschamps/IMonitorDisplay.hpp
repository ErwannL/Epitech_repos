/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
    #define IMONITORDISPLAY_HPP_
    #include "IMonitorModule.hpp"
    #include "modules/IMonitorModuleOS.hpp"
    #include "modules/IMonitorModuleCpu.hpp"
    #include "modules/IMonitorModuleRam.hpp"
    #include "modules/IMonitorModuleUser.hpp"
    #include "modules/IMonitorModuleTime.hpp"
    #include "modules/IMonitorModuleNetwork.hpp"

    class IMonitorDisplay {
        protected:
            IMonitorModuleTime *_time;
            IMonitorModuleOS *_os;
            IMonitorModuleRAM *_ram;
            IMonitorModuleUser *_user;
            IMonitorModuleCPU *_cpu;
            IMonitorModuleNetwork *_network;

        public:
            IMonitorDisplay(void) {};
            std::string getTime() {return(_os->_name);};
            ~IMonitorDisplay(void) {};
    };

#endif /* !IMONITORDISPLAY_HPP_ */
