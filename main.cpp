#include "application.h"
#include "demogame.h"

int main()
{
    Application application;

    if(!application.init()) {
        application.shutdown();
        return -1;
    }

    DemoGame game;
    game.init();

    application.setGame(&game);

    while(application.running()) {
        application.loop();
    }

    application.shutdown();

    return 0;
}
