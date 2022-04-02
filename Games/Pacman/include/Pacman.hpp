/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "../../../Interface/include/IGame.hpp"

class Pacman : public IGame {
    public:
        Pacman();
        ~Pacman() {};

        void play(int, int);
        void move(int, int);
        void grow();
        void move_enemies();
        int direct_move(int, int);
        std::vector<std::string> getMap() {return _map;};
        std::vector<std::pair<int,int>> getPlayer() {return _player;};
        int getScore(){return _score;};
    protected:
    private:
        std::vector<std::string> _map;
        std::vector<std::pair<int,int>> _player;
        std::vector<std::pair<int,int>> _enemies;
        int _fruits = 4;
        int _score = 0;
        int _strong = 0;
        int _cycle = 0;
};

#endif /* !PACMAN_HPP_ */
