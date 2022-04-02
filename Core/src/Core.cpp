/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** Core
*/

#include "../include/Core.hpp"

Core::Core(std::string filename)
{
    _libFile = std::move(filename);
    std::cout << "Core created..." << std::endl;
    _directory = new C_Directory;
    getGraphicals();
    getGames();
    truncateNames();
    _dynamic = new Dyn_Lib;
    openGLib();
    _selected = 0;
    _score = new Score;
}

Core::~Core()
{
}

void Core::NextLib(bool is_menu)
{
    if (_Glibs.size() == 1)
        return;
    _graphLib->destroy_window();
    delete _graphLib;
    _dynamic->dl_close(_handle);
    std::string lib = "./lib/";

    for (unsigned int i = 0; i != _Glibs.size(); i++)
    {
        if ((lib + _Glibs.at(i)) == _libFile)
        {
            if (i + 1 < _Glibs.size()) {
                _libFile = lib + _Glibs.at(i + 1);
            }
            else {
                _libFile = lib + _Glibs.at(0);
            }
            break;
        }
    }
    openGLib();
    _graphLib->setName(_username);
    if (is_menu == true)
        startCore();
    else
        Game();
}

void Core::PrevLib(bool is_menu)
{
    if (_Glibs.size() == 1)
        return;
    _graphLib->destroy_window();
    delete _graphLib;
    _dynamic->dl_close(_handle);
    std::string lib = "./lib/";

    for (unsigned int i = 0; i != _Glibs.size(); i++)
    {
        if ((lib + _Glibs[i]) == _libFile)
        {
            if (i > 0)
                _libFile = lib + _Glibs[i - 1];
            if (i == 0)
                _libFile = lib + _Glibs[_Glibs.size() - 1];
            else
                _libFile = lib + _Glibs[0];
            break;
        }
    }
    openGLib();
    _graphLib->setName(_username);
    if (is_menu == true)
        startCore();
    else
        Game();
}

void Core::Game()
{
    _graphLib->clear();
    std::vector<std::string> m = _gameLib->getMap();
    std::vector<std::pair<int,int>> temp = _gameLib->getPlayer();
    std::vector<std::pair<int,int>> p = _gameLib->getPlayer();
    bool won = false;
    bool lost = false;

    _graphLib->draw_game(m, p, temp);
    _graphLib->update();

    int last = 0;
    int input = 0;

    while (!won && !lost) {
        if (input != 0) {
            last = input;
        }
        input = _graphLib->getInput();
        if (input == ILibrary::Input_t::NEXT)
            NextLib(false);
        else if (input == ILibrary::Input_t::PREV)
            PrevLib(false);
        p = _gameLib->getPlayer();
        m = _gameLib->getMap();
        _graphLib->update();
        _gameLib->play(input, last);
        _graphLib->draw_game(_gameLib->getMap(), p, temp);
        _graphLib->draw_currentScore(_gameLib->getScore());
        if (_gameLib->getPlayer().empty()) {
            lost = true;
            continue;
        }
        if (_gameLib->getMap().empty()) {
            won = true;
            continue;
        }
        temp = p;
        _graphLib->clock_s();
    }
    _score->addScore(_username, _gameLib->getScore());
    _score->update_file();
    if (lost) {
        _graphLib->destroy_window();
        _dynamic->dl_close(_handle);
        std::cout << "You loose with a score of: " << _gameLib->getScore() << std::endl;
        exit(0);
    } else {
        _graphLib->destroy_window();
        _dynamic->dl_close(_handle);
        std::cout << "You win with a score of: " << _gameLib->getScore() << std::endl;
        exit(0);
    }
}

void Core::Load_Score()
{
     _score->fetch_names(_games[_selected]);
    _score-> create_map();
    _score->fetch_bests();
}

void Core::startCore()
{
    int input;

    Load_Score();
    _graphLib->draw_score(_score->getAllbests(), _games[_selected]);
    if (_username.empty())
        _username = _graphLib->enter_name();
    while ((input = _graphLib->getInput()) != ILibrary::Input_t::PLAY) {
        _graphLib->draw_menu();
        _graphLib->draw_score(_score->getAllbests(), _games[_selected]);
        if (input == ILibrary::Input_t::DOWN && _selected + 1 <= _games.size() - 1) {
            _selected++;
            Load_Score();
        }
        else if (input == ILibrary::Input_t::UP && _selected == 1) {
            _selected--;
            Load_Score();
        }
        _graphLib->game_selector(_games, _selected);
        _graphLib->update();
        if (input == ILibrary::Input_t::NEXT)
            NextLib(true);
        else if (input == ILibrary::Input_t::PREV)
            PrevLib(true);
    }
    // Game Part
    _gameName = "./lib/" + _gamesLibs[_selected];
    openGameLib();
    Game();
}

void Core::truncateNames()
{
    for (long unsigned int i = 0; i != _Glibs.size(); i++)
        _graphsLibs.push_back(_Glibs[i].substr(7, _Glibs[i].size() - 10));
    for (long unsigned int i = 0; i != _gamesLibs.size(); i++)
        _games.push_back(_gamesLibs[i].substr(7, _gamesLibs[i].size() - 10));
}

void Core::getGraphicals()
{
    std::vector<std::string> temp;

    _directory->c_opendir("./lib/graphs");
    temp = _directory->c_readdir();
    _directory->c_closedir();
    _Glibs = temp;
}

void Core::getGames()
{
    std::vector<std::string> temp;

    _directory->c_opendir("./lib/games/");
    temp = _directory->c_readdir();
    _directory->c_closedir();
    _gamesLibs = temp;
}

void Core::openGLib()
{
    ILibrary *(*init_glib)();
    _handle = _dynamic->dl_open(_libFile.c_str());

    if (!_handle)
    {
        _dynamic->dl_error();
        throw customException("Error while opening library: " + _libFile);
    }
    init_glib = reinterpret_cast<ILibrary *(*)()>(dlsym(_handle, "init_glib"));
    if (!init_glib)
    {
        _dynamic->dl_error();
        _dynamic->dl_close(_handle);
        throw customException("Error while linking library: " + _libFile);
    }
    _graphLib = init_glib();
    _graphLib->create_window();
}

void Core::openGameLib()
{
    IGame *(*init_gamelib)();
    _handleG =_dynamic->dl_open(_gameName.c_str());
    if (!_handleG)
    {
        _dynamic->dl_error();
        throw customException("Error while opening library: " + _gameName);
    }
    init_gamelib = reinterpret_cast<IGame *(*)()>(_dynamic->dl_sym(_handleG, "init_gamelib"));
    if (!init_gamelib)
    {
        _dynamic->dl_error();
        _dynamic->dl_close(_handleG);
        throw customException("Error while linking library: " + _gameName);
    }
    _gameLib = init_gamelib();
}