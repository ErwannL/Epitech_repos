/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** no idea
*/

#include "../include/Parsing.hpp"
#include "../include/Client.hpp"
#include "../include/Core.hpp"
#include <memory>

int main(int argc, char **argv) {
    std::unique_ptr<Core> core = nullptr;
    std::shared_ptr<Client> client = nullptr;
    std::shared_ptr<Parsing> args = std::make_shared<Parsing>();

    try {
        args->parse(argc, argv);
    } catch (const std::exception &ex) {
        std::cerr << "[ERROR]: " << ex.what() << "\n";
        return 84;
    }

    client = make_client(args->getMachine(), args->getPort());

    if (client.get()->getRet() == -1) return 84;

    core = std::make_unique<Core>(client);

    core->run();

    return 0;
}
