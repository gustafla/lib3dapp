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

    float frames=0;
    float tLast=0;
    const float TIME=5.0f;
    
    float projMatTrad[4*4];
    getPProjMat(projMatTrad, 45.0f, 1.0f);
    mat4  projMatNew = getPProjMat(45.0f, 1.0f);
    
    for (int i=0; i<4*4; i++) {
        std::cout << "Trd: " << i << ": " << projMatTrad[i] << std::endl;
        std::cout << "New: " << i << ": " << ((float*)&projMatNew)[i] << std::endl;
    }
    
    float mat2[4*4];
    multMat4(mat2, projMatTrad, projMatTrad);
    mat4  mat2new = projMatNew*projMatNew;
    
    std::cout << "----------------------------------MULT TEST---------------------\n";
    for (int i=0; i<4*4; i++) {
        std::cout << "Trd: " << i << ": " << mat2[i] << std::endl;
        std::cout << "New: " << i << ": " << ((float*)&mat2new)[i] << std::endl;
    }

    while(game.isRunning()) {
        game.draw();
        
        frames+=1;
        if (tLast+TIME < window.getTime()) {
            std::cout << "FPS: " << (frames/TIME) << std::endl;
            frames=0;
            tLast=window.getTime();
        }
    }

    return 0;
}
