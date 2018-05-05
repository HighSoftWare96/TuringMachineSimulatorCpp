/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file main.cpp
 */

#include "../include/GpUtils.h"
#include "../include/TuringMachine.h"
#include "../include/TuringMachineState.h"
#include <iostream>
#include <string>

using namespace std;
using namespace gpUtils;
using namespace mdtModels;

/*! \mainpage Turing machine simulator.
 * Project presented for the C++ Course in the University of Verona. This
 * project deals with the building of a Turing Machine simulator. It allows to
 * create a machine within a Terminal interface and to run in on different
 * symbols sequences (different tapes).
 *
 */

/// Funzione per mostrare a video un menu e un percorso per costruire una nuova
/// MdT interattivamente.
void machineMenu(TuringMachine& machine, TuringMachineState& tape);
/// Funzione per mostrare a video un percorso separato per il cambio del nastro
/// della MdT.
void writeTape(TuringMachineState& tape);

/// Main del programma: entry point.
int main() {
  int choice = 0;
  cout << "== SIMULATORE MACCHINE DI TURING == " << endl;

  /// MdT principale del programma.
  TuringMachine *machine = nullptr;
  /// MdTState principale del programma.
  TuringMachineState *tape = nullptr;

  /// Menu.
  while (choice != 4) {

    string rawChoice;

    /// Menu e richiesta delle opzioni da scegliere.
    cout << "\nOpzioni disponibili: " << endl
         << "  1) Nuova macchina di Turing\n  2) Esegui macchina di Turing\n  "
            "3) Cambia nastro\n  4) Esci\n:> ";
    cin >> rawChoice;

    /// Input scorretti (non nel range e non numeri) generano minRange - 1.
    if ((choice = checkInput<string>(rawChoice, 1, 4)) == 0) {
      choice = 0;
      cout << "Input scorretto!\n";
      /// Continue.
    }

    switch (choice) {
    case 1:
      /// Eliminazione oggetti riferiti.
      delete machine;
      delete tape;
      /// Reinizializzo tutto sia mdt che nastro.
      machine = new TuringMachine();
      tape = new TuringMachineState(machine);
      /// Menu di costruzione di una nuova MdT.
      machineMenu(*machine, *tape);
      break;
    case 2:
      /// Se non è ancora stata creata una delle due allora avviso l'utente che
      /// non può eseguire la MdT.
      if (machine == nullptr || tape == nullptr)
        cout << "Prima di eseguire una MdT e' necessario crearla!" << endl;
      else
        /// Altrimenti la eseguo.
        tape->execute();
      break;
    case 3:
      /// Reinizializzo il nastro.
      delete tape;
      tape = new TuringMachineState(machine);
      /// Menu cambio nastro.
      writeTape(*tape);
      break;
    default:
      break;
    }
  }
  /// Freeing memory.
  delete machine;
  delete tape;
  return 0;
}

void machineMenu(TuringMachine& machine, TuringMachineState& tape) {
  /// RAW input dell'utente.
  string input = "";
  /// Input intero convertito dell'utente.
  int intInput = 0;

  cout << "Inserisci gli stati della MdT (solo stati positivi, -1 per finire)"
       << endl;

  /// Continuo a chiedere finchè non c'è almeno un elemento negli stati o
  /// inserisce stati > 0.
  while (intInput >= 0 || machine.getStates()->size() == 0) {

    cout << "#" << machine.getStates()->size() << ": ";
    cin >> input;

    if ((intInput = checkInput<string>(input, -1, 100)) == -2) {
      intInput = 100;
      cout << "Input non valido..." << endl;
      continue;
    }

    /// Aggiungo un nuovo stato alla Mdt. Se ritorna false lo stato non era
    /// ammesso.
    if (!machine.addNewState(intInput)) {
      cout << "Stato gia' presente, prego inserire uno stato nuovo.\n";
      continue;
    }
  }

  /// Stampo gli stati inseriti.
  cout << "Stati inseriti: " << machine.printStates() << endl;

  /// Inserisce uno stato iniziale, se è false allora non è tra quelli presenti.
  do {
    cout << "Inserisci lo stato iniziale (che corrisponda ad uno dei "
            "presenti): ";
    cin >> input;
  } while (!machine.setInitialState(input));

  /// Inserisce uno stato finale, se è false allora non è tra quelli presenti.
  do {
    cout << "Inserisci lo stato finale (che corrisponda ad uno dei presenti): ";
    cin >> input;
  } while (!machine.setFinalState(input));

  /// simboli e interi da richiedere e salvarsi per inserire una transizione
  /// nella MdT.
  int stateToInsert;
  char symbolToInsert;
  int stateNToInsert;
  char symbolNToInsert;
  Movement moveNToInsert;
  /// Rappresentazione a stringa del movimento (enum non ben rappresentabile).
  string moveNToInsertString;

  int counter = 0;
  cout << "Inserisci le transizioni della Macchina di Turing" << endl;

  do {
    cout << "== Transizione #" << counter << " ==" << endl;
    /// Richiesta stato di riferimento.
    cout << "Inserisci stato: ";
    cin >> input;

    if ((stateToInsert = checkInput<string>(input, 0, 100)) == -1) {
      cout << "Input non valido..." << endl;
      input = "";
      continue;
    }
    ///  Controllo che lo stato inserito sia tra quelli della MdT.
    if (!machine.checkStatusPresent(stateToInsert)) {
      cout << "Stato non presente" << endl;
      continue;
    }

    /// Richiesta simbolo su nastro. Max 1 carattere.
    cout << "Inserisci simbolo: ";
    cin >> input;
    if (input.length() > 1) {
      input = "";
      cout << "Input non valido... Ammessi solo simboli da 1 carattere" << endl;
      continue;
    }

    /// Prendo il char e lo inserisco.
    symbolToInsert = input.at(0);

    /// Richiedo lo stato successivo.
    cout << "Inserisci lo stato conseguente: ";
    cin >> input;

    if ((stateNToInsert = checkInput<string>(input, 0, 100)) == -1) {
      input = "";
      cout << "Input non valido..." << endl;
      continue;
    }

    /// Controllo sia valido.
    if (!machine.checkStatusPresent(stateNToInsert)) {
      cout << "Stato non presente" << endl;
      continue;
    }

    /// Richiedo simbolo successivo.
    cout << "Inserisci simbolo da scrivere: ";
    cin >> input;
    if (input.length() > 1) {
      cout << "Input non valido... Ammessi solo simboli da 1 carattere."
           << endl;
      input = "";
      continue;
    }

    symbolNToInsert = input.at(0);

    /// Richiedo il movimento della testina corrispondente
    cout << "Inserisci il movimento da fare (L/l left, R/r right, N/n none): ";
    cin >> input;
    /// Tutto minuscolo.
    input = toLower(input);

    /// Controllo la validità dell'input, (solo l r n o maiuscoli
    /// corrispondenti).
    if (input.length() > 1 || (input != "l" && input != "n" && input != "r")) {
      cout << "Input non valido... Ammessi solo L/l, R/r, N/n!" << endl;
      input = "";
      continue;
    }
    /// Mappo la stringa inserita con un corrispondente valore della enum di
    /// Movement.
    else if (input == "l") {
      moveNToInsert = L;
      /// Imposto la rappresentazione a stringa del movimento selezionato.
      moveNToInsertString = "L";
    } else if (input == "r") {
      moveNToInsert = R;
      moveNToInsertString = "R";
    } else {
      moveNToInsert = N;
      moveNToInsertString = "N";
    }

    /// Inserisco la transizione nella MdT con tutti i dati raccolti finora.
    machine.insertTransition(stateToInsert, symbolToInsert, stateNToInsert,
                              symbolNToInsert, moveNToInsert);

    /// Restituisco una rappresentazione a schermo della transizione appena
    /// creata e inserita.
    cout << "Transazione (" << stateToInsert << "," << symbolToInsert << ")";
    cout << "=> (" << stateNToInsert << "," << symbolNToInsert << ","
         << moveNToInsertString << ")" << endl;

    /// Chiedo conferma per l'inserimento di un nuovo simbolo.
    cout << "Continuare? (s/n): ";
    cin >> input;

    /// Tutto minuscolo per evitare problemi col case.
    input = toLower(input);
    counter++;

  } while (input != "n" && input != "no");

  /// Richiedo di inserire il nastro.
  writeTape(tape);

  /// Stampo un riepilogo per visualizzare la MdT appena creata.
  cout << "MdT costruita, riepilogo:\n";
  cout << "STATI: " << machine.printStates() << endl;
  cout << "STATO INIZIALE: " << to_string(machine.getInitialState()) << endl;
  cout << "STATO FINALE: " << to_string(machine.getFinalState()) << endl;
  cout << "TRANSIZIONI:\n" << machine.printTransitions();
  cout << "NASTRO: " << tape.printTape() << endl;
}

void writeTape(TuringMachineState& tape) {

  /// Svuoto il nastro (anche se non dovrebbe servire).
  tape.flush();

  string input = "";
  int counter = 0;

  cout << "Inserisci i simboli del nastro iniziale: (-1 per terminare)" << endl;

  /// Finchè non mette il simbolo di uscita -1 o il nastro non è vuoto..
  do {
    cout << "#" << counter << ": ";
    cin >> input;
    /// Richiedo il simbolo da inserire nel nastro e verifico la validità-
    if (input.length() > 1 && input != "-1") {
      cout << "Input non valido... Ammessi solo simboli da 1 carattere" << endl;
      continue;
    }

    /// Se non è il simbolo di uscita.
    if (input != "-1")
      /// Aggiungo al nastro.
      tape.addSymbol(counter++, input.at(0));

  } while (input != "-1" || tape.getTapeSize() == 0);
}
