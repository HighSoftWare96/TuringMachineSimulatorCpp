/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file TransitionBase.cpp
 */

#include "../include/TransitionBase.hpp"
#include "../include/State.hpp"
namespace mdtModels {
TransitionBase::TransitionBase() {}

TransitionBase::TransitionBase(int currentState, char currentSymbol) {
  this->state = State<int>(currentState);
  this->symbol = currentSymbol;
}

TransitionBase::~TransitionBase() {}

const std::string TransitionBase::getMovementRappr() { return ""; }

bool operator<(const TransitionBase &one, const TransitionBase &that) {
  return (one.state.getState() == that.state.getState())
             ? one.symbol < that.symbol
             : one.state.getState() < that.state.getState();
}
} // namespace mdtModels