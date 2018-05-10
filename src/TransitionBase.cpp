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
using namespace mdtModels;
using namespace std;

mdtModels::TransitionBase::TransitionBase() {}

mdtModels::TransitionBase::TransitionBase(int currentState,
                                          char currentSymbol) {
  this->state = currentState;
  this->symbol = currentSymbol;
}

mdtModels::TransitionBase::~TransitionBase() {}

bool mdtModels::operator<(const TransitionBase &one,
                          const TransitionBase &that) {
  return one.state == that.state ? one.symbol < that.symbol
                                 : one.state < that.state;
}
