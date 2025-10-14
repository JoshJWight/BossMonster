#ifndef __ABILITIES_HH__
#define __ABILITIES_HH__

#include "Ability.hh"

class Dash : public Ability {
public:
    const int DASH_DURATION = 20;

    Dash(int startTick, point_t direction);

    bool animationLock(int tickNo) override {
        return true;
    }
    point_t movementVector(int tickNo) override;

private:
    point_t m_direction;
};

#endif