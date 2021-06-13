#ifndef DEMOGAME_H
#define DEMOGAME_H

#include <vector>

#include "game.h"
#include "shader.h"

class DemoGame : public Game
{
public:
    DemoGame();

    bool init() override;
    void shutdown() override;

    void render() override;
private:
    unsigned int mVAO;

    Shader* mShader;
    std::vector<float> mVertices;
};

#endif // DEMOGAME_H
