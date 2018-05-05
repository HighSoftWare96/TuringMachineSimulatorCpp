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
#include "../include/TransitionKey.h"
#include "../include/TransitionValue.h"
#include "../include/TuringMachineState.h"
#include <iostream>
#include <string>

using namespace mdtModels;
using namespace std;
using namespace gpUtils;

TuringMachine::TuringMachine() {
  this->states = new vector<int>();
  this->transitions = new map<TransitionKey, TransitionValue>();
}

TuringMachine::~TuringMachine() {
  delete this->states;
  delete this->transitions;
}

/// Permette di inserire un nuovo elemento all'interno della macchina di turing.
bool TuringMachine::addNewState(int stateToInsert) {
  /// Se lo stato non esiste restituisce false, altrimenti true.
  if (arrayContains(states, stateToInsert))
    return false;
  /// Solo stati positivi.
  if (stateToInsert >= 0)
    states->push_back(stateToInsert);
  return true;
}

bool TuringMachine::setInitialState(string rawString) {
  int initialStateToInsert;
  /// Parserizzo e controllo la stringa in input.
  if ((initialStateToInsert = checkInput<std::string>(rawString, 0, 100)) ==
      -1) {
    return false;
  }
  /// Controllo la validità dello stato (deve esistere).
  if (initialStateToInsert < 0 || !arrayContains(states, initialStateToInsert))
    return false;
  else
    initialState = initialStateToInsert;
  return true;
}

bool TuringMachine::setFinalState(string rawString) {
  /// Come funzione precedente.
  int finalStateToInsert;
  if ((finalStateToInsert = checkInput<std::string>(rawString, 0, 100)) == -1) {
    return false;
  }
  if (finalStateToInsert < 0 || !arrayContains(states, finalStateToInsert))
    return false;
  else
    finalState = finalStateToInsert;
  return true;
}

std::vector<int> *mdtModels::TuringMachine::getStates() { return states; }

string mdtModels::TuringMachine::printStates() {
  string result;
  for (int item : *states) {
    result += "[";
    result += to_string(item);
    result += "] ";
  }
  return result;
}

bool mdtModels::TuringMachine::insertTransition(int state, char symbol,
                                                int nextState, char nextSymbol,
                                                Movement nextMove) {
  /// Controllo la validità degli stati inseriti nella transizione.
  if (!arrayContains(states, state) || !arrayContains(states, nextState))
    return false;
  /// Creo una chiave della mappa.
  TransitionKey key = TransitionKey(state, symbol);
  /// Creo il valore della mappa.
  TransitionValue value = TransitionValue(nextState, nextSymbol, nextMove);
  /// Inserisco (con eventuale sovrascrittura).
  (*transitions)[key] = value;
  return true;
}

bool mdtModels::TuringMachine::checkStatusPresent(int state) {
  return arrayContains(states, state);
}

std::string mdtModels::TuringMachine::printTransitions() {
  string result = "";
  for (const pair<TransitionKey, TransitionValue> &item : *transitions) {
    result += "(";
    result += to_string(item.first.currentState);
    result += ",";
    result += item.first.currentSymbol;
    result += ") => (";
    result += to_string(item.second.nextState);
    result += ",";
    result += item.second.nextSymbol;
    result += ",";
    result +=
        (item.second.nextMove == L ? "L"
                                   : ((item.second.nextMove == R) ? "R" : "N"));
    result += ")\n";
  }
  return result;
}

int mdtModels::TuringMachine::getInitialState() { return initialState; }

int mdtModels::TuringMachine::getFinalState() { return finalState; }

std::map<TransitionKey, TransitionValue> *
mdtModels::TuringMachine::getTransitions() {
  return transitions;
}
