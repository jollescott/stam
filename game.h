#ifndef GAME_H
#define GAME_H


class Game
{
public:
    Game();

    virtual bool init();
    virtual void shutdown();

    virtual void update(double dt);
    virtual void render();

    void resize(int width, int height);

    int getWidth() const;
    int getHeight() const;

private:

    int width, height;
};

#endif // GAME_H
