#include "Controls.hh"

Controls::Controls()
    : up(false), down(false), left(false), right(false), skill1(false), skill2(false), skill3(false), skill4(false), skill5(false)
    , m_leftMouse(false), m_rightMouse(false), m_rightMouseLastState(false), m_leftMouseLastState(false)
{
    m_actOnPressKeys.push_back(sf::Keyboard::E);
    m_actOnPressKeys.push_back(sf::Keyboard::F);
    m_actOnPressKeys.push_back(sf::Keyboard::R);
    m_actOnPressKeys.push_back(sf::Keyboard::Q);
    m_actOnPressKeys.push_back(sf::Keyboard::Space);

    for(auto key : m_actOnPressKeys)
    {
        m_lastStateMap[key] = false;
    }
}

void Controls::tick()
{
    m_currentKeys[sf::Keyboard::W] = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    m_currentKeys[sf::Keyboard::S] = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    m_currentKeys[sf::Keyboard::A] = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    m_currentKeys[sf::Keyboard::D] = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    m_currentKeys[sf::Keyboard::F] = sf::Keyboard::isKeyPressed(sf::Keyboard::F);
    m_currentKeys[sf::Keyboard::E] = sf::Keyboard::isKeyPressed(sf::Keyboard::E);
    m_currentKeys[sf::Keyboard::R] = sf::Keyboard::isKeyPressed(sf::Keyboard::R);
    m_currentKeys[sf::Keyboard::Q] = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
    m_currentKeys[sf::Keyboard::LShift] = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
    m_currentKeys[sf::Keyboard::Space] = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
    m_leftMouse = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    m_rightMouse = sf::Mouse::isButtonPressed(sf::Mouse::Right);

    doTick();
}

void Controls::doTick()
{
    up = m_currentKeys[sf::Keyboard::W];
    down = m_currentKeys[sf::Keyboard::S];
    left = m_currentKeys[sf::Keyboard::A];
    right = m_currentKeys[sf::Keyboard::D];

    skill1 = m_currentKeys[sf::Keyboard::Space] && !m_lastStateMap[sf::Keyboard::Space];
    skill2 = m_currentKeys[sf::Keyboard::Q] && !m_lastStateMap[sf::Keyboard::Q];
    skill3 = m_currentKeys[sf::Keyboard::E] && !m_lastStateMap[sf::Keyboard::E];
    skill4 = m_currentKeys[sf::Keyboard::R] && !m_lastStateMap[sf::Keyboard::R];
    skill5 = m_currentKeys[sf::Keyboard::F] && !m_lastStateMap[sf::Keyboard::F];



    m_rightMouseLastState = m_rightMouse;
    m_leftMouseLastState = m_leftMouse;
    for(auto key : m_actOnPressKeys)
    {
        m_lastStateMap[key] = m_currentKeys[key];
    }
}
