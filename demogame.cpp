#include "demogame.h"

#include <glad/glad.h>

DemoGame::DemoGame()
{

}

bool DemoGame::init()
{
    mVertices = std::vector<float> {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f,  0.5f, 0.0f
    };

    unsigned int vbo;
    glGenBuffers(1, &vbo);

    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(float), mVertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    mShader = new Shader("color");

    if(!mShader->init()) {
        return false;
    }

    return Game::init();
}

void DemoGame::shutdown()
{
    delete mShader;
    mShader = nullptr;
}

void DemoGame::render()
{
    Game::render();

    glUseProgram(mShader->programId());
    glBindVertexArray(mVAO);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}
