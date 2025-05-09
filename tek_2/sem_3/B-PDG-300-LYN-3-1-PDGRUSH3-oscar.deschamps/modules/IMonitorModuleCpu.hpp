/*
** EPITECH PROJECT, 2023
** IMonitorModuleCpu.hpp
** File description:
** no ideas
*/

#ifndef IMONITORMODULECPU_HPP_
    #define IMONITORMODULECPU_HPP_
    #include <fstream>
    #include <iostream>
    #include <type_traits>
    #include "../IMonitorModule.hpp"

    class IMonitorModuleCPU : public IMonitorModule {
        private:
            std::string _values[5];

        public:
            ~IMonitorModuleCPU(void) {};

            IMonitorModuleCPU(int x, int y, int width, int limits)
                                    : IMonitorModule(x, y, width, limits)
            {
                this->_name = "CPU  ";
            }

            std::string rmTab(std::string buf)
            {
                for (int i = 0; i != -1;) {
                    i = buf.find("\t", i);

                    if (i != -1) {
                        buf = buf.replace(i, 1, " ");
                    }
                }
                return buf;
            }

            void getInfos(void)
            {
                std::string buf;
                std::ifstream fd("/proc/cpuinfo", std::ifstream::in);
                std::string what[5] = { "vendor_id", "model name", "cpu MHz", "cache size", "microcode" };

                if (!fd.is_open()) return;

                for (int i = 0; getline(fd, buf, '\n') && i != 5;) {
                    for (int j = 0; j < 5; j++) {
                        if (!buf.find(what[j])) {
                            this->_values[i] = rmTab(buf);
                            i++;
                        }
                    }
                }
            }

            void refresh(void) {}
            std::string *getValues()
            {
                return(_values);
            }
            void display(void)
            {
                getInfos();
                printTitle((" " + this->_name).c_str());
                printStr("");
                printStr(this->_values[0].c_str());
                printStr(this->_values[1].c_str());
                printStr(this->_values[2].c_str());
                printStr(this->_values[3].c_str());
                printStr(this->_values[4].c_str());
                printStr("");
                printBottom();
            }
        };
#endif /* !IMONITORMODULECPU_HPP_ */
