#ifndef DEMOGAME_H
#define DEMOGAME_H

#include "game.h"

#include "geometry.h"

class DemoGame : public Game
{
public:
    DemoGame();

    bool init() override;
    void shutdown() override;

    void render() override;
private:
    Geometry* mGeometry;

    float* mVertices;
    int* mIndices;
};

#endif // DEMOGAME_H
