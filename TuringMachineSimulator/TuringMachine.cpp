#include "TuringMachine.h"
#include "GpUtils.h"
#include <iostream>
#include <string>
#include "TransitionKey.h"
#include "TransitionValue.h"
#include "TuringMachineState.h"
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
	if (arrayContains(states, stateToInsert))
		return false;
	if (stateToInsert >= 0)
		states.push_back(stateToInsert);
	return true;
}

bool TuringMachine::setInitialState(string rawString) {
	int initialStateToInsert;
	try {
		initialStateToInsert = checkInput(rawString, 0, 100);
	}
	catch (...) {
		return false;
	}
	if (initialStateToInsert < 0 || !arrayContains(states, initialStateToInsert))
		return false;
	else
		initialState = initialStateToInsert;
	return true;
}

bool TuringMachine::setFinalState(string rawString) {
	int finalStateToInsert;
	try {
		finalStateToInsert = checkInput(rawString, 0, 100);
	}
	catch (...) {
		return false;
	}
	if (finalStateToInsert < 0 || !arrayContains(states, finalStateToInsert))
		return false;
	else
		finalState = finalStateToInsert;
	return true;
}

std::vector<int> mdtModels::TuringMachine::getStates()
{
	return states;
}

string mdtModels::TuringMachine::printStates()
{
	string result;
	for (int item : states) {
		result += "[";
		result += to_string(item);
		result += "] ";
	}
	return result;
}

bool mdtModels::TuringMachine::insertTransition(int state, char symbol, int nextState, char nextSymbol, Movement nextMove)
{
	if (!arrayContains(states, state) || !arrayContains(states, state))
		return false;
	TransitionKey key = TransitionKey(state, symbol);
	TransitionValue value = TransitionValue(nextState, nextSymbol, nextMove);
	transitions[key] = value;
	return true;
}

bool mdtModels::TuringMachine::checkStatusPresent(int state)
{
	return arrayContains(states, state);
}

std::string mdtModels::TuringMachine::printTransitions()
{
	string result = "";
	for (const pair<TransitionKey, TransitionValue>& item : transitions) {
		result += "(";
		result += to_string(item.first.currentState);
		result += ",";
		result += item.first.currentSymbol;
		result += ") => (";
		result += to_string(item.second.nextState);
		result += ",";
		result += item.second.nextSymbol;
		result += ",";
		result += (item.second.nextMove == L ? "L" : ((item.second.nextMove == R) ? "R" : "N"));
		result += ")\n";
	}
	return result;
}

int mdtModels::TuringMachine::getInitialState()
{
	return initialState;
}

int mdtModels::TuringMachine::getFinalState()
{
	return finalState;
}

std::map<TransitionKey, TransitionValue> *mdtModels::TuringMachine::getTransitions()
{
	return & transitions;
}
