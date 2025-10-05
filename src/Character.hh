#ifndef __CHARACTER_HH__
#define __CHARACTER_HH__

#include "MathUtil.hh"
#include "Ability.hh"

#include <vector>

#include <SFML/Graphics/Sprite.hpp>

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
    point_t size;
    ControllerType controllerType;
    std::vector<sf::Sprite> sprites;

    //State
    point_t position;
    float angle_deg;
    std::vector<Ability> activeAbilities;

};
#endif