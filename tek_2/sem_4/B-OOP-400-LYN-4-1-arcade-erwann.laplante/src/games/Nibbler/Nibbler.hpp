/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
    #define NIBBLER_HPP_
    #include "IGame.hpp"

    class Player {
        public:
            enum Move {
                LEFT,
                RIGHT,
                UP,
                DOWN,
            };
            Player();
            Player(const Player &c);
            ~Player();
            void setPosition(std::tuple<int, int> pos);
            void setSpeed(int x);
            void setDirection(Move moving);
            void setLength(int len);
            std::tuple<int, int> getPosition() const;
            int getSpeed() const;
            int getLength() const;
            Move getDirection() const;
        protected:
            int _speed;
            int _length;
            Move _direction;
            std::tuple<int, int> _position;
    };

    class Nibbler {
    protected:
        std::tuple<int, int> _size;
        std::tuple<int, int> _fruitPos;
        Player _player;
        std::map<std::tuple<int,int>, char> _map;
    public:
        int _maxScore;
        int _score;
        Nibbler();
        Nibbler(const Nibbler &cpy);
        ~Nibbler();
        void reset(void);
        void update(void);
        void setSize(std::tuple<int, int> s);
        void setFruitPos(std::tuple<int, int> pos);
        std::tuple<int, int> getSize() const;
        std::tuple<int, int> getFruit() const;
        Player getPlayer();
        void setRandomFruit();
        void snake_move();
        bool fruit_and_snake(void);
        bool snake_in_wall();
    private:
};

#endif /* !NIBBLER_HPP_ */
