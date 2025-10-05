#ifndef __CHARACTER_HH__
#define __CHARACTER_HH__

#include "MathUtil.hh"
#include "Ability.hh"

#include <vector>

enum ControllerType {
    PLAYER,
    AI
};

class Character {
public:
    Character(point_t _position)
        : position(_position)
    {}
    
    //Permanent attributes
    int id;
    ControllerType controllerType;

    //State
    point_t position;
    std::vector<Ability> activeAbilities;

};
#endif