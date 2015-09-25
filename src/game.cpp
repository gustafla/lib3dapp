#include "game.hpp"
#include "graphics.hpp"
#include "vectors.hpp"

Game::Game(Window& _window):
running(true),
window(_window),
shader(shaderPath("simple.vert"), shaderPath("color.frag")) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    Mesh mesh;
    mesh.pushPosition(vec4( 1, -1, 0, 1));
    mesh.pushPosition(vec4( 0,  1, 0, 1));
    mesh.pushPosition(vec4(-1, -1, 0, 1));
    triangle = new StaticObject(mesh);
}

bool Game::isRunning() {
    return running;
}

void Game::draw() {
    shader.use();
    glUniform4f(shader.getUfmHandle("u_color"), 1.0, 1.0, 0.5, 1.0);
    triangle->draw(shader);
    
    window.swapBuffers();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
