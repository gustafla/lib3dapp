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

#ifdef RASPI_BUILD
#include <bcm_host.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>
#include <SDL/SDL.h>
#else
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#endif

#include <string>

#define INT2P(i) (static_cast<char*>(0) + (i))
#define check() checkGl(__FILE__, __LINE__)

/* The call with string and int parameters should be optimized out in release as the function will be empty? */
/* Assert? Who needs that thing? :DDDD */

void checkGl(std::string file, int line);
void initializeGraphics();
void cleanupGraphics();
