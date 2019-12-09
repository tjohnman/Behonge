#include "State.h"
#include "ObjectTest.h"

#ifndef STATETEST_H
#define STATETEST_H

class StateTest : public State {
public:
    StateTest();
    ~StateTest();

private:
    ObjectTest testObject;
};

#endif
