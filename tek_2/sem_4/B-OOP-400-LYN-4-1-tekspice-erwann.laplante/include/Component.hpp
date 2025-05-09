/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
    #define COMPONENT_HPP_

    #include "IComponent.hpp"

    class Component : virtual public nts::IComponent {
        public:
            Component();
            ~Component();

            nts::Tristate compute(std::size_t pin);
            void verifState(std::size_t pin);

            void simulate(std::size_t tick);
            void simulation(size_t first, nts::Tristate new_state, size_t pin) {return;};

            void setType(std::string new_type);
            void setName(std::string new_name);
            void setState(nts::Tristate new_state, std::size_t pin = 1);
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            void setLinkBi(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            std::list<int> set_data(std::list<int> origin, int pos, int value);
            void setChecker(std::list<int> _checker);

            virtual int retrieve_data(std::list<int> _checker, int x);
            std::string getType(void);
            std::string getName(void);
            std::list<int> getChecker(void);
            nts::Tristate getState(std::size_t pin = 1);
            std::map<std::size_t, std::tuple<nts::IComponent *, std::size_t>> getLinks(void);
            std::string getReadableState();

            std::unique_ptr<nts::IComponent> createComponent(const std::string &type);
            std::unique_ptr<nts::IComponent> createInput() const;
            std::unique_ptr<nts::IComponent> createOutput() const;
            std::unique_ptr<nts::IComponent> createTrue() const;
            std::unique_ptr<nts::IComponent> createFalse() const;
            std::unique_ptr<nts::IComponent> createClock() const;
            std::unique_ptr<nts::IComponent> createAnd() const;
            std::unique_ptr<nts::IComponent> createOr() const;
            std::unique_ptr<nts::IComponent> createXor() const;
            std::unique_ptr<nts::IComponent> createNot() const;
            std::unique_ptr<nts::IComponent> create4011() const;
            std::unique_ptr<nts::IComponent> create4081() const;
            std::unique_ptr<nts::IComponent> create4001() const;
            std::unique_ptr<nts::IComponent> create4071() const;
            std::unique_ptr<nts::IComponent> create4030() const;
            std::unique_ptr<nts::IComponent> create4069() const;

        protected:
        private:
    };

#endif /* !COMPONENT_HPP_ */
