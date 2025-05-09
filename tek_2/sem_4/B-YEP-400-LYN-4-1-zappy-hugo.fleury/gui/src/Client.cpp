/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** gui
*/

#include "../include/Client.hpp"

/* =================== constructors =================== */

Client::Client(std::string machine, int port)
: _port(port), _machine(machine)
{
    this->_client = std::make_shared<client_t>();

    if (this->start_connection() == 1) {
        std::cout << "[ERROR]: server not reachable" << std::endl;
        this->_ret = -1;
        return;
    }

    std::cout << "[INFO]: successfuly connected!" << std::endl;

    this->sendCmd("GRAPHIC");

    this->recvCmd();

    this->_ret = 1;
}

Client::~Client(void)
{
    close(this->_client->socket_fd);

    shutdown(this->_client->socket_fd, SHUT_RDWR);

    std::cout << "[INFO]: connection closed" << std::endl;
}

/* =================== cmd handle =================== */

bool Client::sendCmd(const std::string &data)
{
    std::string sent = data + "\n";

    if (write(this->_client->socket_fd, sent.c_str(), sent.length()) == -1) {
        std::cerr << "[INFO]: Error sending data to server" << std::endl;
        return false;
    }

    return true;
}

std::vector<std::string> Client::recvCmd(void)
{
    std::vector<std::string> rcv;

    while (1) {
        FD_ZERO(&this->_client->fd);
        FD_SET(STDIN_FILENO, &this->_client->fd);
        FD_SET(this->_client->socket_fd, &this->_client->fd);

        struct timeval timeout;

        timeout.tv_sec = 0;
        timeout.tv_usec = 10000;

        int ready = select(this->_client->socket_fd + 1, &this->_client->fd, NULL, NULL, &timeout);

        if (ready == -1 || ready == 0) {
            break;
        } else {
            if (FD_ISSET(this->_client->socket_fd, &this->_client->fd)) {
                char buf[0x1000];

                ssize_t sz = read(3, buf, sizeof(buf));

                buf[sz] = '\0';

                std::string str(buf, sz);

                rcv.push_back(str);
            }
        }
    }
    return rcv;
}

int Client::start_connection(void)
{
    this->_client->serv_addr.sin_family = AF_INET;
    this->_client->serv_addr.sin_addr.s_addr = inet_addr(this->getMachine().c_str());
    this->_client->serv_addr.sin_port = htons(this->getPort());
    this->_client->socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (this->_client->socket_fd == -1 || connect(this->_client->socket_fd, (struct sockaddr *)&this->_client->serv_addr, sizeof(this->_client->serv_addr))) return 1;

    this->_client->user = NULL;
    this->_client->uuid = NULL;

    return 0;
}

void Client::split(std::vector<std::string> *ret, std::string str, std::string delim)
{
    (*ret).clear();

    for (size_t pos = 0; (pos = str.find(delim)) != std::string::npos;) {
        (*ret).push_back(str.substr(0, pos));
        str.erase(0, pos + strlen(delim.data()));
    }

    (*ret).push_back(str);
}
