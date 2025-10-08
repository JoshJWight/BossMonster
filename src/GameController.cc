#include "GameController.hh"
#include <chrono>
#include <thread>
#include <iostream>

GameController::GameController() 
    : m_gameState(std::make_shared<GameState>())
    , m_graphics(std::make_shared<Graphics>(1000,1000))
    , m_currentTick(0)
{
    std::shared_ptr<Character> hero(std::make_shared<Character>(point_t(0,0)));
    hero->id = 1;
    hero->size = point_t(1,1);
    hero->controllerType = PLAYER;
    hero->setupSprites({"smiley.png"});
    m_gameState->characters.push_back(hero);
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
            abilityMovement += ability.movementVector(m_currentTick);
            if(ability.animationLock(m_currentTick)) {
                animationLocked = true;
            }
            if(!ability.allowOtherAbilities(m_currentTick)) {
                canUseAbilities = false;
            }
        }
        character->position += abilityMovement;

        if(character->controllerType == PLAYER && !animationLocked) {
            if(m_controls->up) {
                character->position.y -= 1;
            }
            if(m_controls->down) {
                character->position.y += 1;
            }
            if(m_controls->left) {
                character->position.x -= 1;
            }
            if(m_controls->right) {
                character->position.x += 1;
            }
        }

        //TODO add new abilities from input
    }

    

    //Remove finished abilities
    for (auto& character : m_gameState->characters) {
        character->activeAbilities.erase(
            std::remove_if(
                character->activeAbilities.begin(),
                character->activeAbilities.end(),
                [this](const Ability& ability) {
                    return ability.finished(m_currentTick);
                }
            ),
            character->activeAbilities.end()
        );
    }
}