/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file TuringMachineState.hpp
 */

#pragma once
#include "State.hpp"
#include "TransitionBase.hpp"
#include "TransitionValue.hpp"
#include "TuringMachine.hpp"
#include <iostream>
#include <map>
#include <string>

namespace mdtModels {
/// Classe che permette di rappresentare lo stato di una mdt su un certo nastro.
/** Contiene il nastro e una serie di metodi per simulare una mdt sul nastro. */
class TuringMachineState {
public:
  /// Costruttore che riceve una mdt come parametro per eseguirla sul nastro.
  explicit TuringMachineState(TuringMachine *machine);
  /// Distruttore vuoto: non voglio che quando si distrugga questo oggetto venga
  /// distrutta anche la mdt di riferimento.
  ~TuringMachineState();
  /// Rappresenta a string il nastro.
  std::string printTape();
  /// Metodo per l'esecuzione della mdt sul nastro.
  void execute();
  /// Metodo per l'aggiunta di un simbolo al nastro su una certa posizione
  /// position.
  void addSymbol(int position, char symbol);
  /// Metodo per la pulizia completa del nastro.
  void flush();
  /// Metodo per verificare la grandezza del nastro (per evitare i nastri vuoti
  /// nel main).
  size_t getTapeSize();

private:
  /// Macchina di Turing che verrà eseguita.
  TuringMachine *_machine;
  /// Posizione corrente della testina.
  int _position;
  /// Stato corrente della MdT.
  State<int> _currentState;
  /// Nastro della MdT.
  /** Il nastro è rappresentato nella classe come una mappa intero-carattere in
  cui l'intero rappresenta la posizione mentre
  il carattere il simbolo su quella posizione. */
  std::map<int, char> _machineTape;
  /// Metodo privato per verificare la presenza di una transizione data la sua
  /// chiave statocorrente-simbolocorrente
  /** Verifica che non siano presenti anche transizioni con l'asterisco:
   * restituisce un puntatore alla transizione oppure nullptr se non esiste. */
  const TransitionValue *getTransition(State<int> currentState,
                                       char currentSymbol);
  /// Restituisce una rappresentazione di una transizione effettuata dello stato
  /// attuale della MdT.
  const std::string getMachineStatus(const TransitionValue &currentTransition);
};

} // namespace mdtModels
