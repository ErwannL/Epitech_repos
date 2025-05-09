/*
** EPITECH PROJECT, 2023
** IMonitorModuleOS.hpp
** File description:
** no ideas
*/

#ifndef IMONITORMODULEOS_HPP_
    #define IMONITORMODULEOS_HPP_
    #include <sys/utsname.h>
    #include "../IMonitorModule.hpp"

    class IMonitorModuleOS : public IMonitorModule {
        private:
            std::string _kernel;
            std::string _oname;

        public:
            ~IMonitorModuleOS(void) {};

            IMonitorModuleOS(int x, int y, int width, int limit)
                                : IMonitorModule(x, y, width, limit)
            {
                struct utsname what;

                uname(&what);
                this->_kernel = what.release;
                this->_oname = what.sysname;
                this->_name = "OS ";
            }

            void refresh(void) {}

            void display(void)
            {
                printTitle((" "+ this->_name).c_str());
                printStr("");
                printStr(this->_kernel.c_str());
                printStr(this->_oname.c_str());
                printStr("");
                printBottom();
            }
            std::string getKernel()
            {
                return (_kernel);
            }
            std::string getOname()
            {
                return (_oname);
            }
    };


#endif /* !IMONITORMODULEOS_HPP_ */
