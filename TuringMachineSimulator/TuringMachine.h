#ifndef TURING_MACHINE
#define TURING_MACHINE
#include <map>
#include "TransitionKey.h"
#include "TransitionValue.h"

namespace mdtModels {
	class TuringMachine
	{
	private:
		int *states;
		int initialState;
		int finalState;
		std::map<TransitionKey, TransitionValue> transitions;
		int initializationIndex = 0;

	public:
		TuringMachine();
		~TuringMachine();
		/// Permette di inserire un nuovo elemento all'interno della macchina di turing. 
		bool addNewState(int stateToInsert);
		bool setInitialState(int initialStateToInsert);
		bool setFinalState(int finalStateToInsert);

	};
}

#endif