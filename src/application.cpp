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
    
#include "3dapp_application.hpp"
#include "3dapp_graphics.hpp"
#include "3dapp_vectors.hpp"
#include "3dapp_obj_file.hpp"
#include <cmath>
#include <iostream>
#include <cmath>
#include "3dapp_geo_primitives.hpp"

using namespace Lib3dapp;

Application::Application(Window& _window):
running(true),
window(_window) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    check();
}

bool Application::isRunning() {
    return running;
}

void Application::draw() {
    window.bindFramebuffer();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    window.swapBuffers();
    check();
}

