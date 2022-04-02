/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** SDL_Lib
*/

#ifndef SDL_LIB_HPP_
#define SDL_LIB_HPP_

#include <SDL2/SDL.h>
#include "SDL2/SDL_video.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <unistd.h>
#include <iostream>

#include "../../../Interface/include/ILibrary.hpp"

class SDL_Lib : public ILibrary
{
public:
    SDL_Lib() { std::cout << "SDL Initialized\n"; };
    ~SDL_Lib(){};

    void create_window();
    void draw_game(std::vector<std::string> map, std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>);
    void draw_player(std::string, int, int, int);
    void draw_menu();
    void disp_text(int, int, std::string, std::string color);
    ILibrary::Input_t getInput(); //done
    std::string enter_name();
    void destroy_window();
    std::string getName() { return "SDL"; };

    void clear();
    void update();

    std::string getUsername() { return _username; };
    void setName(std::string);

    void draw_line(std::string line, int h, int);
    void game_selector(std::vector<std::string>, unsigned int);

    void clock_s();
    void draw_score(pair_t, std::string);
    void draw_currentScore(int);

protected:
private:
    SDL_Renderer *_renderer;
    SDL_Window *_window;
    SDL_Surface *_win;
    TTF_Font *_f;
    TTF_Font *_f2;

    SDL_Texture *_back;
    SDL_Texture *_menu;
    std::string _username;
};

#endif /* !SDL_LIB_HPP_ */
