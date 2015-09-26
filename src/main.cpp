#include <iostream>
#include "window.hpp"
#include "config.hpp"
#include "game.hpp"
#include "vectors.hpp"
#include <vector>

int main(int argc, char* argv[]) {
    const Config conf(argc, argv);
    Window window(conf);
    Game game(window);

    while(game.isRunning()) {
        game.draw();
    }

    return 0;
}
