/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file TransitionValue.cpp
 */

#include "../include/TransitionValue.h"
using namespace mdtModels;
using namespace std;

mdtModels::TransitionValue::TransitionValue() {}

mdtModels::TransitionValue::TransitionValue(int nextState, char nextSymbol,
                                            Movement nextMove)
    : TransitionBase(nextState, nextSymbol) {
  this->nextMove = nextMove;
}

TransitionValue::~TransitionValue() {}
