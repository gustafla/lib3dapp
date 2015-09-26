#include "game.hpp"
#include "graphics.hpp"
#include "vectors.hpp"
#include "obj_file.hpp"
#include <cmath>

Game::Game(Window& _window):
running(true),
window(_window),
shader(shaderPath("simple.vert"), shaderPath("color.frag")) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    Mesh mesh = loadOBJFile(meshPath("revision.obj"));
    triangle = new StaticObject(mesh);
}

bool Game::isRunning() {
    return running;
}

void Game::draw() {
    window.bindBuffer();
    glClearColor(sin(window.getTime()*M_PI)*0.5+0.5, 0.0, 0.0, 1.0);
    shader.use();
    glUniform4f(shader.getUfmHandle("u_color"), 1.0, 1.0, 0.5, 1.0);
    triangle->draw(shader);
    
    window.swapBuffers();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
