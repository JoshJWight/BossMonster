#ifndef __GAMESTATE_HH__
#define __GAMESTATE_HH__

#include <vector>
#include <memory>
#include "Character.hh"

struct GameState {
    int playerId;

    std::vector<std::shared_ptr<Character>> characters;

};

#endif