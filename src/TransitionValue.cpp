#include "../include/TransitionValue.h"
using namespace mdtModels;
using namespace std;

mdtModels::TransitionValue::TransitionValue()
{
}

mdtModels::TransitionValue::TransitionValue(int nextState, char nextSymbol, Movement nextMove)
{
	this->nextMove = nextMove;
	this->nextState = nextState;
	this->nextSymbol = nextSymbol;
}

TransitionValue::~TransitionValue()
{
}
