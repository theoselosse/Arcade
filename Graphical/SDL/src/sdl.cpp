/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** main
*/

#include <algorithm>
#include "../../SDL/include/SDL_Lib.hpp"

void logSDLError(std::ostream &os, const std::string &msg)
{
    os << msg << " error: " << SDL_GetError() << std::endl;
}

void SDL_Lib::setName(std::string name)
{
    _username = name;
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y)
{
    SDL_Rect dst;

    dst.x = x;
    dst.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopy(ren, tex, NULL, &dst);
}

void SDL_Lib::draw_line(std::string line, int h, int dir)
{
    int x = SCREEN_WIDTH / 2 - 270;

    for (unsigned int i = 0; i < line.length(); i++, x += 32) {
        if (line[i] == 'X')
            draw_player("WHITE", x, h, dir);
        else if (line[i] == '.')
            draw_player("YELLOW", x, h, dir);
        else if (line[i] == 'o')
            draw_player("GREEN", x, h, dir);
        else if (line[i] == 'F')
            draw_player("RED", x, h, dir);
        else if (line[i] == 'H')
            draw_player("DGREEN", x, h, dir);
        else if (line[i] == 'E')
            draw_player("BLUE", x, h, dir);
    }
}

void SDL_Lib::draw_player(std::string color, int x, int y, int dir)
{
    (void)dir;
    SDL_Rect rec;
    SDL_Color c;

    if (color == "WHITE")
        c = {130, 48, 56, 0};
    else if (color == "YELLOW")
        c = {244, 247, 190, 0};
    else if (color == "RED")
        c = {255, 0, 0, 0};
    else if (color == "GREEN")
        c = {0, 250, 0, 0};
    else if (color == "DGREEN")
        c = {0, 160, 0, 0};
    else if (color == "BLUE")
        c = {0, 0, 255, 0};
    else
        c = {255,255,255, 0};

    rec.x = x;
    rec.y = y;
    rec.w = 32;
    rec.h = 32;
    SDL_SetRenderDrawColor(_renderer, c.r, c.g, c.b, c.a);
    SDL_RenderFillRect(_renderer, &rec);
}

void SDL_Lib::draw_game(std::vector<std::string> map, std::vector<std::pair<int, int>> p, std::vector<std::pair<int, int>> temp)
{
    int dir = 0;

    if (temp.front().first < p.front().first)
        dir = 2;
    else if (temp.front().second < p.front().second)
        dir = 1;
    else if (temp.front().second > p.front().second)
        dir = 3;
    else if (temp.front().first > p.front().first)
        dir = 4;
    else
        dir = 0;

    for (unsigned int i = 0; i != p.size(); i++) { // chaque partie du snake
        for (unsigned int j = 0; j != map.size(); j++) { // for each line
            for (unsigned int k = 0; k != map[j].length(); k++) { // for each char
                if (j == (unsigned int)p[i].first && k == (unsigned int)p[i].second) {
                    if (i == 0)
                        map[j][k] = 'H';
                    else
                        map[j][k] = 'o';
                }
            }
        }
    }
    clear();

    int h = 200;

    for (unsigned int i = 0; i < map.size(); i++, h += 32) {
        draw_line(map[i], h, dir);
    }
}

void SDL_Lib::draw_menu()
{
    SDL_Rect rec;
    rec.x = 0;
    rec.y = 0;
    SDL_Texture *tex = IMG_LoadTexture(_renderer, "./Graphical/res/Menu_BG.jpg");
    SDL_QueryTexture(tex, NULL, NULL, &rec.w, &rec.h);
    SDL_RenderCopy(_renderer, tex, NULL, &rec);
    SDL_DestroyTexture(tex);
}

void SDL_Lib::clear()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}

void SDL_Lib::update()
{
    SDL_RenderPresent(_renderer);
}

void SDL_Lib::create_window()
{
    TTF_Init();
    _f = TTF_OpenFont("Graphical/res/fonts/arcade/OriginTech personal use.ttf", 60);
    if (!_f)
        logSDLError(std::cout, "Font not found");
    _f2 = TTF_OpenFont("Graphical/res/fonts/arcade/OriginTech personal use.ttf", 40);
    if (!_f2)
        logSDLError(std::cout, "Font not found");
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        logSDLError(std::cout, "SDL_Init");
        return;
    }
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (_window == nullptr)
    {
        logSDLError(std::cout, "CreateWindow");
        SDL_Quit();
        return;
    }
    _win = SDL_GetWindowSurface(_window);
    _renderer = SDL_CreateRenderer(_window, -1,
                                   SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_renderer == nullptr)
    {
        logSDLError(std::cout, "CreateRenderer");
        SDL_Quit();
        return;
    }
    _back = IMG_LoadTexture(_renderer, "./Arcade_BG.jpg");
    _menu = IMG_LoadTexture(_renderer, "./Menu_BG.jpg");
}


ILibrary::Input_t SDL_Lib::getInput()
{
    SDL_Event e;
    if (SDL_PollEvent(&e) == 0)
        return NONE;
    if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
        return Input_t::ESCAPE;
    if (e.key.repeat == 0 && e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_UP:
                return Input_t::UP;
            case SDLK_RETURN:
                return Input_t::ENTER;
            case SDLK_DOWN:
                return Input_t::DOWN;
            case SDLK_LEFT:
                return Input_t::LEFT;
            case SDLK_RIGHT:
                return Input_t::RIGHT;
            case SDLK_o:
                return Input_t::PREV;
            case SDLK_p:
                return Input_t::NEXT;
            case SDLK_SPACE:
                return Input_t::PLAY;
            default:
                return Input_t::NONE;
        }
    }
    return Input_t::NONE;
}

void SDL_Lib::destroy_window()
{
    TTF_CloseFont(_f);
    _f = nullptr;
    TTF_CloseFont(_f2);
    _f2 = nullptr;
    SDL_DestroyRenderer(_renderer);
    _renderer = nullptr;
    SDL_DestroyWindow(_window);
    _window = nullptr;
    SDL_Quit();
}

void SDL_Lib::disp_text(int x, int y, std::string string, std::string color)
{
    SDL_Color c;
    SDL_Rect rec;

    if (string.empty())
        return;
    if (color == "RED")
        c = {255, 0, 0, 0};
    if (color == "Y")
        c = {255, 244, 102, 0};
    if (color == "CYAN")
        c = {6, 214, 160, 0};
    if (color == "GREEN")
        c = {0, 255, 0, 0};
    if (color == "GRAY")
        c = {86, 82, 84, 0};
    if (color == "CYAN" || color == "Y") {
        SDL_Surface *fsu = TTF_RenderText_Solid(_f2, string.c_str(), c);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, fsu);
        rec.x = x;
        rec.y = y;
        rec.w = fsu->w;
        rec.h = fsu->h;
        SDL_RenderCopy(_renderer, texture, NULL, &rec);
        SDL_FreeSurface(fsu);
        SDL_DestroyTexture(texture);
    } else {
        SDL_Surface *fsuf = TTF_RenderText_Solid(_f, string.c_str(), c);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, fsuf);
        rec.x = x;
        rec.y = y;
        rec.w = fsuf->w;
        rec.h = fsuf->h;
        SDL_RenderCopy(_renderer, texture, NULL, &rec);
        SDL_FreeSurface(fsuf);
        SDL_DestroyTexture(texture);
    }
}

std::string SDL_Lib::enter_name()
{
    SDL_Event e;
    std::string str;
    SDL_StartTextInput();
    bool run = false;

    while (!run)
    {
        clear();
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.key.keysym.sym == SDLK_RETURN)
                run = true;
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE && str.length() > 0)
                str = str.substr(0, str.length() - 1);
            else if (e.type == SDL_TEXTINPUT)
            {
                str += e.text.text;
            }
        }
        draw_menu();
        disp_text(SCREEN_WIDTH / 2 - 300, 50, "Enter an username", "RED");
        disp_text(SCREEN_WIDTH / 2 - 200, 150, str, "GREEN");
        update();
    }
    _username = str;
    SDL_StopTextInput();
    if (str.empty())
    {
        _username = "guest";
        return ("guest");
    }
    return str;
}

void SDL_Lib::game_selector(std::vector<std::string> _games, unsigned int _selected)
{
    int h = 300;
    std::string lib = "Current lib: " + getName();
    std::string name = "Welcome " + getUsername();

    disp_text(SCREEN_WIDTH / 2 - 200, 100, name, "RED");
    for (unsigned int i = 0; i != _games.size(); i++, h += 200)
    {
        if (_selected != i)
            disp_text(SCREEN_WIDTH / 2 - 100, h, _games[i], "RED");
        else
            disp_text(SCREEN_WIDTH / 2 - 100, h, _games[i], "GREEN");
    }
    disp_text(100, 300, lib, "RED");
}

void SDL_Lib::clock_s()
{
    SDL_Delay(60);
}

void SDL_Lib::draw_score(pair_t score, std::string name)
{
    int h = 500;

    std::string title = "Bests of " + name;
    disp_text(100, 400, title, "RED");
    for (auto i = score.begin(); i != score.end(); i++, h += 80) {
        disp_text(150, h, i->first.substr(0, 5) + "  :  ", "Y");
        disp_text(400, h, std::to_string(i->second), "CYAN");
    }
}

void SDL_Lib::draw_currentScore(int score)
{
    disp_text(SCREEN_WIDTH / 4 - 100, SCREEN_HEIGHT / 4, "Score: " + std::to_string(score), "CYAN");
}

extern "C"
{
    SDL_Lib *init_glib()
    {
        return (new SDL_Lib());
    }
}