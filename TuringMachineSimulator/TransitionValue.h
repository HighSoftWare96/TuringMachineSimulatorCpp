#ifndef TRANSITION_VALUE
#define TRANSITION_VALUE
namespace mdtModels {

	enum Movement {
		L = -1,
		N = 0,
		R = 1
	};

	class TransitionValue
	{
	public:
		int nextState;
		char nextSymbol;
		Movement nextMove;

		TransitionValue();
		TransitionValue(int nextState, char nextSymbol, Movement nextMove);
		~TransitionValue();
	};
}
#endif 



