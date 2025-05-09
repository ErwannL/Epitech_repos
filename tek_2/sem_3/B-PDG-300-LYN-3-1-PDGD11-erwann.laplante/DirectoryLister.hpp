/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD11-erwann.laplante
** File description:
** DirectoryLister
*/

#ifndef DIRECTORYLISTER_HPP_
    #define DIRECTORYLISTER_HPP_

    #include "IDirectoryLister.hpp"

    class DirectoryLister : virtual public IDirectoryLister {
        public:
            DirectoryLister();
            DirectoryLister(const std::string& path, bool hidden);
            ~DirectoryLister();

            bool open(const std::string& path, bool hidden);
            std::string get();

        protected:
            bool _hidden;
            dirent *_file;
            DIR *_dir;
            bool _is_open = false;
    };

#endif /* !DIRECTORYLISTER_HPP_ */
