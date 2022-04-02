/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** score
*/

#include "../include/Score.hpp"

Score::Score()
{}

Score::~Score()
{}

void Score::dump_map()
{
    for (auto i = _allscores.begin(); i != _allscores.end(); i++) {
        std::cout << "Scores of:" + i->first << std::endl;
        for (size_t y = 0; y < i->second.size(); y++) {
            std::cout << i->second[y] << std::endl;
        }
        std::cout << std::endl;
    }
}

void Score::dump_best()
{
    for (auto it = _allbests.begin(); it != _allbests.end(); it++)
        std::cout << it->first << "\t" << it->second << std::endl;
}

void Score::create_map()
{
    std::string score;
    size_t i = 0;
    size_t p;
    std::string current = "none";

    _allscores.clear();
    for (i = 0; i != _usernames.size(); i++)
        _allscores[_usernames[i]];
    fs.open(file);
    while (getline(fs, score)) {
        if (score.length() >= 2 && (p = score.find(':')) != std::string::npos)
            current = score.substr(0, p);
        else if (is_score(score) && current != "none")
            _allscores[current].push_back(score);
    }
    for (auto it = _allscores.begin(); it != _allscores.end(); it++) {
        std::sort(it->second.begin(), it->second.end());
        std::reverse(it->second.begin(), it->second.end());
    }
    fs.close();
}

void Score::update_file()
{
    fs.open(file, std::ios_base::out);
    for (auto z = _allscores.begin(); z != _allscores.end(); z++) {
        fs << z->first << ":" << std::endl;
        for (size_t x = 0; x != z->second.size(); x++)
            fs << z->second[x] << std::endl;
    }
    fs.close();
}

void Score::fetch_names(std::string fil)
{
    file = "./saves/score_";
    std::string line;
    size_t p;

    _usernames.clear();
    file += fil;
    fs.open(file);
    while (getline(fs, line)) {
        if (line.length() >= 2 && (p = line.find(':')) != std::string::npos)
            _usernames.push_back(line.substr(0, p));
    }
    fs.close();
}

void Score::get_5best()
{
    int size;

    if ((size = 5 - _allbests.size()) > 0) {
        for (; size != 0; size--) {
            _allbests.push_back(std::make_pair("_____", std::atoi("0000")));
        }
    }
    std::sort(_allbests.begin(), _allbests.end(), sort_best);
    std::reverse(_allbests.begin(), _allbests.end());
    if (size < 0) {
        _allbests.resize(5);
    }
}

void Score::fetch_bests()
{
    _allbests.clear();
    for (auto it = _allscores.begin(); it != _allscores.end(); it++) {
        if (!it->second.empty())
            _allbests.push_back(std::make_pair(it->first, std::atoi(it->second.front().c_str())));
    }
    get_5best();
}

void Score::addScore(std::string user, int score)
{
    _allscores[user];
    _allscores[user].push_back(std::to_string(score));
}