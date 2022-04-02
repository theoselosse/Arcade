/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** IC_Directory
*/

#ifndef IC_DIRECTORY_HPP_
#define IC_DIRECTORY_HPP_

#include <vector>
#include <iostream>
#include <string>

class IC_Directory {
    public:
        virtual ~IC_Directory() = default;
        virtual void c_opendir(const char *) = 0;
        virtual std::vector<std::string> c_readdir() = 0;
        virtual void c_closedir() = 0;

    protected:
    private:
};

#endif /* !IC_DIRECTORY_HPP_ */
