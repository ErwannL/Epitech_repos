/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** gui
*/

#ifndef CLIENT_HPP
    #define CLIENT_HPP
    #include <any>
    #include <map>
    #include <iostream>
    #include <memory>
    #include <vector>
    #include <string>
    #include <netdb.h>
    #include <stdio.h>
    #include <fstream>
    #include <fcntl.h>
    #include <cstddef>
    #include <iostream>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/uio.h>
    #include <sys/wait.h>
    #include <sys/time.h>
    #include <arpa/inet.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <stdint.h>

    class Client {
        private:
            typedef struct client_s {
                struct sockaddr_in serv_addr;
                struct timeval timeout;
                int socket_fd;
                int login;
                char *user;
                char *uuid;
                fd_set fd;
            } client_t;

            int _ret;
            int _port;
            std::string _machine;
            std::shared_ptr<client_t> _client;

        public:
            ~Client(void);
            Client(std::string, int);

            int start_connection(void);

            bool sendCmd(const std::string &);
            
            std::vector<std::string> recvCmd(void);
            void split(std::vector<std::string> *, std::string, std::string);

            int getRet(void) const { return this->_ret; };
            int getPort(void) const { return this->_port; };
            std::string getMachine(void) const { return this->_machine; };
            int getClient(void) const { return this->_client->socket_fd; };
    };

    inline
    std::shared_ptr<Client> make_client(std::string machine, int port)
    {
        return std::make_shared<Client>(machine, port);
    }
#endif