#include "GameController.hh"
#include <chrono>
#include <thread>
#include <iostream>

GameController::GameController() 
    : m_gameState(std::make_shared<GameState>())
    , m_graphics(std::make_shared<Graphics>(1000,1000))
    , m_controls(std::make_shared<Controls>())
    , m_currentTick(0)
{
    std::shared_ptr<Character> hero(std::make_shared<Character>(point_t(0,0)));
    hero->id = 1;
    hero->size = point_t(1,1);
    hero->controllerType = PLAYER;
    hero->setupSprites({"smiley.png"});
    hero->angle_deg = 0;

    std::shared_ptr<Character> npc(std::make_shared<Character>(point_t(5,5)));
    npc->id = 2;
    npc->size = point_t(1,1);
    npc->controllerType = AI;
    npc->setupSprites({"frowny.png"});
    npc->angle_deg = 45;


    m_gameState->characters.push_back(hero);
    m_gameState->characters.push_back(npc);
    m_gameState->playerId = hero->id;
}

void GameController::mainLoop() {
    while(true) {
        m_currentTick++;
        m_controls->tick();
        tick();
        m_graphics->render(m_gameState);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 60));
    }
}

void GameController::tick() {
    //Update characters
    for(auto& character : m_gameState->characters) {
        bool animationLocked = false;
        bool canUseAbilities = true;
        point_t abilityMovement(0,0);
        for(auto& ability : character->activeAbilities) {
            abilityMovement += ability->movementVector(m_currentTick);
            std::cout << "Ability movement: " << abilityMovement.x << ", " << abilityMovement.y << std::endl;
            if(ability->animationLock(m_currentTick)) {
                animationLocked = true;
            }
            if(!ability->allowOtherAbilities(m_currentTick)) {
                canUseAbilities = false;
            }
        }
        character->position += abilityMovement;

        if(character->controllerType == PLAYER && !animationLocked) {
            if(m_controls->up) {
                character->position.y += character->maxSpeed;
            }
            if(m_controls->down) {
                character->position.y -= character->maxSpeed;
            }
            if(m_controls->left) {
                character->position.x -= character->maxSpeed;
            }
            if(m_controls->right) {
                character->position.x += character->maxSpeed;
            }
        }

        if(character->controllerType == PLAYER && canUseAbilities) {
            point_t mousePos = m_graphics->getMousePos();
            if(m_controls->skill1) {
                point_t dashDir = math_util::normalize(mousePos - character->position);
                character->activeAbilities.push_back(std::make_shared<Dash>(m_currentTick, dashDir));
                std::cout << "Dashdir: " << dashDir.x << ", " << dashDir.y << std::endl;
                std::cout << "Dash ability used" << std::endl;
            }
        }

        //TODO AI control
    }

    

    //Remove finished abilities
    for (auto& character : m_gameState->characters) {
        character->activeAbilities.erase(
            std::remove_if(
                character->activeAbilities.begin(),
                character->activeAbilities.end(),
                [this](const std::shared_ptr<Ability>& ability) {
                    return ability->finished(m_currentTick);
                }
            ),
            character->activeAbilities.end()
        );
    }
}