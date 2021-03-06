/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file TransitionBase.hpp
 */
#pragma once
#include "../include/State.hpp"
#include <string>

namespace mdtModels {
/// Classe che rappresenta la chiave di una transizione.
/** La classe è composta da due proprietà pubbliche: lo stato e il simbolo che
   rappresentano lo stato corrente e il simbolo sulla posizione corrente del
   nastro con cui cercare poi una transizione corrispondente. */
class TransitionBase {
public:
  /// Stato corrente della MdT.
  State<int> state;
  /// Simbolo corrente della MdT.
  char symbol;
  /// Costruttore vuoto
  explicit TransitionBase();
  /// Costruttore della chiave: imposta lo stato e il simbolo della chiave.
  explicit TransitionBase(int currentState, char currentSymbol);
  /// Distruttore vuoto.
  ~TransitionBase();
  /// ritorna il movimento - POLIMORFISMO
  virtual const std::string getMovementRappr();
};
/// Overriding dell'operatore < utilizzato per implementare questa classe come
/// chiave di una mappa.
/** Necessario a std::map per costruire l'albero di rappresentazione della
mappa: ha bisogno di sapere in che ordine porre gli elementi all'internod della
struttura dati.*/
bool operator<(const TransitionBase &one, const TransitionBase &that);
} // namespace mdtModels