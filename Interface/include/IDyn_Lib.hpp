/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** IDyn_Lib
*/

#ifndef IDYN_LIB_HPP_
#define IDYN_LIB_HPP_

class IDyn_Lib {
    public:
        virtual ~IDyn_Lib() = default;

        virtual void *dl_open(const char *) = 0;
        virtual void *dl_sym(void *, const char *) = 0;
        virtual char *dl_error() = 0;
        virtual void dl_close(void *) = 0;

    protected:
    private:
};

#endif /* !IDYN_LIB_HPP_ */
