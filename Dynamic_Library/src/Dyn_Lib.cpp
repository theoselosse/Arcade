/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** Dyn_Lib
*/

#include "../include/Dyn_Lib.hpp"

Dyn_Lib::Dyn_Lib()
{}

Dyn_Lib::~Dyn_Lib()
{}

void *Dyn_Lib::dl_open(const char *filename)
{
    return (dlopen(filename, RTLD_LOCAL | RTLD_LAZY));
}

void *Dyn_Lib::dl_sym(void * handle, const char * sym)
{
    return dlsym(handle, sym);
}

char *Dyn_Lib::dl_error()
{
    return dlerror();
}

void Dyn_Lib::dl_close(void *_handle)
{
    dlclose(_handle);
}
