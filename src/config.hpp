#pragma once

class Config {
    public:
        Config(int argc, char** argv);

        bool fullscreen;
        unsigned int w;
        unsigned int h;
        unsigned int display;
        
    private:
        void parseArgs(int argc, char** argv);
};
