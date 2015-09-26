#include "game.hpp"
#include "graphics.hpp"
#include "vectors.hpp"
#include "obj_file.hpp"
#include <cmath>
#include <iostream>
#include <cmath>

Game::Game(Window& _window):
running(true),
window(_window),
shader(shaderPath("mvp.vert"), shaderPath("color.frag")) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    Mesh mesh = loadOBJFile(meshPath("revision.obj"));
    triangle = new StaticObject(mesh);
    getPProjMat(projection, 45.0f, window.getAspect());
    mvp = new MVP(projection, 0.0, 0.0, -3.0f);
}

bool Game::isRunning() {
    return running;
}

void Game::draw() {
    getPProjMat(projection, 45.0f, window.getAspect());
    window.bindBuffer();
    glClearColor(sin(window.getTime()*M_PI)*0.5+0.5, 0.0, 0.0, 1.0);
    shader.use();
    glUniform4f(shader.getUfmHandle("u_color"), 1.0, 1.0, 0.5, 1.0);
    mvp->setModelRotation(M_PI/2.0, window.getTime()/2.0, window.getTime());
    mvp->buildModel();
    mvp->buildMVP();
    glUniformMatrix4fv(shader.getUfmHandle("mvp"), 1, GL_FALSE, mvp->mvp);
    triangle->draw(shader);
    
    window.swapBuffers();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
