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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

