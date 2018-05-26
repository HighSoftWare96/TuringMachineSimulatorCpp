/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file State.h
 */
#pragma once

namespace mdtModels {

/// Classe che rappresenta lo stato di una mdt.
template <typename T> 

class State {
public:
  explicit State();
  /// costruttore che riceve il valore dello stato.
  explicit State(T value);
  /// Distruttore vuoto.
  ~State();
  const T getState() const;
private:
  /// Stato della MdT.
  T state;
};
template <typename T> 
/// Overloading dell'operatore = utilizzato per comparare due State
bool operator==(const State<T> &one, const State<T> &that);
} // namespace mdtModels