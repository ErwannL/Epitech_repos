/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-erwann.laplante
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
    #define SNAKE_HPP_

    #include "IGame.hpp"
    #include "IArcade.hpp"
    #include "Misc.hpp"
    enum Move {
        LEFT,
        RIGHT,
        UP,
        DOWN,
    };

    class Snake_part {
        public:
            Snake_part(Move dir, std::tuple <int,int> pos);
            Snake_part(const Snake_part &cpy);
            ~Snake_part();
            Move getDirection();
            std::tuple<int,int> getPos();
            void setDirection(Move temp);
            void setPos(std::tuple<int,int> temp);
        protected:
            Move _direction;
            std::tuple<int, int> _pos;
    };

    class Player {
        public:
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
            std::map<int, Snake_part> _snake;
        protected:
            int _speed;
            int _length;
            Move _direction;
            std::tuple<int, int> _position;
    };

    class Snake : virtual public IGame {
        public:
            int _score;
            Snake();
            Snake(const Snake &cpy);
            ~Snake() {};
            Arcade::Type getTypeClass (void);
            Arcade::Type what = Arcade::Type::Game;
            void reset(void);
            void update(void);
            void setSize(std::tuple<int, int> s);
            void setFruitPos(std::tuple<int, int> pos);
            std::tuple<int, int> getNewTuple(std::tuple<int, int> tuple, Move dir);
            std::tuple<int, int> getSize() const;
            std::tuple<int, int> getFruit() const;
            Player getPlayer();
            void setRandomFruit();
            void snake_move();
            void updateSnake(void);
            bool fruit_and_snake(void);
            void setMap(Sprite &sprite, std::string name);
            bool snake_in_wall();
            std::pair<int, Snake_part> insert_part();
            void setInput(std::pair<std::string, bool> temp);
            std::map<std::string, Sprite> &getMapSprite(void);
        protected:
            std::pair<std::string, bool> _input;
            std::tuple<int, int> _size;
            std::tuple<int, int> _fruitPos;
            Player _player;
            std::map<std::string, Sprite> _spriteMap;
    };

    extern "C" std::shared_ptr<Snake> init(void);

#endif /* !SNAKE_HPP_ */
