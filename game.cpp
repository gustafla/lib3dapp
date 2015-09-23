#include "game.hpp"
#include "graphics.hpp"

Game::Game(Window& _gameWin):
running(true),
gameWin(_gameWin) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

bool Game::isRunning() {
    return running;
}

void Game::draw() {
    gameWin.swapBuffers();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
