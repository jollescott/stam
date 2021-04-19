#include "demogame.h"

#include <glad/glad.h>

DemoGame::DemoGame()
{

}

void DemoGame::render()
{
    glClearColor(0.1, 0.5, 0.4, 1.0);
    Game::render();
}
