/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** NCurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <unistd.h>
#include <iostream>
#include "../../../Interface/include/ILibrary.hpp"

class NCURSES_Lib : public ILibrary 
{
public:
    NCURSES_Lib() {std::cout << "Ncurses Initialized\n";};
    ~NCURSES_Lib() {};

    void create_window();//done
    void draw_player(std::string, int, int, int);//done
    void draw_menu();//done
    void draw_game(std::vector<std::string> map, std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>);//done
    void disp_text(int, int, std::string, std::string color);//done
    ILibrary::Input_t getInput();//done
    std::string enter_name();//done
    void destroy_window();//done
    std::string getName() { return "NCURSES"; };

    void clear();//done
    void update();//done

    std::string getUsername() { return _username; };
    void setName(std::string);

    void draw_line(std::string line, int h, int); //done
    void game_selector(std::vector<std::string>, unsigned int);

    void clock_s();
    void draw_score(pair_t score, std::string name);
    void draw_currentScore(int);


private:
    std::string _username;
};

#endif /* !NCURSES_Lib_HPP_ */