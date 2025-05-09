/*
** EPITECH PROJECT, 2023
** IMonitorModuleUser.hpp
** File description:
** no ideas
*/

#ifndef IMONITORMODULEUSER_HPP_
    #define IMONITORMODULEUSER_HPP_
    #include <unistd.h>
    #include <limits.h>
    #include <string.h>
    #include "../IMonitorModule.hpp"

    class IMonitorModuleUser : public IMonitorModule {
        private:
            char _host[HOST_NAME_MAX];
            char _user[LOGIN_NAME_MAX];

        public:
            ~IMonitorModuleUser(void) {};

            IMonitorModuleUser(int x, int y, int width, int limit)
                                        : IMonitorModule(x, y, width, limit)
            {
                gethostname(this->_host, HOST_NAME_MAX);
                getlogin_r(this->_user, LOGIN_NAME_MAX);
                this->_name = "USER ";
            }

            void refresh(void) {}

            void display(void)
            {
                printTitle((" " + this->_name).c_str());
                printStr("");
                printStr(this->_host);
                printStr(this->_user);
                printStr("");
                printBottom();
            }
            std::string getUser()
            {
                return(_user);
            }
            std::string getHost()
            {
                return(_host);
            }
    };

#endif /* !IMONITORMODULEUSER_HPP_ */
