//gamestate.cpp

#include "header/gamestate.hpp"

bool GameState::getLoadSuccess() { return loadSuccess; }

int GameState::getNextState() { return nextState; }

void GameState::setWindow(Window* w) { window = w; }
