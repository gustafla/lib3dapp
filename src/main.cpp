#include <iostream>
#include "window.hpp"
#include "config.hpp"
#include "game.hpp"
#include "vectors.hpp"
#include <vector>

int main(int argc, char* argv[]) {
    const Config conf(argc, argv);
    Window gameWin(conf);
    Game game(gameWin);

/* ------------------------------------------VECTOR DEBUG TEST ------------- */

    std::vector<vec4> vertices;
    vertices.push_back(vec4(1.0f, -1.0f, 0.0f, 1.0f));
    vertices.push_back(vec4(0.0f, 1.0f, 0.0f, 1.0f));
    vertices.push_back(vec4(-1.0f, -1.0f, 0.0f ,1.0f));

    float* array = (float*)&vertices[0];
    float array2[3*4];
    for (int i=0; i<3; i++) {
        array2[i] = (vertices[i]).x;
        array2[i+1] = (vertices[i]).y;
        array2[i+2] = (vertices[i]).z;
        array2[i+3] = (vertices[i]).w;
    }

    std::cout << "vec4 size expected: " << 4*4 << "\nvec4 size: " << sizeof(vec4) << std::endl;

    for (int i=0; i<vertices.size()*4; i++) {
        std::cout << array[i] << std::endl;
    }

    std::cout << "----------------------------------------\n";

    for (int i=0; i<3*4; i++) {
        std::cout << array2[i] << std::endl;
    }
    
/* ------------------------------------------------------------------------- */

    while(game.isRunning()) {
        game.draw();
    }

    return 0;
}
