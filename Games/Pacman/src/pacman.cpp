/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** pacman
*/

#include <iostream>
#include <algorithm>
#include "../include/Pacman.hpp"

Pacman::Pacman()
{
    std::cout << "Pacman Initialized!" << std::endl;
    _player.push_back(std::make_pair(1, 1));
    _enemies.push_back(std::make_pair(5, 10));
    _enemies.push_back(std::make_pair(10, 5));
    _enemies.push_back(std::make_pair(10, 15));
    _enemies.push_back(std::make_pair(21, 10));
    _score = 0;
    _map = {"XXXXXXXXXXXXXXXXXXXXX",
            "X.........X.........X",
            "X.XXX.XXX.X.XXX.XXX.X",
            "X.XXX.XXX.X.XXX.XXX.X",
            "X.XXX.XXX.X.XXX.XXX.X",
            "XF........E........FX",
            "X.XXX.X.XXXXX.X.XXX.X",
            "X.XXX.X.XXXXX.X.XXX.X",
            "X.....X...X...X.....X",
            "XXXXX.XXX.X.XXX.XXXXX",
            "XXXXX.X.......X.XXXXX",
            "XXXXX.X.XX.XX.X.XXXXX",
            "XXXXX.X.X...X.X.XXXXX",
            ".....E..X...X..E.....", 
            "XXXXX.X.X...X.X.XXXXX",
            "XXXXX.X.XXXXX.X.XXXXX",
            "XXXXX.X.......X.XXXXX",
            "XXXXX.XXX.X.XXX.XXXXX",
            "X.....X...X...X.....X",
            "X.XXX.X.XXXXX.X.XXX.X",
            "X.XXX.X.XXXXX.X.XXX.X",
            "XF........E........FX",
            "X.XXX.XXX.X.XXX.XXX.X",
            "X.XXX.XXX.X.XXX.XXX.X",
            "X.XXX.XXX.X.XXX.XXX.X",
            "X.........X.........X",
            "XXXXXXXXXXXXXXXXXXXXX"};
}

void Pacman::move(int x, int y)
{
    if (_player[0].first + x == 13 && _player[0].second + y == 0) {
        _player[0] = std::make_pair(13, 20);
    } else if (_player[0].first + x == 13 && _player[0].second + y == 20) {
        _player[0] = std::make_pair(13, 0);
    } else if (_map[_player[0].first + x][_player[0].second + y] != 'X') {
        _player[0] = std::make_pair(_player[0].first + x, _player[0].second + y);
    } else 
        _player[0] = std::make_pair(_player[0].first + 0, _player[0].second + 0);
    //_score += 5;
}

void Pacman::grow()
{
    _score += 100;
    _player.push_back(std::make_pair(_player.at(_player.size() - 1).first, _player.at(_player.size() - 1).second));
}

void Pacman::move_enemies()
{
    if (_cycle < 5) {
        _map[_enemies[0].first + 0][_enemies[0].second + 1] = 'E';
        _map[_enemies[0].first][_enemies[0].second] = '.';
        _enemies[0] = std::make_pair(_enemies[0].first + 0, _enemies[0].second + 1);
        _map[_enemies[1].first + 1][_enemies[1].second + 0] = 'E';
        _map[_enemies[1].first][_enemies[1].second] = '.';
        _enemies[1] = std::make_pair(_enemies[1].first + 1, _enemies[1].second + 0);
        _map[_enemies[2].first + 1][_enemies[2].second + 0] = 'E';
        _map[_enemies[2].first][_enemies[2].second] = '.';
        _enemies[2] = std::make_pair(_enemies[2].first + 1, _enemies[2].second + 0);
        _map[_enemies[3].first + 0][_enemies[3].second + 1] = 'E';
        _map[_enemies[3].first][_enemies[3].second] = '.';
        _enemies[3] = std::make_pair(_enemies[3].first + 0, _enemies[3].second + 1);
    } else {
        _map[_enemies[0].first + 0][_enemies[0].second - 1] = 'E';
        _map[_enemies[0].first][_enemies[0].second] = '.';
        _enemies[0] = std::make_pair(_enemies[0].first + 0, _enemies[0].second - 1);
        _map[_enemies[1].first - 1][_enemies[1].second + 0] = 'E';
        _map[_enemies[1].first][_enemies[1].second] = '.';
        _enemies[1] = std::make_pair(_enemies[1].first - 1, _enemies[1].second + 0);
        _map[_enemies[2].first - 1][_enemies[2].second + 0] = 'E';
        _map[_enemies[2].first][_enemies[2].second] = '.';
        _enemies[2] = std::make_pair(_enemies[2].first - 1, _enemies[2].second + 0);
        _map[_enemies[3].first + 0][_enemies[3].second - 1] = 'E';
        _map[_enemies[3].first][_enemies[3].second] = '.';
        _enemies[3] = std::make_pair(_enemies[3].first + 0, _enemies[3].second - 1);
    }
}

void Pacman::play(int input, int last)
{
    if (input != last) {
        if (last == 1)
            move(-1, 0);
        else if (last == 2)
            move(1, 0);
        else if (last == 3)
            move(0, -1);
        else if (last == 4)
            move(0, 1);
    }
    else {
        if (input == 1)
            move(-1, 0);
        else if (input == 2)
            move(1, 0);
        else if (input == 3)
            move(0, -1);
        else if (input == 4)
            move(0, 1);
    }

    move_enemies();

    if (_cycle == 9)
        _cycle = 0;
    else 
        _cycle++;

    for (unsigned int j = 0; j != _map.size(); j++) {
        for (unsigned int k = 0; k != _map[j].length(); k++) {
            if (j == (unsigned int)_player[0].first && k == (unsigned int)_player[0].second) {
                if (_map[j][k] == 'F' && (unsigned int)_player[0].first == j && (unsigned int)_player[0].second == k) {
                    _map[j][k] = '.';
                    _fruits--;
                    _score += 50;
                    _strong = 1;
                }
                if (_map[j][k] == 'E' && (unsigned int)_player[0].first == j && (unsigned int)_player[0].second == k && _strong == 1) {
                    for (unsigned int i = 0; i != _enemies.size(); i++) {
                        if ((unsigned int)_enemies[i].first == j && (unsigned int)_enemies[1].second == k)
                            _enemies.erase(_enemies.begin() + i);
                        _map[j][k] = '.';
                        _strong = 0;
                        _score += 100;
                    }
                }
                if (_map[j][k] == 'E' && (unsigned int)_player[0].first == j && (unsigned int)_player[0].second == k && _strong == 0) {
                    _player.clear();
                }
            }
        }
    }
    if (_fruits == 0)
        _map.clear();
}

extern "C" {
    Pacman *init_gamelib() {
        return (new Pacman());
    }
}