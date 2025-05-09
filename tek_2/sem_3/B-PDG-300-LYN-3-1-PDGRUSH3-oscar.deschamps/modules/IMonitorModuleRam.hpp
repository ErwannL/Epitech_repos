/*
** EPITECH PROJECT, 2023
** IMonitorModuleRam.hpp
** File description:
** no ideas
*/

#ifndef IMONITORMODULERAM_HPP_
    #define IMONITORMODULERAM_HPP_
    #include <math.h>
    #include <iostream>
    #include <sys/sysinfo.h>
    #include "../IMonitorModule.hpp"

    class IMonitorModuleRAM : public IMonitorModule {
        private:
            std::string _used;
            std::string _total;
            std::string _available;

        public:
            void getRam(void)
            {
	            struct sysinfo si;

	            if (sysinfo(&si) == 0) {
                    this->_total = "Total: " + std::to_string(si.totalram / pow(1024, 3)).substr(0, 5) + " GB";
                    this->_available = "Available: " + std::to_string(si.freeram / pow(1024, 3)).substr(0, 5) + " GB ("
                                                            + std::to_string(((si.freeram * 100) / si.totalram)).substr(0, 5) + " %%)";
                    this->_used = "Used: " + std::to_string((si.totalram - si.freeram) / pow(1024, 3)).substr(0, 5) + " GB";
	            }
            }

            ~IMonitorModuleRAM(void) {};

            IMonitorModuleRAM(int x, int y, int width, int limit)
                                        : IMonitorModule(x, y, width, limit)
            {
                getRam();
                this->_name = "RAM  ";
            }

            void refresh(void) { getRam(); }

            void display(void)
            {
                printTitle((" " + this->_name).c_str());
                printStr("");
                printStr(this->_total.c_str());
                printStr(this->_available.c_str());
                printStr(this->_used.c_str());
                printStr("");
                printBottom();
            }
            std::string getUsed()
            {
                return(_used);
            }
            std::string getTotal()
            {
                return(_total);
            }
            std::string getAvailable()
            {
                return(_available);
            }
    };

#endif /* !IMONITORMODULERAM_HPP_ */
