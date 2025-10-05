#ifndef __ABILITY_HH__
#define __ABILITY_HH__

#include "MathUtil.hh"

class Ability {
public:
    Ability(int startTick)
        : m_startTick(startTick)
    {}
    virtual bool finished(int tickNo) const
    {
        return tickNo >= m_startTick + m_duration;
    }
    // Returns true if the entity cannot move or perform other actions during this tick
    virtual bool animationLock(int tickNo){
        return false;
    }
    // Returns true if the entity can start a new ability during this tick
    virtual bool allowOtherAbilities(int tickNo){
        return false;
    }

    virtual point_t movementVector(int tickNo){
        return point_t(0,0);
    }
    //TODO hurtbox (relative to entity position)
    //TODO spawning entities
    //TODO damage amount

private:
    int m_startTick;
    int m_duration;

};

#endif