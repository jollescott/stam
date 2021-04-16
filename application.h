#ifndef APPLICATION_H
#define APPLICATION_H

#include <glad/glad.h>
#include <SDL.h>

#include "game.h"

class Application
{
public:
    Application();

    static void sdlError(const char* msg);

    bool init();
    void shutdown();

    void loop();

    bool running() const;

    void setRunning(bool running);

    Game *game() const;
    void setGame(Game *game);

private:

    SDL_Window* mWindow;
    SDL_Event mEvent;

    bool mRunning;
    Uint64 mLastTime;

    Game* mGame;
};

#endif // APPLICATION_H
