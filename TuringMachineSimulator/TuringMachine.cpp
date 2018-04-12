#include "TuringMachine.h"
#include "GpUtils.h"
using namespace mdtModels;
using namespace std;
using namespace gpUtils;


TuringMachine::TuringMachine()
{
}


TuringMachine::~TuringMachine()
{
}

/// Permette di inserire un nuovo elemento all'interno della macchina di turing. 
bool TuringMachine::addNewState(int stateToInsert) {
	if (states == nullptr)
		states = new int[10];
	if (initializationIndex > 10) {
		int *tempArr = new int[initializationIndex];
		memcpy(tempArr, states, initializationIndex * sizeof(int) - 1);
		delete[] states;
		states = tempArr;
	}
	if (arrayContains(initializationIndex, states, stateToInsert))
		return false;
	states[initializationIndex] = stateToInsert;
	initializationIndex++;
	return true;
}

bool TuringMachine::setInitialState(int initialStateToInsert) {
	if (!arrayContains(initializationIndex - 1, states, initialStateToInsert))
		return false;
	else
		initialState = initialStateToInsert;
	return true;
}

bool TuringMachine::setFinalState(int finalStateToInsert) {
	if (!arrayContains(initializationIndex - 1, states, finalStateToInsert))
		return false;
	else
		finalState = finalStateToInsert;
	return true;
}