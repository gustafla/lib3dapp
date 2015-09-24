#include "config.hpp"
#include <cstring>
#include <cstdlib>
#include "define.hpp"
#include <iostream>

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
            exit(0);
        }
    }
}
