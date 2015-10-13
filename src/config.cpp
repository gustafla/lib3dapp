#include "config.hpp"
#include <cstring>
#include <cstdlib>
#include "define.hpp"
#include <iostream>
#include <stdint.h>
#include <bcm_host.h>

Config::Config(int argc, char** argv):
fullscreen(false),
w(SCREEN_W),
h(SCREEN_H) {
    parseArgs(argc, argv);
}

void Config::parseArgs(int argc, char** argv) {
    int i=1;

    for (; i<argc; i++) {
        if (strcmp(argv[i], "--fullscreen") == 0) {
            fullscreen=true;
        } else {
            std::cout << "Unrecognized argument \"" << argv[i] << "\".\n";
            exit(ERR_SUCCESS);
        }
    }

    #ifdef RASPI_BUILD
        int errDisp;
        uint32_t actualW, actualH;
        if ((errDisp = graphics_get_display_size(0, &actualW, &actualH)) < 0) {
            exit(ERR_NO_RPI_DISPLAY_SIZE);
        }
        
        w = actualW;
        h = actualH;
    #endif
}
