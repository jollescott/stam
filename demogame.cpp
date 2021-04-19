#include "demogame.h"

#include <glad/glad.h>

DemoGame::DemoGame()
{

}

bool DemoGame::init()
{
    mVertices = new float[18] {
        // first triangle
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f,  0.5f, 0.0f,  // top left
        // second triangle
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left
    };

    mIndices = new int[6] {
        0, 1, 3,
        1, 2, 3
    };

    mGeometry = new Geometry();
    mGeometry->init();

    mGeometry->setVertices(mVertices);
    mGeometry->setIndices(mIndices);

    mGeometry->prepare();

    return Game::init();
}

void DemoGame::shutdown()
{
    delete mGeometry;
    mGeometry = nullptr;

    delete [] mVertices;
    mVertices = nullptr;

    delete []  mIndices;
    mIndices = nullptr;
}

void DemoGame::render()
{
    glClearColor(0.1, 0.5, 0.4, 1.0);

    glBindVertexArray(mGeometry->vao());

    Game::render();
}
