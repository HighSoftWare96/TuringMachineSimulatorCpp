/**
* @copyright TuringMachineSimulatorCpp
* license Apache
* @author Bertoncelli Giovanni
* @version v1.0.1
* @date May, 2018
* @file TransitionKey.cpp
*/

#include "../include/TransitionKey.h"
using namespace mdtModels;
using namespace std;


TransitionKey::TransitionKey(int currentState, char currentSymbol)
{
	this->currentState = currentState;
	this->currentSymbol = currentSymbol;
}


TransitionKey::~TransitionKey()
{
}

bool mdtModels::operator<(const TransitionKey & one, const TransitionKey & that)
{
	return one.currentState == that.currentState ? one.currentSymbol < that.currentSymbol : one.currentState < that.currentState;
}
