/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <iostream>
#include <vector>
#include <utility>

const int SCREEN_W  = 1920;
const int SCREEN_H = 1080;

class IGame {
    public:
        virtual ~IGame() = default;
        virtual void move(int, int) = 0;
        virtual void play(int, int) = 0;
        virtual std::vector<std::string> getMap() = 0;
        virtual std::vector<std::pair<int,int>> getPlayer() = 0;
        virtual int getScore() = 0;

    protected:
    private:
};

#endif /* !IGAME_HPP_ */
