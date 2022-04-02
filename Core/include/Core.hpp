/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <vector>
#include <unistd.h>
#include "../../Interface/include/ICore.hpp"
#include "../../Interface/include/ILibrary.hpp"
#include "../../Interface/include/IGame.hpp"
#include "../include/Exceptions.hpp"

#include "../../Dynamic_Library/include/Dyn_Lib.hpp"
#include "../../C_Directory/include/C_Directory.hpp"
#include "../../Score/include/Score.hpp"

class Core : public ICore {
    public:
        Core(std::string filename);
        ~Core();
        void startCore();
        void getGraphicals();
        void getGames();
        void truncateNames();
        void openGLib();
        void openGameLib();
        void Load_Score();
        void NextLib(bool);
        void PrevLib(bool);
        void Game();
    protected:
    private:
        std::string _libFile;
        std::string _gameName;
        std::vector<std::string> _graphsLibs;
        std::vector<std::string> _Glibs;
        std::vector<std::string> _games;
        std::vector<std::string> _gamesLibs;
        void *_handle;
        void *_handleG;
        ILibrary *_graphLib;
        IGame *_gameLib;
        unsigned int _selected;

        std::string _username;

        Dyn_Lib *_dynamic;
        C_Directory *_directory;
        Score *_score;
};

#endif /* !CORE_HPP_ */
