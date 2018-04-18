#include "TuringMachine.h"
#include "GpUtils.h"
#include <iostream>
#include <string>
#include <map>
#include "TransitionKey.h"
#include "TransitionValue.h"
#include "TuringMachineState.h"
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

void mdtModels::TuringMachineState::execute()
{
	cout << "## Esecuzione della Mdt creata ##\n" << "/La MdT viene eseguita partendo da SX verso DX (quindi dalla posizione 0)/" << endl;
	
	position = 0;
	currentState = machine->getInitialState();
	TransitionValue const *currentTransition;

	bool mdtContinues = true;

	while (mdtContinues) {

		/// controllo posizione su nastro
		if (machineTape.find(position) == machineTape.end()) {
			// posizione not found => metto il simbolo vuoto
			machineTape[position] = 36;
		}

		currentTransition = getTransition(currentState, machineTape[position]);
		mdtContinues = currentTransition != nullptr;

		if (mdtContinues) {
			cout << getMachineStatus(currentTransition);
			machineTape[position] = currentTransition->nextSymbol;
			currentState = currentTransition->nextState;
			position += currentTransition->nextMove;
		}
	};

	cout << "Esecuzione conclusa" << endl;
	cout << "Nastro finale: " << printTape() << endl;
	cout << "STATO #" << currentState << ", " << ((currentState == machine->getFinalState() ) ? " " : " NON ") << "FINALE";
}

void mdtModels::TuringMachineState::addSymbol(int position, char symbol)
{
	this->machineTape.insert(std::pair<int, char>(position, symbol));
}

void mdtModels::TuringMachineState::flush()
{
	this->machineTape.clear();
}

size_t mdtModels::TuringMachineState::getTapeSize()
{
	return machineTape.size();
}

TransitionValue  const * mdtModels::TuringMachineState::getTransition(int currentState, char currentSymbol) {
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
