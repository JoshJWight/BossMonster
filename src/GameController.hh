#ifndef __GAMECONTROLLER_HH__
#define __GAMECONTROLLER_HH__

#include <memory>

#include "GameState.hh"
#include "Graphics.hh"
#include "Controls.hh"

class GameController {
public:
    GameController();

    void mainLoop();
private:
    void tick();

    int m_currentTick;

    std::shared_ptr<GameState> m_gameState;
    std::shared_ptr<Graphics> m_graphics;
    std::shared_ptr<Controls> m_controls;

};


#endif