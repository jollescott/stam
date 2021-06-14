#ifndef DEMOGAME_H
#define DEMOGAME_H

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "game.h"
#include "geometry.h"

class DemoGame : public Game
{
public:
    DemoGame();

    bool init() override;
    void shutdown() override;

    void render() override;
    void update(double dt) override;
private:
    Geometry* mGeometry;
};

#endif // DEMOGAME_H
