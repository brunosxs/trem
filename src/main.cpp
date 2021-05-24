#include "constants.h"
#include <iostream>
#include "game.h"
int main(int argc, char *args[]) {
    //TODO 
    //ADD LOGIC

    Game *game = new Game();
    game->initialize(WINDOW_WIDTH,WINDOW_HEIGTH);
    game->set_run(true);
    while(game->is_running()) {
        game->process_input();
        game->update();
        game->render();
    }

    game->destroy();
    return 0;
}
