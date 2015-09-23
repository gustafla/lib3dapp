#include <iostream>
#include "window.hpp"
#include "config.hpp"
#include "game.hpp"

int main(int argc, char* argv[]) {
    const Config conf(argc, argv);
    Window gameWin(conf);
    Game game(gameWin);
    
    while(game.isRunning()) {
        game.draw();
    }

    return 0;
}
