#ifndef TRANSITION_KEY
#define TRANSITION_KEY
namespace mdtModels {
	class TransitionKey
	{
	public:
		int currentState;
		int currentSymbol;
		TransitionKey();
		~TransitionKey();
	};
}
#endif



