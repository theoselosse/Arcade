/*
** EPITECH PR.JECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** snake
*/

#include <algorithm>
#include "../include/Snake.hpp"

Snake::Snake()
{
    _player.push_back(std::make_pair(10, 3));
    _player.push_back(std::make_pair(10, 2));
    _player.push_back(std::make_pair(10, 1));

    std::cout << "Nibbler Initialized!" << std::endl;
    _map = {"XXXXXXXXXXXXXXXXXXXXXXXXXXX","X.........................X","X.........................X","X............F............X","X.........................X","X.........................X","X.........................X","X......F..................X","X.........................X","X.........................X","X.........................X",
    "X.........................X","X............F............X","X.........................X","X.........................X","X......F..................X", "X.........................X","X.........................X","X............F............X",
    "X.........................X","X.........................X","X.........................X","X.........................X","X.........................X","XXXXXXXXXXXXXXXXXXXXXXXXXXX"};
}

void Snake::move(int x, int y)
{
    std::pair<int,int> tmp;
    std::pair<int, int> tmp2;

    for (unsigned int i = 0; i != _player.size(); i++) {
        if (i == 0) {
            tmp = _player[i];
            _player[i] = std::make_pair(_player[i].first + x, _player[i].second + y);
        }
        else {
            tmp2 = _player[i];
            _player[i] = tmp;
            tmp = tmp2;
        }
    }
    if (longue_queue != 0) {
        longue_queue --;
        _player.push_back(tmp);
    }
    _score += 5;
}

void Snake::grow(int input)
{
    _score += 100;
    tmp = _player.back();
    longue_queue++;
}

void Snake::play(int input, int last)
{
    if (input != last) {
        if (last == 1) // up
            move(-1, 0);
        else if (last == 2) // down
            move(1, 0);
        else if (last == 3) // left
            move(0, -1);
        else if (last == 4) // right
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
    for (unsigned int i = 0; i != _player.size(); i++) {
        for (unsigned int j = 0; j != _map.size(); j++) {
            for (unsigned int k = 0; k != _map[j].length(); k++) {
                if (j == (unsigned int)_player[i].first && k == (unsigned int)_player[i].second) {
                    if (_map[j][k] == 'X' || _map[j][k] == 'o') {
                        _player.clear();
                        return;
                    }
                    for (unsigned int l = 0; l != _player.size(); l++) {
                        if (_map[j][k] == 'F' && (unsigned int)_player[l].first == j && (unsigned int)_player[l].second == k) {
                            _map[j][k] = '.';
                            _fruits--;
                            grow(input);
                        }
                    }
                }
            }
        }
    }
    if (_fruits == 0)
        _map.clear();
}

extern "C" {
    Snake *init_gamelib() {
        return (new Snake());
    }
}