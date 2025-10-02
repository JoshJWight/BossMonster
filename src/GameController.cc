#include "GameController.hh"
#include <chrono>
#include <thread>
#include <iostream>

GameController::GameController() 
    : m_gameState(std::make_shared<GameState>())
    , m_graphics(std::make_shared<Graphics>()) 
{
}

void GameController::mainLoop() {
    while(true) {
        // Game loop logic here
        m_graphics->render();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 60));
        std::cout << "Hello World" << std::endl;
    }
}