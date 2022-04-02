/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "../../../Interface/include/IGame.hpp"

class Snake : public IGame {
    public:
        Snake();
        ~Snake() {};

        void play(int, int);
        void move(int, int);
        void grow(int);
        std::vector<std::string> getMap() {return _map;};
        std::vector<std::pair<int,int>> getPlayer() {return _player;};
        int getScore(){return _score;};

    protected:
    private:
        std::vector<std::string> _map;
        std::vector<std::pair<int,int>> _player;
        int _fruits = 5;
        int _score = 0;
        int longue_queue = 0;
        std::pair<int, int> tmp;
};

#endif /* !SNAKE_HPP_ */