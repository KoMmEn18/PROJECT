#include "State.h"

State::State() : m_previous(nullptr) {}

void State::setPrevious(State * state)
{
    m_previous = state;
}