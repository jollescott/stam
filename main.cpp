#include "application.h"
#include "game.h"

int main()
{
    Application application;

    if(!application.init()) {
        application.shutdown();
        return -1;
    }

    Game game;
    game.init();

    application.setGame(&game);

    while(application.running()) {
        application.loop();
    }

    application.shutdown();

    return 0;
}
