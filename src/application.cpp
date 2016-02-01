#include "application.hpp"
#include "graphics.hpp"
#include "vectors.hpp"
#include "obj_file.hpp"
#include <cmath>
#include <iostream>
#include <cmath>
#include "geo_primitives.hpp"

Application::Application(Window& _window):
running(true),
window(_window) {
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
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
