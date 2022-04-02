/*
** EPITECH PROJECT, 2021
** Score
** File description:
** utils
*/

#include <iostream>
#include <algorithm>
#include "../include/Score.hpp"

bool is_score(std::string score)
{
    for (size_t i = 0; i != score.length(); i++) {
        if (!isdigit(score[i]))
            return false;
    }
    return true;
}

bool sort_best(const std::pair<std::string, int> &a, const std::pair<std::string,int> &b)
{
    return (a.second < b.second);
}