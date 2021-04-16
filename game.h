#ifndef GAME_H
#define GAME_H


class Game
{
public:
    Game();

    bool init();
    void shutdown();

    void update(double dt);
    void render();

    void resize(int width, int height);

    int getWidth() const;
    int getHeight() const;

private:

    int width, height;
};

#endif // GAME_H
