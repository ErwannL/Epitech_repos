/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD11-erwann.laplante
** File description:
** SafeDirectoryLister
*/

#ifndef SAFEDIRECTORYLISTER_HPP_
    #define SAFEDIRECTORYLISTER_HPP_

    #include "DirectoryLister.hpp"

    class SafeDirectoryLister : virtual public DirectoryLister {
        public:
            SafeDirectoryLister();
            SafeDirectoryLister(const std::string& path, bool hidden);
            ~SafeDirectoryLister();

            bool open(const std::string& path, bool hidden);
            std::string get();

        protected:
            std::string _path;
            bool _hidden;
            dirent *_file;
            DIR *_dir;
            bool _is_open = false;
    };

#endif /* !SAFEDIRECTORYLISTER_HPP_ */
