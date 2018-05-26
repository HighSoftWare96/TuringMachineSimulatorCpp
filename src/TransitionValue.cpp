/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file TransitionValue.cpp
 */

#include "../include/TransitionValue.h"
#include "../include/State.h"
#include <iostream>

mdtModels::TransitionValue::TransitionValue() {}

mdtModels::TransitionValue::TransitionValue(int nextState, char nextSymbol,
                                            const mdtModels::Movement& nextMoveP)
    : mdtModels::TransitionBase(nextState, nextSymbol) {
  this->nextMove = nextMoveP;
}

mdtModels::TransitionValue::~TransitionValue() {}