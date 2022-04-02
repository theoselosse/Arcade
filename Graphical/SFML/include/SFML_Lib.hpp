/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** sfml graphics class
*/

#ifndef ARCADE_SFML_H
#define ARCADE_SFML_H

#include "../../../Interface/include/ILibrary.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class SFML_Lib : public ILibrary
{
public:
    SFML_Lib();
    ~SFML_Lib() { _window.close(); };

    void create_window();
    void draw_game(std::vector<std::string> map);
    void draw_game(std::vector<std::string> map, std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>);
    void draw_player(std::string, int, int, int);
    void draw_menu();
    void disp_text(int, int, std::string, std::string color);
    ILibrary::Input_t getInput();
    std::string enter_name();
    void destroy_window();
    std::string getName() { return "SFML"; };

    void clear();
    void update();

    std::string getUsername() { return _player_name_entered; };
    void setName(std::string);

    void draw_line(std::string line, int h, int dir);
    void game_selector(std::vector<std::string>, unsigned int);

    void clock_s();
    void draw_score(pair_t, std::string);
    void draw_currentScore(int);

protected:
private:
    std::string _player_name_entered;
    sf::RenderWindow _window;
    sf::Texture _m_b_texture;
    sf::Sprite _m_b_sprite;
    sf::Texture _gl_n_m_texture;
    sf::Sprite _gl_n_m_sprite;
    sf::Texture _proj_n_m_texture;
    sf::Sprite _proj_n_m_sprite;
    sf::Texture _m_player_texture;
    sf::Sprite _m_player_sprite;
    sf::Texture _m_player_r_texture;
    sf::Sprite _m_player_r_sprite;
    sf::Texture _m_player2_texture;
    sf::Sprite _m_player2_sprite;
    sf::Texture _m_fruit_texture;
    sf::Sprite _m_fruit_sprite;
    sf::Texture background_text_sfml_texture;
    sf::Sprite background_text_sfml_sprite;
    sf::Texture wall_sfml_texture;
    sf::Sprite wall_sfml_sprite;
    sf::Font _font;
    sf::Event _event;
    sf::Text _text;
    int _dir;
    bool _run;
};

#endif /* !ARCADE_SFML_H */
