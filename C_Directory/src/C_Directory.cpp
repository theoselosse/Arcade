/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** C_Directory
*/

#include "../include/C_Directory.hpp"

C_Directory::C_Directory()
{}

C_Directory::~C_Directory()
{}

void C_Directory::c_opendir(const char *path)
{
    _folder = opendir(path);
}

std::vector<std::string> C_Directory::c_readdir()
{
    std::vector<std::string> temp;
    struct dirent *content;
    std::string name;


    if (_folder != nullptr) {
        while ((content = readdir(_folder))) {
            struct stat st{};
            stat(content->d_name, &st);
            name = content->d_name;
            if (name.size() > 3 && name.substr(name.size() - 3, 3) == ".so")
                temp.push_back(name);
        }
    }
    return temp;
}

void C_Directory::c_closedir()
{
    closedir(_folder);
}