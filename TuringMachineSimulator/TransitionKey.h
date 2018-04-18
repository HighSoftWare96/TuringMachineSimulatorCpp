#ifndef TRANSITION_KEY
#define TRANSITION_KEY
namespace mdtModels {
	class TransitionKey
	{
	public:
		int currentState;
		char currentSymbol;
		TransitionKey(int currentState, char currentSymbol);
		~TransitionKey();
	/// IMPORTANTE!! cosi si fa l'overloading di operatori (in questo caso necessario per l'uso nella map)
	friend bool operator<(const TransitionKey & one, const TransitionKey & that);
	};

}

#endif



