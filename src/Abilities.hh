#ifndef __ABILITIES_HH__
#define __ABILITIES_HH__

#include "Ability.hh"

class Dash : public Ability {
public:
    const int DASH_DURATION = 10;
    const float DASH_SPEED = 1.5f;

    Dash(int startTick, point_t direction);

    bool animationLock(int tickNo) override {
        return true;
    }
    point_t movementVector(int tickNo) override;

private:
    point_t m_direction;
};

#endif