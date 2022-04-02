/*
** EPITECH PROJECT, 2021
** Score
** File description:
** Score
*/

#ifndef SCORE_HPP_
#define SCORE_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <cstdlib>

typedef std::map<std::string, std::vector<std::string>> map_t;
typedef std::vector<std::pair<std::string, int>> pair_t;

bool is_score(std::string score);
bool sort_best(const std::pair<std::string, int> &a, const std::pair<std::string,int> &b);


class Score {
    public:
        Score();
        ~Score();
        void fetch_names(std::string);
        void fetch_bests(void);
        
        void get_5best();
        map_t getAllscores() {return _allscores;};
        pair_t getAllbests() {return _allbests;};
        void addScore(std::string, int);

        void create_map(void);

        void update_file(void);

        void dump_map();
        void dump_best();

    protected:
    private:
        std::fstream fs;
        map_t _allscores;
        pair_t _allbests;
        std::string file;
        std::vector<std::string> _usernames;
};

#endif /* !SCORE_HPP_ */
