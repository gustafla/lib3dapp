#include <iostream>
#include "window.hpp"
#include "config.hpp"
#include "application.hpp"
#include "vectors.hpp"
#include <vector>
#include "graphics.hpp"

int main(int argc, char* argv[]) {
    const Config conf(argc, argv);
    Window window(conf);
    Application game(window);

    float frames=0;
    float tLast=0;
    const float TIME=5.0f;

    while(game.isRunning()) {
        game.draw();
        
        frames+=1;
        if (tLast+TIME < window.getTime()) {
            std::cout << "FPS: " << (frames/TIME) << std::endl;
            frames=0;
            tLast=window.getTime();
        }
        
        check();
    }

    return 0;
}
