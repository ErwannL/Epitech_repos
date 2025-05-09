/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-erwann.laplante
** File description:
** main
*/

#include "Core.hpp"
#include "Games.hpp"
#include "Graphicals.hpp"

int main (int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Bad arguments -> need only 1!" << std::endl;
        return 84;
    }

    void *handle = dlopen(av[1], RTLD_LAZY);
    char *error = dlerror();
    if (!handle || error != NULL) {
        std::cerr << av[1] << " => Unknown lib" << std::endl << error << std::endl;
        return 84;
    }

    std::shared_ptr<Arcade::Graphicals> (*lib)() = (std::shared_ptr<Arcade::Graphicals>(*)())dlsym(handle, "init");

    if (!lib || lib()->getTypeClass() != Arcade::Type::Graphical) {
        std::cerr << av[1] << " is not a graphical library" << std::endl;
        return 84;
    }

    lib()->createWindow();
    lib()->setTexte();

    while(lib()->isOpen()) {
        lib()->addName(lib()->getKey());
        lib()->updateTexte();
        lib()->updateWindow();
    }

    dlclose(handle);

    // Arcade::Core core;
    // std::filesystem::path exe_dir = std::filesystem::path(av[0]).parent_path();
    // std::filesystem::path path_to_dir = std::filesystem::current_path() / exe_dir / "lib";
    // for (const auto& entry : std::filesystem::directory_iterator(path_to_dir)) {
    //     if (entry.is_regular_file() && entry.path().filename().string()[0] != '.') {
    //         std::string temp = "lib/" + entry.path().filename().string();
    //         handle = dlopen(temp.c_str(), RTLD_LAZY);
    //         error = dlerror();
    //         if (handle && error == NULL) {
    //             std::shared_ptr<Arcade::Graphicals> (*tmp)() = (std::shared_ptr<Arcade::Graphicals>(*)())dlsym(handle, "init");
    //             std::string lib_name = entry.path().filename().string();
    //             lib_name.erase(0, 7);
    //             lib_name.erase(lib_name.size() - 3);
    //             if (tmp && tmp()->getTypeClass() != Arcade::Type::Graphical)
    //                 core.addGraphicalLib(lib_name);
    //             else if (tmp && tmp()->getTypeClass() != Arcade::Type::Game)
    //                 core.addGameLib(lib_name);
    //             dlclose(handle);
    //         }
    //     }
    // }
    // for (const auto& element : core.getGraphicalLib())
    //     std::cout << element << " ";
    // std::cout << std::endl;
    // for (const auto& element : core.getGameLib())
    //     std::cout << element << " ";
    // std::cout << std::endl;

    return 0;
}
