#include "config.hpp"
#include <cstring>
#include <cstdlib>
#include "define.hpp"
#include <iostream>
#include <stdint.h>
#include "graphics.hpp"
#include "util.hpp"

void argErr(std::string arg) {
    std::cout << "Invalid argument near " << arg << std::endl;
    exit(ERR_INVALID_ARGUMENT);
}

Config::Config(int argc, char** argv):
fullscreen(false),
w(SCREEN_W),
h(SCREEN_H),
display(0) {
    parseArgs(argc, argv);
}

void Config::parseArgs(int argc, char** argv) {
    std::string errorMessages[] = {
        " expects a natural number as a parameter.\n",
        " is not a valid parameter for ",
        "Failed to get display size.\n"
    };
    
    int i=1;

    for (; i<argc; i++) {
        if (strcmp(argv[i], "--fullscreen") == 0) {
            fullscreen=true;
        } else if (strcmp(argv[i], "--display") == 0) {
            i++;
            if (i < argc) {
                if (isdigits(std::string(argv[i]))) {
                    display = atoi(argv[i]);
                } else {
                    std::cout << argv[i] << errorMessages[1] << "--display.\n";
                    argErr(argv[i-1]);
                }
            } else {
                std::cout << "--display" << errorMessages[0];
                argErr(argv[i-1]);
            }
        } else {
            std::cout << "Unrecognized argument \"" << argv[i] << "\".\n";
            exit(ERR_INVALID_ARGUMENT);
        }
    }

    #ifdef RASPI_BUILD
        if (fullscreen) {
            uint32_t actualW, actualH;
            if ((graphics_get_display_size(0, &actualW, &actualH)) < 0) {
                std::cout << errorMessages[2];
                exit(ERR_NO_DISPLAY_SIZE);
            }
        
            w = actualW;
            h = actualH;
        }
    #else
        unsigned int n = SDL_GetNumVideoDisplays();
        if (display >= n) {
            std::cout << "No display " << display << " available.\n" << "Displays available: 0-" << n-1 << std::endl;
            exit(ERR_INVALID_ARGUMENT);
        }
        if (fullscreen) {
            SDL_DisplayMode mode;
            if ((SDL_GetCurrentDisplayMode(display, &mode)) != 0) {
                std::cout << errorMessages[2];
                exit(ERR_NO_DISPLAY_SIZE);
            }
            
            w=mode.w;
            h=mode.h;
        }
    #endif
}
