/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** main_loop
*/

#include "Snake.hpp"

std::pair<int, Snake_part> Snake::insert_part(void)
{
    int ind = _player._snake.end()->first + 1;
    Move dir = _player._snake.end()->second.getDirection();
    int x = std::get<0>(_player._snake.end()->second.getPos());
    int y = std::get<1>(_player._snake.end()->second.getPos());
    Snake_part snake = Snake_part(dir, {x, y + 1});
    return (std::pair<int, Snake_part>(ind, snake));
}

void Snake::updateSnake(void)
{
    std::tuple<int,int> temp;
    Move last_dir;

    _player._snake.begin()->second.setDirection(_player.getDirection());
    _player._snake.begin()->second.setPos(_player.getPosition());
    for (int i = 2; i <= _player._snake.size();i++) {
        temp = _player._snake.find(i - 1)->second.getPos();
        last_dir = _player._snake.find(i - 1)->second.getDirection();
        _player._snake.find(i)->second.setPos(temp);
        _player._snake.find(i)->second.setDirection(last_dir);
    }
}

void Snake::update(void)
{
    Texture head = Texture("media/sprite.png", "o", {42, 42}, {0,0});
    Texture body = Texture("media/sprite.png", "o", {22, 40}, {94, 85});
    Texture tail = Texture("media/sprite.png", "o", {22, 40}, {52, 85});
    Texture fruit = Texture("media/sprite.png", "&", {40, 40}, {3, 83});
    Sprite h = Sprite("head_snake", /*xPos*/0, /*yPos*/0, head);
    Sprite b = Sprite("body_snake", /*xPos*/0, /*yPos*/0, body);
    Sprite t = Sprite("tail_snake", /*xPos*/0, /*yPos*/0, tail);
    Sprite f = Sprite("head_snake", /*xPos*/0, /*yPos*/0, fruit);
    setMap(h, "head");
    setMap(b, "body");
    setMap(t, "tail");
    setMap(f, "fruit");
    if (_player.getLength() == 0)
        return;
    int random = rand() % 4;
    switch (_input.first.c_str()[0]) {
        case 'q':
        case 'Q':
            _player.setDirection((LEFT));
        case 'd':
        case 'D':
            _player.setDirection((RIGHT));
        case 'z':
        case 'Z':
            _player.setDirection((UP));
        case 's':
        case 'S':
            _player.setDirection((DOWN));
    }
    snake_move();
    if (fruit_and_snake()) {
        _score += 1;
        _player.setLength(_player.getLength() + 1);
        setRandomFruit();
        insert_part();
        _player._snake.insert(insert_part());
    }
    updateSnake();
    if (snake_in_wall()) {
        _player.setLength(0);
        _player._snake.clear();
    }
}