/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file main.cpp
 */
/*! \mainpage Turing machine simulator.
 * Project presented for the C++ Course in the University of Verona. This
 * project deals with the building of a Turing Machine simulator. It allows to
 * create a machine within a Terminal interface and to run in on different
 * symbols sequences (different tapes).
 *
 */

#include "../include/GpUtils.hpp"
#include "../include/PromptRequests.hpp"
#include "../include/TuringMachine.hpp"
#include "../include/TuringMachineState.hpp"
#include <iostream>
#include <string>

// Main del programma: entry point.
int main() {
  int choice = 0;
  std::cout << "== SIMULATORE MACCHINE DI TURING == " << std::endl;

  // MdT principale del programma.
  mdtModels::TuringMachine machine;
  // MdTState principale del programma.
  mdtModels::TuringMachineState tape = mdtModels::TuringMachineState(&machine);

  // Menu.
  while (choice != 4) {

    std::string rawChoice;

    // Menu e richiesta delle opzioni da scegliere.
    std::cout
        << "\nOpzioni disponibili: " << std::endl
        << "  1) Nuova macchina di Turing\n  2) Esegui macchina di Turing\n  "
           "3) Cambia nastro\n  4) Esci\n:> ";
    std::cin >> rawChoice;

    // Input scorretti (non nel range e non numeri) generano minRange - 1.
    if ((choice = gpUtils::checkInput<const std::string &>(rawChoice, 1, 4)) ==
        0) {
      choice = 0;
      std::cout << "Input scorretto!\n";
      // Continue.
    }

    switch (choice) {
    case 1:
      // Eliminazione oggetti riferiti.
      // Reinizializzo tutto sia mdt che nastro.
      machine = mdtModels::TuringMachine();
      tape = mdtModels::TuringMachineState(&machine);
      // Menu di costruzione di una nuova MdT.
      promptReq::PromptRequests::machineMenu(machine, tape);
      break;
    case 2:
      // Se non è ancora stata creata una delle due allora avviso l'utente che
      // non può eseguire la MdT.
      if (machine.getStates().size() == 0 || tape.getTapeSize() == 0)
        std::cout << "Prima di eseguire una MdT e' necessario crearla!"
                  << std::endl;
      else
        // Altrimenti la eseguo.
        tape.execute();
      break;
    case 3:
      // Reinizializzo il nastro.
      tape = mdtModels::TuringMachineState(&machine);
      // Menu cambio nastro.
      promptReq::PromptRequests::writeTape(tape);
      break;
    default:
      break;
    }
  }
  return 0;
}
