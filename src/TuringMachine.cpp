/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file TuringMachine.cpp
 */

#include "../include/TuringMachine.hpp"
#include "../include/GpUtils.hpp"
#include "../include/State.hpp"
#include "../include/TransitionBase.hpp"
#include "../include/TransitionValue.hpp"
#include "../include/TuringMachineState.hpp"
#include <iostream>
#include <string>

namespace mdtModels {
TuringMachine::TuringMachine() {
  states = std::vector<mdtModels::State<int>>();
  transitions = std::map<TransitionBase, TransitionValue>();
}

TuringMachine::~TuringMachine() {
  delete _initialState;
  delete _finalState;
}

// Permette di inserire un nuovo elemento all'interno della macchina di turing.
const bool TuringMachine::addNewState(int stateToInsert) {
  // Se lo stato non esiste restituisce false, altrimenti true.
  if (gpUtils::arrayContains(states, mdtModels::State<int>(stateToInsert)))
    return false;
  // Solo stati positivi.
  if (stateToInsert >= 0)
    states.push_back(State<int>(stateToInsert));
  return true;
}

const bool TuringMachine::setInitialState(const std::string &rawString) {
  int initialStateToInsert;
  // Parserizzo e controllo la stringa in input.
  if ((initialStateToInsert =
           gpUtils::checkInput<const std::string &>(rawString, 0, 100)) == -1) {
    return false;
  }
  // Controllo la validità dello stato (deve esistere).
  if (initialStateToInsert < 0 ||
      !gpUtils::arrayContains(states,
                              mdtModels::State<int>(initialStateToInsert)))
    return false;
  else
    _initialState = new mdtModels::State<int>(initialStateToInsert);
  return true;
}

const bool TuringMachine::setFinalState(const std::string &rawString) {
  // Come funzione precedente.
  int finalStateToInsert;
  if ((finalStateToInsert =
           gpUtils::checkInput<const std::string &>(rawString, 0, 100)) == -1) {
    return false;
  }

  bool result;
  if (finalStateToInsert < 0 ||
      !gpUtils::arrayContains(states,
                              mdtModels::State<int>(finalStateToInsert)))
    result = false;
  else {
    _finalState = new mdtModels::State<int>(finalStateToInsert);
    result = true;
  }
  return result;
}

const std::vector<mdtModels::State<int>> TuringMachine::getStates() {
  return states;
}

const std::string TuringMachine::printStates() {
  std::string result;
  for (mdtModels::State<int> item : states) {
    result += "[";
    result += std::to_string(item.getState());
    result += "] ";
  }
  return result;
}

const bool
TuringMachine::insertTransition(int state, char symbol, int nextState,
                                char nextSymbol,
                                const mdtModels::Movement &nextMove) {
  // Controllo la validità degli stati inseriti nella transizione.
  if (!gpUtils::arrayContains(states, mdtModels::State<int>(state)) ||
      !gpUtils::arrayContains(states, mdtModels::State<int>(nextState)))
    return false;
  // Creo una chiave della mappa.
  mdtModels::TransitionBase key = mdtModels::TransitionBase(state, symbol);
  // Creo il valore della mappa.
  mdtModels::TransitionValue value =
      mdtModels::TransitionValue(nextState, nextSymbol, nextMove);
  // Inserisco (con eventuale sovrascrittura).
  transitions[key] = value;
  return true;
}

const bool TuringMachine::checkStatusPresent(int state) {
  return gpUtils::arrayContains(states, mdtModels::State<int>(state));
}

const std::string &TuringMachine::printTransitions() {
  std::string *result = new std::string();
  for (const std::pair<mdtModels::TransitionBase, mdtModels::TransitionValue>
           &item : transitions) {
    *result += "(";
    *result += std::to_string(item.first.state.getState());
    *result += ",";
    *result += item.first.symbol;
    *result += ") => (";
    *result += std::to_string(item.second.state.getState());
    *result += ",";
    *result += item.second.symbol;
    *result += ",";
    *result += item.second.getMovementRappr();
    *result += ")\n";
  }
  return *result;
}

const mdtModels::State<int> &TuringMachine::getInitialState() {
  return *_initialState;
}

const mdtModels::State<int> &TuringMachine::getFinalState() {
  return *_finalState;
}

const std::map<mdtModels::TransitionBase, mdtModels::TransitionValue>
TuringMachine::getTransitions() {
  return transitions;
}
} // namespace mdtModels