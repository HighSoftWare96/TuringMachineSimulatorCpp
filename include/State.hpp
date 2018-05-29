/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file State.hpp
 */
#pragma once

namespace mdtModels {

/// Classe che rappresenta lo stato di una mdt.
template <typename T> class State {
public:
  /// costruttore vuoto
  explicit State();
  /// costruttore che riceve il valore dello stato.
  explicit State(T value);
  /// Distruttore vuoto.
  ~State();
  /// metodo per la restituzione dello stato che viene rappresentato
  const T getState() const;

private:
  /// Stato della MdT.
  T state;
};
/// Overloading dell'operatore = utilizzato per comparare due State
template <typename T>
bool operator==(const State<T> &one, const State<T> &that);
} // namespace mdtModels