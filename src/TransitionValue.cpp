/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file TransitionValue.cpp
 */

#include "../include/TransitionValue.hpp"
#include "../include/State.hpp"
#include <iostream>

namespace mdtModels {
TransitionValue::TransitionValue() {}

TransitionValue::TransitionValue(int nextState, char nextSymbol,
                                 const mdtModels::Movement &nextMoveP)
    : mdtModels::TransitionBase(nextState, nextSymbol) {
  nextMove = nextMoveP;
}

TransitionValue::~TransitionValue() {}

const std::string TransitionValue::getMovementRappr() const {
  return (nextMove == mdtModels::Movement::L
              ? "L"
              : ((nextMove == mdtModels::Movement::R) ? "R" : "N"));
}
} // namespace mdtModels