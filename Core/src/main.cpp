/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** main
*/

#include <iostream>
#include "../include/Core.hpp"

void print_usage()
{
    throw customException("USAGE:\n\t./arcade lib\n\nDESCRIPTION:\n\tlib\t\tpath to the graphical lib\n");
}

void check_usage(int ac)
{
    if (ac < 2 || ac > 2) {
        print_usage();
    }
}

int main(int ac, char **av)
{
    try {
        check_usage(ac);
        Core core(av[1]);
        core.startCore();
        return 0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 84;
    }
}