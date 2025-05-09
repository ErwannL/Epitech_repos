/*
** EPITECH PROJECT, 2023
** IMonitorModuleNetwork.hpp
** File description:
** IMonitorModuleTime
*/

#ifndef IMONITORNETWORK_HPP_
    #define IMONITORNETWORK_HPP_
    #include <ctime>
    #include <cstdio>
    #include <iostream>
    #include "../IMonitorModule.hpp"

    class IMonitorModuleNetwork : public IMonitorModule {
        private:
            std::string _ip;

        public:
            IMonitorModuleNetwork(int x, int y, int width, int limit)
                                    : IMonitorModule(x, y, width, limit)
            {
                this->_ip = "ipv4: " + execCmd("ip route").substr(12, 13);
                this->_name = "NETWORK";
            };

            ~IMonitorModuleNetwork(void) {};

            std::string execCmd(std::string cmd)
            {
                char buf[2];
                std::string ret = "";
                FILE *fd = popen(cmd.c_str(), "r");

                if (!fd) return "[ERROR]: no connection.";

                while (!feof(fd)) {
                    if (fgets(buf, 2, fd)) ret += buf;
                }
                return ret;
            }

            void refresh(void) {}
            std::string getIP() {return (_ip);};
            void display(void)
            {
                printTitle((" " + this->_name).c_str());
                printStr("");
                printStr(this->_ip.c_str());
                printStr("");
                printBottom();
            }
    };
#endif /* !IMonitorModuleNewtork_HPP_ */
