#ifndef __GAMECONTROLLER_HH__
#define __GAMECONTROLLER_HH__

#include <memory>

#include "GameState.hh"
#include "Graphics.hh"

class GameController {
public:
    GameController();

    void mainLoop();
private:
    std::shared_ptr<GameState> m_gameState;
    std::shared_ptr<Graphics> m_graphics;


};


#endif