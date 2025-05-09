/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD11-erwann.laplante
** File description:
** IDirectoryLister
*/

#ifndef IDIRECTORYLISTER_HPP_
    #define IDIRECTORYLISTER_HPP_

    #include <iostream>
    #include <dirent.h>
    #include <string.h>

    class IDirectoryLister{
        public:
            virtual ~IDirectoryLister() = default;

            virtual bool open(const std::string& path, bool hidden) = 0;
            virtual std::string get() = 0;

            class OpenFailureException {
                public:
                    OpenFailureException();
                    ~OpenFailureException();
                    const char *what() const noexcept;
            };

            class NoMoreFileException {
                public:
                    NoMoreFileException();
                    ~NoMoreFileException();
                    const char *what() const noexcept;
            };
    };

#endif /* !IDIRECTORYLISTER_HPP_ */
