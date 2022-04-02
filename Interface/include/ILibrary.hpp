/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** ILibrary
*/

#ifndef ILIBRARY_HPP_
#define ILIBRARY_HPP_

#include <iostream>
#include <vector>

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

typedef std::vector<std::pair<std::string, int>> pair_t;

class ILibrary
{
public:
    typedef enum Input_s
    {
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        ESCAPE,
        NEXT,
        PREV,
        PAUSE,
        ENTER,
        PLAY
    } Input_t;

    virtual ~ILibrary() = default;
    virtual void create_window() = 0;
    virtual void draw_game(std::vector<std::string> map, std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>) = 0;
    virtual void draw_player(std::string, int, int, int) = 0;
    virtual void draw_menu() = 0;
    virtual ILibrary::Input_t getInput() = 0;
    virtual std::string enter_name() = 0;
    virtual void destroy_window() = 0;
    virtual void disp_text(int, int, std::string, std::string color) = 0;
    virtual void clear() = 0;
    virtual void update() = 0;
    virtual std::string getName() = 0;

    virtual std::string getUsername() = 0;
    virtual void setName(std::string) = 0;

    virtual void draw_line(std::string line, int h, int dir) = 0;
    virtual void game_selector(std::vector<std::string>, unsigned int) = 0;

    virtual void clock_s() = 0;
    virtual void draw_score(pair_t, std::string) = 0;
    virtual void draw_currentScore(int) = 0;

protected:
private:
};

#endif /* !ILIBRARY_HPP_ */
