#ifndef __CHARACTER_HH__
#define __CHARACTER_HH__

#include "MathUtil.hh"
#include "Ability.hh"
#include "TextureBank.hh"

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

    void setupSprites(std::initializer_list<const char*> filenames)
    {
        for(auto filename : filenames)
        {
            sf::Sprite sprite;
            sprite.setTexture(TextureBank::get(filename));
            sprites.push_back(sprite);
        }
    }
    
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