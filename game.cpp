#include "game.h"

#include "glad/glad.h"

Game::Game()
{

}

bool Game::init()
{
    return true;
}

void Game::shutdown()
{

}

void Game::update(double dt)
{

}

void Game::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.1, 0.5, 0.4, 1.0);
}

void Game::resize(int width, int height) {
    this->width = width;
    this->height = height;

    glViewport(0,0, width, height);
}

int Game::getWidth() const
{
    return width;
}

int Game::getHeight() const
{
    return height;
}

