#include "Graphics.hh"

#include <iostream>
#include <algorithm>

Graphics::Graphics(int windowWidth, int windowHeight)
    :m_window(sf::VideoMode(windowWidth, windowHeight), "Fixed History"),
     m_windowSize(windowWidth, windowHeight),
     m_cameraScale(windowWidth / 500.0)
{
    m_window.setMouseCursorVisible(true);
}

void Graphics::setSpriteScale(sf::Sprite & sprite, point_t worldSize)
{
    const sf::Texture * texture = sprite.getTexture();
    sf::Vector2f texSize(texture->getSize());
    sf::Vector2f scale(m_cameraScale * worldSize);
    scale = math_util::elementwise_divide(scale, texSize);

    sprite.setScale(scale);
    sprite.setOrigin(texSize.x / 2.0f, texSize.y / 2.0f);
}

 void Graphics::render(std::shared_ptr<GameState> gameState)
{
    m_cameraWorldPos = point_t(0,0);
    if(gameState->characters.size() > 0)
        m_cameraWorldPos = gameState->characters[0]->position;

    sf::Event event;
    while(m_window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            std::cout << "Window closed, exiting." << std::endl;
            m_window.close();
            exit(0);
        }
        if(event.type == sf::Event::MouseWheelMoved)
        {
            float scaleLog = std::log10(m_cameraScale);
            scaleLog += event.mouseWheel.delta * 0.1;
            m_cameraScale = std::pow(10, scaleLog);
        }
    }

    m_window.clear();

    


    m_window.display();
}

void Graphics::drawCharacter(Character* c)
{
    if(c->sprites.size() == 0)
        throw std::runtime_error("Character has no sprites to draw");

    //For now just draw the first sprite, needs to be changed when animations are added
    sf::Sprite & sprite = c->sprites[0];

    setSpriteScale(sprite, c->size);

    point_t cameraPos = worldToCamera(c->position);
    sprite.setPosition(sf::Vector2f(cameraPos));
    sprite.setRotation(c->angle_deg * -1.0f);
    m_window.draw(sprite);
}

point_t Graphics::getMousePos()
{
    sf::Vector2f mouseCameraPos(sf::Mouse::getPosition(m_window));

    return cameraToWorld(mouseCameraPos);
}

point_t Graphics::worldToCamera(point_t worldPoint)
{
    point_t worldDiff = worldPoint - m_cameraWorldPos;
    point_t cameraDiff = worldDiff * m_cameraScale;
    //In SFML the +y axis is downwards on the screen, but my world space
    //has +y as the up direction, because I find it easier to think in
    cameraDiff.y *= -1.0f;
    return cameraDiff + (m_windowSize / 2.0f);
}


point_t Graphics::cameraToWorld(sf::Vector2f cameraPoint)
{
    point_t point(cameraPoint);
    point -= m_windowSize / 2.0f;
    point.y *= -1.0f;
    point /= m_cameraScale;
    point += m_cameraWorldPos;
    return point;
}
