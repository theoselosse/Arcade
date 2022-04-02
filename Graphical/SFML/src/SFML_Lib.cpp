/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** sfml graphics source file
*/

#include "../include/SFML_Lib.hpp"
#include <unistd.h>

void SFML_Lib::setName(std::string name)
{
    _player_name_entered = name;
}

SFML_Lib::SFML_Lib()
{
    std::cout << "SFML Initialized" << std::endl;
    if (!_m_b_texture.loadFromFile("Graphical/SFML/assets/bg_m_sfml.png"))
        exit(84);
    _m_b_sprite.setTexture(_m_b_texture);
    if (!_gl_n_m_texture.loadFromFile("Graphical/SFML/assets/graph_lib_n_sfml.png"))
        exit(84);
    _gl_n_m_sprite.setTexture(_gl_n_m_texture);
    _gl_n_m_sprite.setPosition(1500, 0);
    if (!_proj_n_m_texture.loadFromFile("Graphical/SFML/assets/proj_n_sfml.png"))
        exit(84);
    _proj_n_m_sprite.setTexture(_proj_n_m_texture);
    _proj_n_m_sprite.setPosition(100, 10);
    if (!_font.loadFromFile("Graphical/SFML/assets/aokay.ttf"))
        exit(84);
    if (!_m_player_texture.loadFromFile("Graphical/SFML/assets/m_player_sfml.png"))
        exit(84);
    _m_player_sprite.setTexture(_m_player_texture);
    if (!_m_player_r_texture.loadFromFile("Graphical/SFML/assets/m_player_sfml_reverse.png"))
        exit(84);
    _m_player_r_sprite.setTexture(_m_player_r_texture);
    if (!_m_player2_texture.loadFromFile("Graphical/SFML/assets/m_player2_sfml.png"))
        exit(84);
    _m_player2_sprite.setTexture(_m_player2_texture);
    if (!_m_fruit_texture.loadFromFile("Graphical/SFML/assets/m_fruit_sfml.png"))
        exit(84);
    _m_fruit_sprite.setTexture(_m_fruit_texture);
    if (!background_text_sfml_texture.loadFromFile("Graphical/SFML/assets/background_text_sfml.png"))
        exit(84);
    background_text_sfml_sprite.setTexture(background_text_sfml_texture);
     if (!wall_sfml_texture.loadFromFile("Graphical/SFML/assets/wall_sfml.png"))
        exit(84);
    wall_sfml_sprite.setTexture(wall_sfml_texture);
    _m_player2_sprite.setOrigin(16, 16);
    background_text_sfml_sprite.setOrigin(16, 16);
    wall_sfml_sprite.setOrigin(16, 16);
    _m_fruit_sprite.setOrigin(16, 16);
    _m_player_sprite.setOrigin(16, 16);
    _m_player_r_sprite.setOrigin(16, 16);
    _text.setCharacterSize(50);
    _text.setFont(_font);
    _window.setFramerateLimit(60);
    _dir = 0;
    _run = false;
}

void SFML_Lib::create_window()
{
    _window.create(sf::VideoMode(1920, 1080), "ARCADE - SFML",
                   sf::Style::Resize);
}

void SFML_Lib::destroy_window()
{
    _window.close();
}

void SFML_Lib::update()
{
    _window.display();
}

void SFML_Lib::clear()
{
    _window.clear(sf::Color::Black);
}

void SFML_Lib::draw_player(std::string color,int x, int y, int dir)
{
    //_m_player_sprite.setOrigin(16, 16);
    if (color == "WHITE") {
        wall_sfml_sprite.setPosition(x, y);
        _window.draw(wall_sfml_sprite);
    } else if (color == "YELLOW") {
        background_text_sfml_sprite.setPosition(x, y);
        _window.draw(background_text_sfml_sprite);
    } else if (color == "BLACK") {
        background_text_sfml_sprite.setPosition(x, y);
        _window.draw(background_text_sfml_sprite);
        _m_player2_sprite.setPosition(x, y);
        _window.draw(_m_player2_sprite);
    } else if (color == "RED") {
        background_text_sfml_sprite.setPosition(x, y);
        _window.draw(background_text_sfml_sprite);
        _m_fruit_sprite.setPosition(x, y);
        _window.draw(_m_fruit_sprite);
    } else if (color == "GREEN") {
        background_text_sfml_sprite.setPosition(x, y);
        _window.draw(background_text_sfml_sprite);
        _m_player2_sprite.setPosition(x, y);
        _window.draw(_m_player2_sprite);
    } else if (color == "DGREEN") {
        background_text_sfml_sprite.setPosition(x, y);
        _window.draw(background_text_sfml_sprite);
        if (dir == 2) {
            _m_player_sprite.setRotation(0);
            _m_player_sprite.setPosition(x, y);
            _window.draw(_m_player_sprite);
        } else if (dir == 1) {
            _m_player_sprite.setPosition(x, y);
            _m_player_sprite.setRotation(90);
            _window.draw(_m_player_sprite);
        } else if (dir == 3) {
            _m_player_sprite.setPosition(x, y);
             _m_player_sprite.setRotation(270);
            _window.draw(_m_player_sprite);
        } else if (dir == 4) {
            _m_player_r_sprite.setPosition(x, y);
            _window.draw(_m_player_r_sprite);
        } else {
            if (_dir == 2) {
                _m_player_r_sprite.setPosition(x, y);
                _window.draw(_m_player_r_sprite);
            } else {
                _m_player_sprite.setPosition(x, y);
                _window.draw(_m_player_sprite);
            }
        }
    } else {
        background_text_sfml_sprite.setPosition(x, y);
        _window.draw(background_text_sfml_sprite);
    }
}

void SFML_Lib::draw_game(std::vector<std::string> map, std::vector<std::pair<int, int>> p, std::vector<std::pair<int, int>> temp)
{
    int dir = 0;

    if (temp.front().second < p.front().second) {
        dir = 2;
        _dir = 1;
    } else if (temp.front().first < p.front().first) {
        dir = 1;
        _dir = 1;
    } else if (temp.front().first > p.front().first) {
        dir = 3;
        _dir = 1;
    } else if (temp.front().second > p.front().second) {
        dir = 4;
        _dir = 2;
    } else
        dir = 0;
    
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
    int h = 200;
    for (unsigned int i = 0; i < map.size(); i++, h += 32) {
        draw_line(map[i], h, dir);
    }
}

void SFML_Lib::draw_menu()
{
    _window.draw(_m_b_sprite);
    _window.draw(_gl_n_m_sprite);
    _window.draw(_proj_n_m_sprite);
}

ILibrary::Input_t SFML_Lib::getInput()
{
    if (!_window.pollEvent(_event))
        return (NONE);
    if (_event.type == sf::Event::Closed)
        return (ESCAPE);
    if (_event.type == sf::Event::KeyPressed)
    {
        switch (_event.key.code) {
        case sf::Keyboard::Enter:
            return (ENTER);
        case sf::Keyboard::Left:
            return (LEFT);
        case sf::Keyboard::Right:
            return (RIGHT);
        case sf::Keyboard::Up:
            return (UP);
        case sf::Keyboard::Down:
            return (DOWN);
        case sf::Keyboard::Escape:
            return (ESCAPE);
        case sf::Keyboard::Space:
            return (PLAY);
        case sf::Keyboard::O:
            return (PREV);
        case sf::Keyboard::P:
            return (NEXT);
        default:
            return (NONE);
        }
    }
    return (NONE);
}

std::string SFML_Lib::enter_name()
{
    while (_run == false)
    {
        clear();
        while (_window.pollEvent(_event))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                _run = true;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
                _player_name_entered = _player_name_entered.substr(0, _player_name_entered.length() - 1);
            else if (_event.type == sf::Event::TextEntered)
            {
                _player_name_entered += _event.text.unicode;
            }
        }
        draw_menu();
        disp_text(750, 300, "ENTER YOU NAME :", "Red");
        disp_text(850, 400, _player_name_entered, "Magenta");
        update();
    }
    if (_player_name_entered.empty() || _player_name_entered.size() == 1)
    {
        _player_name_entered = "guest";
        return ("guest");
    }
    return _player_name_entered;
}

void SFML_Lib::disp_text(int x, int y, std::string content, std::string color)
{
    if (color == "RED")
        _text.setFillColor(sf::Color::Red);
    else if (color == "WHITE")
        _text.setFillColor(sf::Color::White);
    else if (color == "YELLOW")
        _text.setFillColor(sf::Color::Yellow);
    else if (color == "GREEN")
        _text.setFillColor(sf::Color::Green);
    else if (color == "CYAN")
        _text.setFillColor(sf::Color::Cyan);
    else
        _text.setFillColor(sf::Color::Black);
    _text.setPosition(x, y);
    _text.setString(content);
    _window.draw(_text);
}

void SFML_Lib::draw_line(std::string line, int h, int dir)
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
            draw_player("BLACK", x, h, dir);
    }
}

void SFML_Lib::game_selector(std::vector<std::string> _games, unsigned int _selected)
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

void SFML_Lib::clock_s()
{
    usleep(70000);
}

void SFML_Lib::draw_score(pair_t score, std::string name)
{
    int h = 500;

    std::string title = "Bests of " + name;
    disp_text(100, 400, title, "RED");
    _text.setCharacterSize(40);
    for (auto i = score.begin(); i != score.end(); i++, h += 80) {
        disp_text(150, h, i->first.substr(0, 5) + "  :  ", "YELLOW");
        disp_text(400, h, std::to_string(i->second), "CYAN");
    }
    _text.setCharacterSize(50);
}

void SFML_Lib::draw_currentScore(int score)
{
    disp_text(SCREEN_WIDTH / 4 - 100, SCREEN_HEIGHT / 4, "Score: " + std::to_string(score), "RED");
}

extern "C"
{
    SFML_Lib *init_glib()
    {
        return (new SFML_Lib());
    }
}