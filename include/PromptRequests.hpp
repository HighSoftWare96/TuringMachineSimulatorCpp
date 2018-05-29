/**
 * @copyright TuringMachineSimulatorCpp license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file PromptRequests.hpp
 */
#pragma once
#include "TuringMachine.hpp"
#include "TuringMachineState.hpp"

/// Namespace che contiene tutte le definizioni statiche del progetto.
namespace promptReq {
/// Classe per l'interazione a video con l'utente
class PromptRequests {
public:
  // Funzione per mostrare a video un menu e un percorso per costruire una nuova
  // MdT interattivamente.
  static void machineMenu(mdtModels::TuringMachine &machine,
                          mdtModels::TuringMachineState &tape);
  // Funzione per mostrare a video un percorso separato per il cambio del nastro
  // della MdT.
  static void writeTape(mdtModels::TuringMachineState &tape);
};
} // namespace promptReq