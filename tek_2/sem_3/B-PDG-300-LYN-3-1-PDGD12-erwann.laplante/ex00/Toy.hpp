/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD12-erwann.laplante
** File description:
** Toy
*/

#ifndef TOY_HPP_
    #define TOY_HPP_

    #include "Picture.hpp"

    class Toy {
        public:
            enum ToyType {
                BASIC_TOY,
                ALIEN
            };

            Toy();
            Toy(ToyType type, std::string name, std::string filename);
            ~Toy();

            ToyType getType() const;
            std::string getName() const;
            std::string getAscii() const;

            void setName(std::string name);
            bool setAscii(std::string file_name);


        protected:
            ToyType _type;
            std::string _name;
            Picture _picture;
    };

#endif /* !TOY_HPP_ */
