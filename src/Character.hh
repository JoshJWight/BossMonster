#ifndef __CHARACTER_HH__
#define __CHARACTER_HH__

#include "MathUtil.hh"
#include "Ability.hh"

#include <vector>

class Character {
public:
    Character(point_t _position)
        : position(_position)
    {}
    
    //State

    int id;

    point_t position;
    std::vector<Ability> activeAbilities;

};
#endif