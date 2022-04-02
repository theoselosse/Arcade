/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** C_Directory
*/

#ifndef C_DIRECTORY_HPP_
#define C_DIRECTORY_HPP_

#include <dirent.h>
#include <sys/stat.h>

#include "../../Interface/include/IC_Directory.hpp"

class C_Directory : public IC_Directory {
    public:
        C_Directory();
        ~C_Directory();
        void c_opendir(const char *);
        std::vector<std::string> c_readdir();
        void c_closedir();

    protected:
    private:
        DIR *_folder;
};

#endif /* !C_DIRECTORY_HPP_ */
