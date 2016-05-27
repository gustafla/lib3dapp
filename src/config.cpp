// Copyright 2016 Lauri Gustafsson
/*  This file is part of lib3dapp.

    lib3dapp is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    lib3dapp is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with lib3dapp.  If not, see <http://www.gnu.org/licenses/>.*/

#include "3dapp_config.hpp"
#include <cstring>
#include <cstdlib>
#include "3dapp_consts.hpp"
#include <iostream>
#include <stdint.h>
#include "3dapp_graphics.hpp"
#include "3dapp_util.hpp"

const ConfigParameter Config::reservedParams[Config::NUM_RESERVED_PARAMS] = {
    ConfigParameter("--fullscreen", 0),
    ConfigParameter("--display", 1),
    ConfigParameter("-w", 1),
    ConfigParameter("-h", 1)
};

void Lib3dapp::argErr(std::string arg) {
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
        } else if (strcmp(argv[i], "-w") == 0) {
            i++;
            if (i < argc) {
                if (isdigits(std::string(argv[i]))) {
                    w = atoi(argv[i]);
                } else {
                    std::cout << argv[i] << errorMessages[1] << "-w.\n";
                    argErr(argv[i-1]);
                }
            } else {
                std::cout << "-w" << errorMessages[0];
                argErr(argv[i-1]);
            }
        } else if (strcmp(argv[i], "-h") == 0) {
            i++;
            if (i < argc) {
                if (isdigits(std::string(argv[i]))) {
                    h = atoi(argv[i]);
                } else {
                    std::cout << argv[i] << errorMessages[1] << "-h.\n";
                    argErr(argv[i-1]);
                }
            } else {
                std::cout << "-h" << errorMessages[0];
                argErr(argv[i-1]);
            }
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
