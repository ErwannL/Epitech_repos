/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** IMonitorModuleTime
*/

#ifndef IMonitorModuleTime_HPP_
    #define IMonitorModuleTime_HPP_
    #include <ctime>
    #include <iostream>
    #include "../IMonitorModule.hpp"

    class IMonitorModuleTime : public IMonitorModule {
        public:
            IMonitorModuleTime(int x, int y, int width, int limit)
                                    : IMonitorModule(x, y, width, limit)
            {
                this->_time = std::time(nullptr);
                this->_name = "TIME ";
            };

            ~IMonitorModuleTime(void) {};

            char *getTime(void) const
            {
                time_t _time = std::time(nullptr);
                return asctime(std::localtime(&_time));
            };
            
            void refresh(void) { getTime(); }

            void display(void)
            {
                printTitle((" " + this->_name).c_str());
                printStr("");
                printStr(this->getTime());
                printStr("");
                printBottom();
            }

        private:
            std::time_t _time;
    };
#endif /* !IMonitorModuleTime_HPP_ */
