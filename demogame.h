#ifndef DEMOGAME_H
#define DEMOGAME_H

#include "game.h"

class DemoGame : public Game
{
public:
    DemoGame();

    void render() override;
};

#endif // DEMOGAME_H
