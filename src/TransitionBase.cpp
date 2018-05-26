/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file TransitionKey.cpp
 */

#include "../include/TransitionBase.h"
#include "../lib/catch.hpp"
#include "../include/State.h"

mdtModels::TransitionBase::TransitionBase() {}

mdtModels::TransitionBase::TransitionBase(int currentState,
                                          char currentSymbol) {
  this->state = State<int>(currentState);
  this->symbol = currentSymbol;
}

mdtModels::TransitionBase::~TransitionBase() {}

const std::string mdtModels::TransitionBase::getMovementRappr() const {
  return "";
}

bool mdtModels::operator<(const TransitionBase &one,
                          const TransitionBase &that) {
  return (one.state.getState() == that.state.getState()) ? one.symbol < that.symbol
                                 : one.state.getState() < that.state.getState();
}
