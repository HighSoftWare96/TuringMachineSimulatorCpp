/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file TuringMachineState.cpp
 */

#include "../include/TuringMachineState.h"
#include "../include/GpUtils.h"
#include "../include/TransitionBase.h"
#include "../include/TransitionValue.h"
#include "../include/TuringMachine.h"
#include <iostream>
#include <map>
#include <string>

mdtModels::TuringMachineState::TuringMachineState(
    mdtModels::TuringMachine *machine) {
  _machine = machine;
  _machineTape = std::map<int, char>();
}

mdtModels::TuringMachineState::~TuringMachineState() {}

std::string mdtModels::TuringMachineState::printTape() {
  std::string result = "";
  for (const std::pair<int, char> &item : _machineTape) {
    result += item.second;
    result += " ";
  }
  return result;
}

// CORE: Esecuzione della MdT.
void mdtModels::TuringMachineState::execute() {
  std::cout << "## Esecuzione della Mdt creata ##\n"
            << "/La MdT viene eseguita partendo da SX verso DX (quindi dalla "
               "posizione 0)/"
            << endl;

  // Imposto la posizione a 0.
  _position = 0;
  // Imposto lo stato corrente come quello iniziale.
  _currentState = _machine->getInitialState();
  // Puntatore per recuperare la transizione corrente.
  mdtModels::TransitionValue const *currentTransition;

  // Booleano per verificare se la MdT termina o no in quel ciclo.
  bool mdtContinues = true;

  while (mdtContinues) {

    // controllo posizione su nastro
    if (_machineTape.find(_position) == _machineTape.end()) {
      // Se la posizione not found => metto il simbolo vuoto.
      _machineTape[_position] = '$';
    }

    // Tento di recuperare la transizione corrente.
    currentTransition = getTransition(_currentState, _machineTape[_position]);
    // Verifico se la macchina termina o no (esiste la transizione).
    mdtContinues = (currentTransition != nullptr);

    // Se la transizione esiste allora la eseguo.
    if (mdtContinues) {

      // Restituisco una rappresentazione della transizione effettuata dalla
      // MdT.
      string result = "";
      result.append("####################################################\
	\nPOSIZIONE sul nastro: ");
      result += to_string(_position);
      result.append("\nSTATO CORRENTE: ");
      result += to_string(_currentState.getState());
      result.append(" | SIMBOLO su nastro: ");
      result += (_machineTape)[_position];
      result.append("\nPROSSIMO STATO: ");
      result += to_string(currentTransition->state.getState());
      result.append(" | PROSSIMO SIMBOLO: ");
      result += currentTransition->symbol;
      result.append(" | MOVIMENTO: ");
      switch (currentTransition->nextMove) {
      case mdtModels::Movement::L:
        result.append("L");
        break;
      case mdtModels::Movement::R:
        result.append("R");
        break;
      case mdtModels::Movement::N:
        result.append("N");
        break;
      }
      result.append("\nNASTRO: ");
      result += printTape();
      result += "\n";
      cout << result;

      _machineTape[this->_position] = currentTransition->symbol;

      // Imposto il prossimo stato
      _currentState = currentTransition->state;
      // Procedo con il movimento della testina aggiornando la sua posizione.
      this->_position = this->_position + int(currentTransition->nextMove);
    }
  };

  // Riepilogo della esecuzione della MdT.
  std::cout << "Esecuzione conclusa" << endl;
  std::cout << "Nastro finale: " << printTape() << endl;
  std::cout << "Stato n." << std::to_string(_currentState.getState()) << ", "
            << ((_currentState == _machine->getFinalState()) ? " " : " non ")
            << "finale";
}

void mdtModels::TuringMachineState::addSymbol(int position, char symbol) {
  // Inserisco il simbolo nella mappa con quella posizione e quel char.
  _machineTape.insert(std::pair<int, char>(position, symbol));
}

void mdtModels::TuringMachineState::flush() {
  // Ripulisco la map del tape.
  _machineTape.clear();
}

size_t mdtModels::TuringMachineState::getTapeSize() {
  // Ritorno la grandezza del nastro.
  return _machineTape.size();
}

mdtModels::TransitionValue const *
mdtModels::TuringMachineState::getTransition(State<int> currentState,
                                             char currentSymbol) {
  // Puntatore alle transizioni della MdT.
  auto transitions = _machine->getTransitions();
  // itero per tutta la mappa tramite il puntatore/iterator alla mappa
  // stessa, se trovo la transizione restituisco il suo puntatore
  for (std::map<TransitionBase, TransitionValue>::iterator it =
           transitions.begin();
       it != transitions.end(); it++) {
    // trovo una transizione con l'asterisco e quello stato oppure quello
    // stato e quel simbolo
    if (it->first.state == currentState &&
        (it->first.symbol == currentSymbol || it->first.symbol == '*'))
      return &it->second;
  }
  return nullptr;
}
