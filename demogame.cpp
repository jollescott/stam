#include "demogame.h"

#include <glad/glad.h>

DemoGame::DemoGame()
{
    mGeometry = new Geometry();
    mTrans = glm::mat4(1.0f);
}

bool DemoGame::init()
{
    if(!mGeometry->init()) {
        return false;
    }

    return Game::init();
}

void DemoGame::shutdown()
{
    mGeometry->shutdown();
}

void DemoGame::render()
{
    Game::render();

    glUseProgram(mGeometry->shader()->programId());
    glBindVertexArray(mGeometry->vao());

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void DemoGame::update(double dt)
{

}
