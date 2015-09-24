#include "game.hpp"
#include "graphics.hpp"

Game::Game(Window& _window):
running(true),
window(_window) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

bool Game::isRunning() {
    return running;
}

void Game::draw() {
    window.swapBuffers();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
