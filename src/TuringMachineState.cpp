/**
* @copyright TuringMachineSimulatorCpp
* license Apache
* @author Bertoncelli Giovanni
* @version v1.0.1
* @date May, 2018
* @file TuringMachineState.cpp
*/

#include "../include/TuringMachine.h"
#include "../include/GpUtils.h"
#include "../include/TransitionKey.h"
#include "../include/TransitionValue.h"
#include "../include/TuringMachineState.h"
#include <iostream>
#include <string>
#include <map>

using namespace mdtModels;
using namespace std;
using namespace gpUtils;

mdtModels::TuringMachineState::TuringMachineState(TuringMachine *machine)
{
	this->machine = machine;
}


mdtModels::TuringMachineState::~TuringMachineState()
{
}

std::string mdtModels::TuringMachineState::printTape()
{
	string result = u8"";
	for (const pair<int, char>& item : machineTape) {
		result += item.second;
		result += " ";
	}
	return result;
}

/// CORE: Esecuzione della MdT.
void mdtModels::TuringMachineState::execute()
{
	cout << "## Esecuzione della Mdt creata ##\n" << "/La MdT viene eseguita partendo da SX verso DX (quindi dalla posizione 0)/" << endl;
	
	/// Imposto la posizione a 0.
	position = 0;
	/// Imposto lo stato corrente come quello iniziale.
	currentState = machine->getInitialState();
	/// Puntatore per recuperare la transizione corrente.
	TransitionValue const *currentTransition;
	
	/// Booleano per verificare se la MdT termina o no in quel ciclo.
	bool mdtContinues = true;

	while (mdtContinues) {

		/// controllo posizione su nastro
		if (machineTape.find(position) == machineTape.end()) {
			/// Se la posizione not found => metto il simbolo vuoto.
			machineTape[position] = '$'; /// TODO: verificare
		}

		/// Tento di recuperare la transizione corrente.
		currentTransition = getTransition(currentState, machineTape[position]);
		/// Verifico se la macchina termina o no (esiste la transizione).
		mdtContinues = currentTransition != nullptr;

		/// Se la transizione esiste allora la eseguo.
		if (mdtContinues) {
			/// Restituisco la rappresentazione della transizione effettuata.
			cout << getMachineStatus(currentTransition);
			/// Imposto il carattere da inserire.
			machineTape[position] = currentTransition->nextSymbol;
			/// Imposto il prossimo stato
			currentState = currentTransition->nextState;
			/// Procedo con il movimento della testina aggiornando la sua posizione.
			position += currentTransition->nextMove;
		}
	};

	/// Riepilogo della esecuzione della MdT.
	cout << "Esecuzione conclusa" << endl;
	cout << "Nastro finale: " << printTape() << endl;
	cout << "Stato n." << currentState << ", " << ((currentState == machine->getFinalState() ) ? " " : " non ") << "finale";
}

void mdtModels::TuringMachineState::addSymbol(int position, char symbol)
{
	/// Inserisco il simbolo nella mappa con quella posizione e quel char.
	this->machineTape.insert(std::pair<int, char>(position, symbol));
}

void mdtModels::TuringMachineState::flush()
{
	/// Ripulisco la map del tape.
	this->machineTape.clear();
}

size_t mdtModels::TuringMachineState::getTapeSize()
{
	/// Ritorno la grandezza del nastro.
	return machineTape.size();
}

TransitionValue  const * mdtModels::TuringMachineState::getTransition(int currentState, char currentSymbol) {
	/// Puntatore alle transizioni della MdT.
	auto *transitions = machine->getTransitions();
	/// itero per tutta la mappa tramite il puntatore/iterator alla mappa stessa, se trovo la transizione restituisco il suo puntatore
	for (std::map<TransitionKey, TransitionValue>::iterator it = transitions->begin(); it != transitions->end(); it++) {
		/// trovo una transizione con l'asterisco e quello stato oppure quello stato e quel simbolo
		if (it->first.currentState == currentState && (it->first.currentSymbol == currentSymbol || it->first.currentSymbol == '*'))
			return &it->second;
	}
	return nullptr;
}

std::string mdtModels::TuringMachineState::getMachineStatus(TransitionValue const* currentTransition)
{
	/// Restituisco una rappresentazione della transizione effettuata dalla MdT.
	string result = "";
	result.append("####################################################\nPOSIZIONE sul nastro: ");
	result += to_string(position);
	result.append("\nSTATO CORRENTE: ");
	result += to_string(currentState);
	result.append(" | SIMBOLO su nastro: ");
	result += machineTape[position];
	result.append("\nPROSSIMO STATO: ");
	result += to_string(currentTransition->nextState);
	result.append(" | PROSSIMO SIMBOLO: ");
	result += currentTransition->nextSymbol;
	result.append(" | MOVIMENTO: ");
	result += (currentTransition->nextMove == L ? "L" : ((currentTransition->nextMove == R) ? "R" : "N"));
	result.append("\nNASTRO: ");
	result += printTape();
	result += "\n";
	return result;
}
