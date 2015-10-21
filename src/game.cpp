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
shader(shaderPath("mvptex.vert"), shaderPath("showtex_var.frag")) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    projection = getPProjMat(45.0f, window.getAspect());
    mvp = new MVP(projection, 0.0, 0.0, -5.0f);
    shader.use();
    glUniform1i(shader.getUfmHandle("iChannel0"), 0);
    //glEnable(GL_CULL_FACE);
    //glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

bool Game::isRunning() {
    return running;
}

void Game::draw() {
    resources.getTexture("test.tga")->bindToUnit(0);
    projection = getPProjMat(45.0, window.getAspect());
    window.bindBuffer();
    glClearColor(sin(window.getTime()*M_PI)*0.5+0.5, 0.0, 0.0, 1.0);
    shader.use();
    //glUniform4f(shader.getUfmHandle("u_color"), 1.0, 1.0, 0.5, 1.0);
    mvp->setModelRotation(0.0, window.getTime()/2.0, window.getTime());
    mvp->buildModel();
    mvp->buildMVP();
    glUniformMatrix4fv(shader.getUfmHandle("mvp"), 1, GL_FALSE, mvp->getMVPArray());
    resources.getStaticModel("cube_tex.obj")->draw(shader);
    
    window.swapBuffers();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
