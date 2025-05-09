/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** IComponent
*/

#ifndef NANOTEKSPICE_HPP_
    #define NANOTEKSPICE_HPP_

    #include <iostream>
    #include <fstream>
    #include <string>
    #include <map>
    #include <tuple>
    #include <sstream>
    #include <vector>
    #include <string.h>
    #include <signal.h>
    #include <cstring>
    #include <cstdio>
    #include <list>
    #include <memory>
    #include <algorithm>

    namespace nts {
        enum Tristate {
            Undefined = (-true),
            True = true,
            False = false
        };

        class IComponent {
            public :
                virtual ~IComponent() = default ;

                virtual nts::Tristate compute(std::size_t pin) = 0;
                virtual void verifState(std::size_t pin) = 0;

                virtual void simulate(std::size_t tick) = 0;
                virtual void simulation(size_t first, nts::Tristate new_state, size_t pin) = 0;

                virtual void setType(std::string new_type) = 0;
                virtual void setName(std::string new_name) = 0;
                virtual void setState(nts::Tristate new_state, std::size_t pin = 1) = 0;
                virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
                virtual void setLinkBi(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
                virtual std::list<int> set_data(std::list<int> origin, int pos, int value) = 0;
                virtual void setChecker(std::list<int> _checker) = 0;

                virtual std::string getType(void) = 0;
                virtual int retrieve_data(std::list<int> _checker, int x) = 0;
                virtual std::list<int> getChecker(void) = 0;
                virtual std::string getName(void) = 0;
                virtual nts::Tristate getState(std::size_t pin = 1) = 0;
                virtual std::string getReadableState(void) = 0;
                virtual std::map<std::size_t, std::tuple<nts::IComponent *, std::size_t>> getLinks(void) = 0;

                virtual std::unique_ptr<nts::IComponent> createComponent(const std::string &type) = 0;
                virtual std::unique_ptr<nts::IComponent> createInput() const = 0;
                virtual std::unique_ptr<nts::IComponent> createOutput() const = 0;
                virtual std::unique_ptr<nts::IComponent> createTrue() const = 0;
                virtual std::unique_ptr<nts::IComponent> createFalse() const = 0;
                virtual std::unique_ptr<nts::IComponent> createClock() const = 0;
                virtual std::unique_ptr<nts::IComponent> createAnd() const = 0;
                virtual std::unique_ptr<nts::IComponent> createOr() const = 0;
                virtual std::unique_ptr<nts::IComponent> createXor() const = 0;
                virtual std::unique_ptr<nts::IComponent> createNot() const = 0;
                virtual std::unique_ptr<nts::IComponent> create4011() const = 0;
                virtual std::unique_ptr<nts::IComponent> create4081() const = 0;
                virtual std::unique_ptr<nts::IComponent> create4001() const = 0;
                virtual std::unique_ptr<nts::IComponent> create4071() const = 0;
                virtual std::unique_ptr<nts::IComponent> create4030() const = 0;
                virtual std::unique_ptr<nts::IComponent> create4069() const = 0;

                class Error : public std::exception {
                    public:
                        enum ErrorType {
                            ARGUMENTS,
                            OPEN,
                            TYPE,
                            VALUE,
                            DEC_NAME,
                            NAME,
                            PIN,
                            DELI,
                            ALREADY,
                            LINE,
                            COMMAND,
                            C_TYPE,
                            MODIF,
                            NTS,
                            NUM_PIN,
                            NO_COMP
                        };

                        Error(ErrorType erreur);
                        ~Error();
                        const char *what() const noexcept;

                        ErrorType type;
                        std::string str;
                };

            protected:
                std::string type;
                std::string name;
                std::list<nts::Tristate> state;
                std::map<std::size_t, std::tuple<nts::IComponent *, std::size_t>> Links;
                std::list<int> checker;

            private:
        };

    }

    int test_function_clear_str(char c);
    std::string clear_str(std::string str);

    std::string get_name(std::string str);
    std::string get_pin(std::string str);

    std::map<std::string, std::unique_ptr<nts::IComponent>> read_file(std::string filename, std::map<std::string, std::unique_ptr<nts::IComponent>> Elements);

    int tekspice_function(int ac, char **av);

#endif /* !NANOTEKSPICE_HPP_ */
