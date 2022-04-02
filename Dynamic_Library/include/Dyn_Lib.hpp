/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** Dyn_Lib
*/

#ifndef DYN_LIB_HPP_
#define DYN_LIB_HPP_

#include <dlfcn.h>
#include "../../Interface/include/IDyn_Lib.hpp"

class Dyn_Lib : public IDyn_Lib{
    public:
        Dyn_Lib();
        ~Dyn_Lib();

        void *dl_open(const char *);
        void *dl_sym(void *, const char *);
        char *dl_error();
        void dl_close(void *);
    
        
    protected:
    private:
};

#endif /* !DYN_LIB_HPP_ */
