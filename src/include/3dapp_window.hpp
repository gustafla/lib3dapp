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

#pragma once

#include "3dapp_config.hpp"
#include "3dapp_vectors.hpp"
#include "3dapp_graphics.hpp"
#include <string>

namespace Lib3dapp {
    class Window {
        public:
        Window(const Config& conf, std::string caption="", vec2 realsize=vec2(0), float alpha=1.0f);
        ~Window();
        void close();
        void swapBuffers();
        void bindFramebuffer();
        float getTime();
        unsigned int getWidth();
        unsigned int getHeight();
        float getAspect();
        void resize(unsigned int w, unsigned int h);
        void restoreViewport();
        void setCaption(std::string caption="");
            
        private:
        #ifdef RASPI_BUILD
        EGLNativeWindowType window;
        EGLDisplay display;
        EGLContext context;
        EGLSurface buffer;
        #else
        SDL_Window* window;
        SDL_GLContext context;
        #endif
        SDL_Event events;
        unsigned int width;
        unsigned int height;
        float aspect;
    };
};

using namespace Lib3dapp;
