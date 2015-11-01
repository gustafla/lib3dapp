#include "game.hpp"
#include "graphics.hpp"
#include "vectors.hpp"
#include "obj_file.hpp"
#include <cmath>
#include <iostream>
#include <cmath>

Game::Game(Window& _window):
running(true),
window(_window) {
    Shader vertexShader(shaderPath("mvptex.vert"));
    Shader fragmentShader(shaderPath("showtex_var.frag"));
    shaderProgram = new Program(vertexShader, fragmentShader);
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    check();
    projection = getPProjMat(45.0f, window.getAspect());
    mvp = new MVP(projection, 0.0, 0.0, -5.0f);
    shaderProgram->use();
    check();
    glUniform1i(shaderProgram->getUfmHandle("iChannel0"), 0);
    check();
    //glEnable(GL_CULL_FACE);
    //glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    check();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    check();
}

bool Game::isRunning() {
    return running;
}

void Game::draw() {
    resources.getTexture("test.tga")->bindToUnit(0);
    check();
    projection = getPProjMat(45.0, window.getAspect());
    window.bindBuffer();
    check();
    glClearColor(sin(window.getTime()*M_PI)*0.5+0.5, 0.0, 0.0, 1.0);
    check();
    shaderProgram->use();
    check();
    //glUniform4f(shader.getUfmHandle("u_color"), 1.0, 1.0, 0.5, 1.0);
    mvp->setModelRotation(0.0, window.getTime()/2.0, window.getTime());
    mvp->buildModel();
    mvp->buildMVP();
    glUniformMatrix4fv(shaderProgram->getUfmHandle("mvp"), 1, GL_FALSE, mvp->getMVPArray());
    check();
    resources.getStaticModel("cube_tex.obj")->draw(*shaderProgram);
    check();
    
    window.swapBuffers();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    check();
}
