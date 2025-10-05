#ifndef __GRAPHICS_HH__
#define __GRAPHICS_HH__

#include "GameState.hh"
#include "Character.hh"
#include "MathUtil.hh"
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>

class Graphics {
public:
    Graphics(int windowWidth, int windowHeight);

    void render(std::shared_ptr<GameState> gameState);
    point_t getMousePos();

    float m_cameraScale;

    sf::RenderWindow m_window;

    point_t m_cameraWorldPos;

    point_t m_windowSize;

    void drawCharacter(Character* c);
    void setSpriteScale(sf::Sprite & sprite, point_t worldSize);
    point_t worldToCamera(point_t worldPoint);
    point_t cameraToWorld(sf::Vector2f cameraPoint);
};

#endif