#include "application.h"

#include <stdio.h>

Application::Application() : mRunning(true)
{

}

void Application::sdlError(const char *msg) {
    fprintf(stderr, "%s: %s\n", msg, SDL_GetError());
}

bool Application::init() {
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        sdlError("SDL failed to initialize.");
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

    mWindow = SDL_CreateWindow("Stam", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    if(mWindow == nullptr) {
        sdlError("Failed to create window");
        return false;
    }

    auto glContex = SDL_GL_CreateContext(mWindow);

    if(glContex == nullptr) {
        sdlError("Failed to create gl context.");
        return false;
    }

    gladLoadGLLoader(SDL_GL_GetProcAddress);

    return true;
}

void Application::shutdown() {

    if(mWindow != nullptr) {
        SDL_DestroyWindow(mWindow);
    }

    SDL_Quit();
}

void Application::loop() {
    auto now = SDL_GetPerformanceCounter();
    auto deltaTime = (double)((now - mLastTime) * 1000 / SDL_GetPerformanceFrequency());

    if(mGame) {
        mGame->render();
        mGame->update(deltaTime);
    }

    SDL_GL_SwapWindow(mWindow);

    while(SDL_PollEvent(&mEvent)) {

        switch(mEvent.type) {
        case SDL_WINDOWEVENT_RESIZED:

            if(mGame) {
                mGame->resize(mEvent.window.data1, mEvent.window.data2);
            }

            break;
        case SDL_QUIT:
            setRunning(false);
            break;
        }

    }

    mLastTime = now;
}

bool Application::running() const
{
    return mRunning;
}

void Application::setRunning(bool running)
{
    mRunning = running;
}

Game *Application::game() const
{
    return mGame;
}

void Application::setGame(Game *game)
{
    mGame = game;
}
