#ifndef CONTROLS_HH
#define CONTROLS_HH

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include <map>
#include <vector>

class Controls {
public:
    Controls();

    void tick();

    short encode();

    bool up;
    bool down;
    bool left;
    bool right;

    bool skill1;
    bool skill2;
    bool skill3;
    bool skill4;
    bool skill5;

private:
    void doTick();

    std::map<sf::Keyboard::Key, bool> m_currentKeys;
    std::map<sf::Keyboard::Key, bool> m_lastStateMap;
    std::vector<sf::Keyboard::Key> m_actOnPressKeys;

    bool m_leftMouse;
    bool m_rightMouse;
    bool m_leftMouseLastState;
    bool m_rightMouseLastState;
};

#endif