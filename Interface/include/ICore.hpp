/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-hugo.humez
** File description:
** ICore
*/

#ifndef ICORE_HPP_
#define ICORE_HPP_

class ICore {
    public:
        virtual ~ICore() = default;
        virtual void startCore() = 0;
        virtual void getGraphicals() = 0;
        virtual void getGames() = 0;
        virtual void openGLib() = 0;
        virtual void openGameLib() = 0;
        virtual void Load_Score() = 0;
        virtual void NextLib(bool) = 0;
        virtual void PrevLib(bool) = 0;
        virtual void Game() = 0;
    protected:
    private:
};

#endif /* !ICORE_HPP_ */
