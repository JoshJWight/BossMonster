#include "Abilities.hh"

Dash::Dash(int startTick, point_t direction)
    : Ability(startTick), m_direction(math_util::normalize(direction))
{
    m_duration = DASH_DURATION;
}

point_t Dash::movementVector(int tickNo)
{
    return m_direction;
}