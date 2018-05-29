/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file TransitionValue.hpp
 */

#pragma once
#include "TransitionBase.hpp"
#include <string>

namespace mdtModels {
/// Enum per i movimenti della testina della MdT.
/** Questa enum utilizzata in questo namespace rappresenta
i valori ammessi per i movimenti della testina ed ha associati
gli interi corrispondenti da sommare al valore della posizione attuale
della testina. */
enum class Movement { L = -1, N = 0, R = 1 };

/// Classe per rappresentare i valori di una transizione.
/** Usata nella mappa delle transizioni per ricavare il prossimo stato della
macchina, il simbolo da scrivere e il movimento da fare data una certa chiave.
*/
class TransitionValue : public TransitionBase {
public:
  /// Prossimo movimento della MdT.
  Movement nextMove;
  /// Costruttore vuoto, usato per la std::map.
  explicit TransitionValue();
  /// Costruttore che riceve tutte i dati da assegnare alle proprietà
  /// dell'oggetto stesso.
  explicit TransitionValue(int nextState, char nextSymbol,
                           const Movement &nextMove);
  /// Distruttore vuoto.
  ~TransitionValue();
  /// ritorna il movimento -- POLIMORFISMO
  const std::string getMovementRappr() const;
};
} // namespace mdtModels