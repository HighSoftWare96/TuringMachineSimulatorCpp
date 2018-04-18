#include <iostream>
#include <string>
#include "GpUtils.h"
#include "TuringMachine.h"
#include "TuringMachineState.h"
using namespace std;
using namespace gpUtils;
using namespace mdtModels;

void machineMenu(TuringMachine *machine, TuringMachineState *tape);
void writeTape(TuringMachineState *tape);


int main() {
	int choice = 0;
	cout << "== SIMULATORE MACCHINE DI TURING == " << endl;

	TuringMachine *machine = nullptr;
	TuringMachineState *tape = nullptr;


	while (choice != 4) {

		string rawChoice;

		cout << "\nOpzioni disponibili: " << endl << "  1) Nuova macchina di Turing\n  2) Esegui macchina di Turing\n  3) Cambia nastro\n  4) Esci\n:> ";
		cin >> rawChoice;

		try {
			choice = checkInput(rawChoice, 1, 4);
		}
		catch (...) {
			choice = 0;
			cout << "Input scorretto!\n";
		}
		switch (choice)
		{
		case 1:
			delete machine, tape;
			/// reinizializzo tutto sia mdt che nastro
			machine = new TuringMachine();
			tape = new TuringMachineState(machine);
			machineMenu(machine, tape);
			break;
		case 2:
			if (machine == nullptr || tape == nullptr)
				cout << "Prima di eseguire una MdT e' necessario crearla!" << endl;
			else
				tape->execute();
			break;
		case 3:
			delete tape;
			tape = new TuringMachineState(machine);
			writeTape(tape);
			break;
		default:
			break;
		}
	}
	delete machine;
	delete tape;
	return 0;
}


void machineMenu(TuringMachine *machine, TuringMachineState *tape) {

	string input = "";
	int intInput = 0;

	cout << "Inserisci gli stati della MdT (solo stati positivi, -1 per finire)" << endl;

	while (intInput >= 0 || machine->getStates().size() == 0) {

		cout << "#" << machine->getStates().size() << ": ";
		cin >> input;

		try {
			intInput = checkInput(input, -100, 100);
		}
		catch (...) {
			cout << "Input non valido..." << endl;
			continue;
		}

		if (!machine->addNewState(intInput)) {
			cout << "Stato gia' presente, prego inserire uno stato nuovo.\n";
			continue;
		}
	}

	cout << "Stati inseriti: " << machine->printStates() << endl;

	do {
		cout << "Inserisci lo stato iniziale (che corrisponda ad uno dei presenti): ";
		cin >> input;
	} while (!machine->setInitialState(input));

	do {
		cout << "Inserisci lo stato finale (che corrisponda ad uno dei presenti): ";
		cin >> input;
	} while (!machine->setFinalState(input));

	int stateToInsert;
	char symbolToInsert;
	int stateNToInsert;
	char symbolNToInsert;
	Movement moveNToInsert;
	string moveNToInsertString;

	int counter = 0;
	cout << "Inserisci le transizioni della Macchina di Turing" << endl;

	do {
		cout << "== Transizione #" << counter << " ==" << endl;
		cout << "Inserisci stato: ";
		cin >> input;
		try {
			stateToInsert = checkInput(input, 0, 100);
		}
		catch (...) {
			cout << "Input non valido..." << endl;
			continue;
		}

		if (!machine->checkStatusPresent(stateToInsert)) {
			cout << "Stato non presente" << endl;
			continue;
		}

		cout << "Inserisci simbolo: ";
		cin >> input;
		if (input.length() > 1) {
			cout << "Input non valido... Ammessi solo simboli da 1 carattere" << endl;
			continue;
		}
		
		symbolToInsert = input.at(0);

		cout << "Inserisci lo stato conseguente: ";
		cin >> input;
		try {
			stateNToInsert = checkInput(input, 0, 100);
		}
		catch (...) {
			cout << "Input non valido..." << endl;
			continue;
		}

		if (!machine->checkStatusPresent(stateNToInsert)) {
			cout << "Stato non presente" << endl;
			continue;
		}

		cout << "Inserisci simbolo da scrivere: ";
		cin >> input;
		if (input.length() > 1) {
			cout << "Input non valido... Ammessi solo simboli da 1 carattere." << endl;
			continue;
		}

		symbolNToInsert = input.at(0);

		cout << "Inserisci il movimento da fare (L/l left, R/r right, N/n none): ";
		cin >> input;
		input = toLower(input);

		if (input.length() > 1 || (input != "l" && input != "n" && input != "r")) {
			cout << "Input non valido... Ammessi solo L/l, R/r, N/n!" << endl;
			continue;
		}
		else if (input == "l")
		{
			moveNToInsert = L;
			moveNToInsertString = "L";
		}
		else if (input == "r")
		{
			moveNToInsert = R;
			moveNToInsertString = "R";
		}
		else {
			moveNToInsert = N;
			moveNToInsertString = "N";
		}

		machine->insertTransition(stateToInsert, symbolToInsert, stateNToInsert, symbolNToInsert, moveNToInsert);

		cout << "Transazione (" << stateToInsert << "," << symbolToInsert << ")";
		cout << "=> (" << stateNToInsert << "," << symbolNToInsert << "," << moveNToInsertString << ")" << endl;

		cout << "Continuare? (s/n): ";
		cin >> input;

		input = toLower(input);
		counter++;

	} while (input != "n" && input != "no");

	writeTape(tape);

	cout << "MdT costruita, riepilogo:\n";
	cout << "STATI: " << machine->printStates() << endl;
	cout << "STATO INIZIALE: " << to_string(machine->getInitialState()) << endl;
	cout << "STATO FINALE: " << to_string(machine->getFinalState()) << endl;
	cout << "TRANSIZIONI:\n" << machine->printTransitions();
	cout << "NASTRO: " << tape->printTape() << endl;

}

void writeTape(TuringMachineState *tape) {
	tape->flush();

	string input = "";
	int counter = 0;
	
	cout << "Inserisci i simboli del nastro iniziale: (-1 per terminare)" << endl;

	do {
		cout << "#" << counter << ": ";
		cin >> input;
		if (input.length() > 1 && input != "-1") {
			cout << "Input non valido... Ammessi solo simboli da 1 carattere" << endl;
			continue;
		}

		if (input != "-1")
			/// aggiungo al nastro
			tape->addSymbol(counter++, input.at(0));

	} while (input != "-1" || tape->getTapeSize() == 0);
}