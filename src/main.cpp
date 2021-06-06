#include "constants.h"
#include <iostream>
#include "game.h"


#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>
    #include "test_game.h"

int main(int argc, char *args[]) {

    doctest::Context ctx;
    ctx.setOption("abort-after", 5);  // default - stop after 5 failed asserts
    ctx.applyCommandLine(argc, args); // apply command line - argc / argv
    ctx.setOption("no-breaks", true); // override - don't break in the debugger
    int res = ctx.run();              // run test cases unless with --no-run
    if(ctx.shouldExit())              // query flags (and --exit) rely on this
        return res;


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
