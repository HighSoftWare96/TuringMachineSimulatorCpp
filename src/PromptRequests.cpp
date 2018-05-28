#include "../include/PromptRequests.h"
#include "../include/GpUtils.h"
#include "../include/TuringMachine.h"
#include "../include/TuringMachineState.h"
#include <iostream>
#include <string>

void promptReq::PromptRequests::machineMenu(
    mdtModels::TuringMachine &machine, mdtModels::TuringMachineState &tape) {
  // RAW input dell'utente.
  std::string input = "";
  // Input intero convertito dell'utente.
  int intInput = 0;

  std::cout << "Inserisci gli stati della MdT" << std::endl;

  // Continuo a chiedere finchè non c'è almeno un elemento negli stati o
  // inserisce stati > 0.
  while (intInput >= 0 || machine.getStates().size() == 0) {

    std::cout << "#" << machine.getStates().size() << ": ";
    std::cin >> input;

    if ((intInput = gpUtils::checkInput<const std::string &>(input, -1, 100)) ==
        -2) {
      intInput = 100;
      std::cout << "Input non valido..." << std::endl;
      continue;
    }

    // Aggiungo un nuovo stato alla Mdt. Se ritorna false lo stato non era
    // ammesso.
    if (!machine.addNewState(intInput)) {
      std::cout << "Stato gia' presente, prego inserire uno stato nuovo.\n";
      continue;
    }
  }

  // Stampo gli stati inseriti.
  std::cout << "Stati inseriti: " << machine.printStates() << std::endl;

  // Inserisce uno stato iniziale, se è false allora non è tra quelli presenti.
  do {
    std::cout << "Inserisci lo stato iniziale (che corrisponda ad uno dei "
                 "presenti): ";
    std::cin >> input;
  } while (!machine.setInitialState(input));

  // Inserisce uno stato finale, se è false allora non è tra quelli presenti.
  do {
    std::cout
        << "Inserisci lo stato finale (che corrisponda ad uno dei presenti):";
    std::cin >> input;
  } while (!machine.setFinalState(input));

  // simboli e interi da richiedere e salvarsi per inserire una transizione
  // nella MdT.
  int stateToInsert;
  char symbolToInsert;
  int stateNToInsert;
  char symbolNToInsert;
  mdtModels::Movement moveNToInsert;
  // Rappresentazione a std::stringa del movimento (enum non ben
  // rappresentabile).
  std::string moveNToInsertString;

  int counter = 0;
  std::cout << "Inserisci le transizioni della Macchina di Turing" << std::endl;

  do {
    std::cout << "== Transizione #" << counter << " ==" << std::endl;
    // Richiesta stato di riferimento.
    std::cout << "Inserisci stato: ";
    std::cin >> input;

    if ((stateToInsert =
             gpUtils::checkInput<const std::string &>(input, 0, 100)) == -1) {
      std::cout << "Input non valido..." << std::endl;
      input = "";
      continue;
    }
    //  Controllo che lo stato inserito sia tra quelli della MdT.
    if (!machine.checkStatusPresent(stateToInsert)) {
      std::cout << "Stato non presente" << std::endl;
      continue;
    }

    // Richiesta simbolo su nastro. Max 1 carattere.
    std::cout << "Inserisci simbolo: ";
    std::cin >> input;
    if (input.length() > 1) {
      input = "";
      std::cout << "Input non valido... Ammessi solo simboli da 1 carattere"
                << std::endl;
      continue;
    }

    // Prendo il char e lo inserisco.
    symbolToInsert = input.at(0);

    // Richiedo lo stato successivo.
    std::cout << "Inserisci lo stato conseguente: ";
    std::cin >> input;

    if ((stateNToInsert =
             gpUtils::checkInput<const std::string &>(input, 0, 100)) == -1) {
      input = "";
      std::cout << "Input non valido..." << std::endl;
      continue;
    }

    // Controllo sia valido.
    if (!machine.checkStatusPresent(stateNToInsert)) {
      std::cout << "Stato non presente" << std::endl;
      continue;
    }

    // Richiedo simbolo successivo.
    std::cout << "Inserisci simbolo da scrivere: ";
    std::cin >> input;
    if (input.length() > 1) {
      std::cout << "Input non valido... Ammessi solo simboli da 1 carattere."
                << std::endl;
      input = "";
      continue;
    }

    symbolNToInsert = input.at(0);

    // Richiedo il movimento della testina corrispondente
    std::cout
        << "Inserisci il movimento da fare (L/l left, R/r right, N/n none): ";
    std::cin >> input;
    // Tutto minuscolo.
    input = gpUtils::toLower(input);

    // Controllo la validità dell'input, (solo l r n o maiuscoli
    // corrispondenti).
    if (input.length() > 1 || (input != "l" && input != "n" && input != "r")) {
      std::cout << "Input non valido... Ammessi solo L/l, R/r, N/n!"
                << std::endl;
      input = "";
      continue;
    }
    // Mappo la std::stringa inserita con un corrispondente valore della enum di
    // Movement.
    else if (input == "l") {
      moveNToInsert = mdtModels::Movement::L;
      // Imposto la rappresentazione a std::stringa del movimento selezionato.
      moveNToInsertString = "L";
    } else if (input == "r") {
      moveNToInsert = mdtModels::Movement::R;
      moveNToInsertString = "R";
    } else {
      moveNToInsert = mdtModels::Movement::N;
      moveNToInsertString = "N";
    }

    // Inserisco la transizione nella MdT con tutti i dati raccolti finora.
    machine.insertTransition(stateToInsert, symbolToInsert, stateNToInsert,
                             symbolNToInsert, moveNToInsert);

    // Restituisco una rappresentazione a schermo della transizione appena
    // creata e inserita.
    std::cout << "Transazione (" << stateToInsert << "," << symbolToInsert
              << ")";
    std::cout << "=> (" << stateNToInsert << "," << symbolNToInsert << ","
              << moveNToInsertString << ")" << std::endl;

    // Chiedo conferma per l'inserimento di un nuovo simbolo.
    std::cout << "Continuare? (s/n): ";
    std::cin >> input;

    // Tutto minuscolo per evitare problemi col case.
    input = gpUtils::toLower(input);
    counter++;

  } while (input != "n" && input != "no");

  // Richiedo di inserire il nastro.
  writeTape(tape);

  // Stampo un riepilogo per visualizzare la MdT appena creata.
  std::cout << "MdT costruita, riepilogo:\n";
  std::cout << "STATI: " << machine.printStates() << std::endl;
  std::cout << "STATO INIZIALE: "
            << std::to_string(machine.getInitialState().getState())
            << std::endl;
  std::cout << "STATO FINALE: "
            << std::to_string(machine.getFinalState().getState()) << std::endl;
  std::string transitionRappr = machine.printTransitions();
  std::cout << "TRANSIZIONI:\n" << transitionRappr;
  std::cout << "NASTRO: " << tape.printTape() << std::endl;
}

void promptReq::PromptRequests::writeTape(mdtModels::TuringMachineState &tape) {

  // Svuoto il nastro (anche se non dovrebbe servire).
  tape.flush();

  std::string input = "";
  int counter = 0;

  std::cout << "Inserisci i simboli del nastro iniziale: (-1 per terminare)"
            << std::endl;

  // Finchè non mette il simbolo di uscita -1 o il nastro non è vuoto..
  do {
    std::cout << "#" << counter << ": ";
    std::cin >> input;
    // Richiedo il simbolo da inserire nel nastro e verifico la validità-
    if (input.length() > 1 && input != "-1") {
      std::cout << "Input non valido... Ammessi solo simboli da 1 carattere"
                << std::endl;
      continue;
    }

    // Se non è il simbolo di uscita.
    if (input != "-1")
      // Aggiungo al nastro.
      tape.addSymbol(counter++, input.at(0));

  } while (input != "-1" || tape.getTapeSize() == 0);
}
