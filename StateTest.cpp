#include "StateTest.h"

StateTest::StateTest() {
    this->add(&this->testObject);
}

StateTest::~StateTest() {
    this->remove(&this->testObject);
}