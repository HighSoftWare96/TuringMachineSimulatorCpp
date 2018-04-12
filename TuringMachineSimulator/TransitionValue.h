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
		int nextSymbol;
		Movement nextMove;

		TransitionValue();
		~TransitionValue();
	};
}
#endif 



