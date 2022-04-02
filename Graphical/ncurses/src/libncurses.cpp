/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** NCurses
*/

#include <iostream>
#include <sstream>
#include <ncurses.h>
#include "../../ncurses/include/NCURSES_Lib.hpp"

void NCURSES_Lib::setName(std::string name)
{
    _username = name;
}

void NCURSES_Lib::draw_line(std::string line, int h, int dir)
{
    int x = COLS / 2 - 10;

    for (unsigned int i = 0; i < line.length(); i++, x += 1) {
        if (line[i] == 'X')
            draw_player("WHITE", h, x, line[i]);
        else if (line[i] == 'O')
            draw_player("YELLOW", h, x, line[i]);
        else if (line[i] == 'o')
            draw_player("GREEN", h, x, line[i]);
        else if (line[i] == 'F')
            draw_player("RED", h, x, line[i]);
        else if (line[i] == 'H')
            draw_player("DGREEN", h, x, line[i]);
    }
}

void NCURSES_Lib::destroy_window()
{
    clear();
    endwin();
}

void NCURSES_Lib::disp_text(int x, int y, std::string string, std::string color)
{
    int which_color = 0;

    if (color == "YELLOW" || color == "Y")
        which_color = 1;
    else if (color == "GRAY")
        which_color = 2;
    else if (color == "RED")
        which_color = 4;
    else if (color == "GREEN" || color == "CYAN")
        which_color = 5;
    else if (color == "WHITE")
        which_color = 6;
    else if (color == "DGREEN")
        which_color = 8;

    attron(COLOR_PAIR(which_color));
    mvprintw(x, y, string.c_str());
    attroff(COLOR_PAIR(which_color));
}

void NCURSES_Lib::draw_player(std::string color, int x, int y, int dir)
{
    attron(COLOR_PAIR(4));
    mvprintw(x, y, std::to_string(dir).c_str());
    attroff(COLOR_PAIR(4));
}

void NCURSES_Lib::draw_game(std::vector<std::string> map, std::vector<std::pair<int, int>> p, std::vector<std::pair<int, int>> temp)
{
    for (unsigned int i = 0; i != p.size(); i++) {
        for (unsigned int j = 0; j != map.size(); j++) {
            for (unsigned int k = 0; k != map[j].length(); k++) {
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

    int h = 10;

    for (unsigned int i = 0; i < map.size(); i++, h++)
        disp_text(h, COLS / 2 - 10, map[i], "RED");
}

ILibrary::Input_t NCURSES_Lib::getInput()
{
    switch (getch()) {
        case KEY_UP:
            return ILibrary::Input_t::UP;
        case KEY_DOWN:
            return ILibrary::Input_t::DOWN;
        case KEY_LEFT:
            return ILibrary::Input_t::LEFT;
        case KEY_RIGHT:
            return ILibrary::Input_t::RIGHT;
        case ' ':
            return ILibrary::Input_t::PLAY;
        case 'o':
            return ILibrary::Input_t::PREV;
        case 'p':
            return ILibrary::Input_t::NEXT;
        default:
            return ILibrary::Input_t::NONE;
    }
}

std::string NCURSES_Lib::enter_name()
{
    int key;
    std::string str;
    char c;

    disp_text(8, COLS / 2 - 10, "Enter a username:", "RED");
    while ((key = getch()) != '\n') {
        if (key != ERR) {
            c = key;
            if (key == 263 && str.length() > 0) {
                str = str.substr(0, str.length() - 1);
                clear();
            }
            else if (key != ' ' && key != 263)
                str += c;
            disp_text(8, COLS/ 2 - 10, "Enter a username:", "RED");
            disp_text(10, COLS / 2 - 8, str.c_str(), "GREEN");
        }
        refresh();
    }
    clear();
    if (str.empty()) {
        _username = "guest";
        return "guest";
    }
    _username = str;
    return str;
}

void NCURSES_Lib::create_window()
{
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    curs_set(FALSE);
    start_color();
    nodelay(stdscr, TRUE);
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    init_pair(6, COLOR_BLUE, COLOR_BLACK);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(8, COLOR_WHITE, COLOR_BLACK);
}

void NCURSES_Lib::clear()
{
    ::clear();
}

void NCURSES_Lib::update()
{
    refresh();
}

void print_menu(std::string ascii[6], std::string pacman[5], int color_s, int color_p)
{
    char str [100];
    int y = 10;

    for (int i = 0; i < 6; i++, y++) {
        ascii[i].copy(str, ascii[i].size() + 1);
        str[ascii[i].size()] = '\0';
        attron(COLOR_PAIR(color_s));
        mvprintw(y, (COLS/2) - 60, str);
        attroff(COLOR_PAIR(color_s));
    }
    y = 10;
    for (int j = 0; j < 5; j++, y++) {
    attron(COLOR_PAIR(color_p));
    pacman[j].copy(str, pacman[j].size() + 1);
    str[pacman[j].size()] = '\0';
    mvprintw(y, COLS/2 + 10, str);
    attroff(COLOR_PAIR(color_p));
    }
}

void NCURSES_Lib::game_selector(std::vector<std::string> _games, unsigned int _selected)
{
    std::string lib = "Current lib: " + getName();
    std::string name = "Welcome " + getUsername();
    int h = 12;

    disp_text(8, 238 / 2 - 10, name, "RED");
    for (unsigned int i = 0; i != _games.size(); i++, h += 2) {
        if (_selected != i)
            disp_text(h, COLS / 2 - 6, _games[i], "RED");
        else
            disp_text(h, COLS / 2 - 6, _games[i], "GREEN");
    }
    disp_text(9, 20, lib, "RED");
}

void NCURSES_Lib::draw_menu()
{
}

void NCURSES_Lib::clock_s()
{
    usleep(80000);
}

void NCURSES_Lib::draw_score(pair_t score, std::string name)
{
    int h = 18;

    std::string title = "Bests of " + name + "   ";
    disp_text(14, 20, title, "RED");
    for (auto i = score.begin(); i != score.end(); i++, h += 3) {
        disp_text(h, 20, i->first.substr(0, 5) + "    :    ", "Y");
        disp_text(h, 35, std::to_string(i->second) + "   ", "GRAY");
    }
}

void NCURSES_Lib::draw_currentScore(int score)
{
    disp_text(LINES / 4, COLS / 4, "Score: " + std::to_string(score), "RED");
}

extern "C" {
    NCURSES_Lib *init_glib() {
        return (new NCURSES_Lib());
    }
}
