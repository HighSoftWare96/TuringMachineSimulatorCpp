/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file TuringMachine.cpp
 */

#include "../include/TuringMachine.h"
#include "../include/GpUtils.h"
#include "../include/TransitionBase.h"
#include "../include/TransitionValue.h"
#include "../include/TuringMachineState.h"
#include "../include/State.h"

#include <iostream>
#include <string>

using namespace mdtModels;
using namespace std;
using namespace gpUtils;

TuringMachine::TuringMachine() {
  this->states = new vector<State<int>>();
  this->transitions = new map<TransitionBase, TransitionValue>();
}

TuringMachine::~TuringMachine() {
  delete this->states;
  delete this->transitions;
}

/// Permette di inserire un nuovo elemento all'interno della macchina di turing.
bool TuringMachine::addNewState(int stateToInsert) {
  State<int> tempState = State<int>();
  tempState.value = stateToInsert;
  /// Se lo stato non esiste restituisce false, altrimenti true.
  if (arrayContains(states, tempState))
    return false;
  /// Solo stati positivi.
  if (tempState.value >= 0)
    states->push_back(tempState);
  return true;
}

bool TuringMachine::setInitialState(string rawString) {
  State<int> tempState = State<int>();
  /// Parserizzo e controllo la stringa in input.
  if ((tempState.value = checkInput<std::string>(rawString, 0, 100)) == -1) {
    return false;
  }
  /// Controllo la validità dello stato (deve esistere).
  if (tempState.value < 0 || !arrayContains(states, tempState))
    return false;
  else
    initialState = tempState;
  return true;
}

bool TuringMachine::setFinalState(string rawString) {
  /// Come funzione precedente.
  State<int> tempState = State<int>();
  if ((tempState.value = checkInput<std::string>(rawString, 0, 100)) == -1) {
    return false;
  }
  if (tempState.value < 0 || !arrayContains(states, tempState))
    return false;
  else
    finalState = tempState;
  return true;
}

std::vector<State<int>> *mdtModels::TuringMachine::getStates() {
  return states;
}

string mdtModels::TuringMachine::printStates() {
  string result;
  for (auto item : *states) {
    result += "[";
    result += item.value;
    result += "] ";
  }
  return result;
}

bool mdtModels::TuringMachine::insertTransition(int state, char symbol,
                                                int nextState, char nextSymbol,
                                                Movement nextMove) {
  State<int> currentState = State<int>();
  currentState.value = state;
  State<int> nextStateS = State<int>();
  nextStateS.value = state;
  /// Controllo la validità degli stati inseriti nella transizione.
  if (!arrayContains(states, currentState) || !arrayContains(states, nextStateS))
    return false;
  /// Creo una chiave della mappa.
  TransitionBase key = TransitionBase(state, symbol);
  /// Creo il valore della mappa.
  TransitionValue value = TransitionValue(nextState, nextSymbol, nextMove);
  /// Inserisco (con eventuale sovrascrittura).
  (*transitions)[key] = value;
  return true;
}

bool mdtModels::TuringMachine::checkStatusPresent(int state) {
  State<int> tempState = State<int>();
  tempState.value = state;
  return arrayContains(states, tempState);
}

std::string mdtModels::TuringMachine::printTransitions() {
  string result = "";
  for (const pair<TransitionBase, TransitionValue> &item : *transitions) {
    result += "(";
    result += to_string(item.first.state);
    result += ",";
    result += item.first.symbol;
    result += ") => (";
    result += to_string(item.second.state);
    result += ",";
    result += item.second.symbol;
    result += ",";
    result +=
        (item.second.nextMove == L ? "L"
                                   : ((item.second.nextMove == R) ? "R" : "N"));
    result += ")\n";
  }
  return result;
}

State<int> mdtModels::TuringMachine::getInitialState() { return initialState; }

State<int> mdtModels::TuringMachine::getFinalState() { return finalState; }

std::map<TransitionBase, TransitionValue> *
mdtModels::TuringMachine::getTransitions() {
  return transitions;
}
