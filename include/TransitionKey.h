#ifndef TRANSITION_KEY
#define TRANSITION_KEY
namespace mdtModels
{

/// Classe che rappresenta la chiave di una transizione.
/** La classe è composta da due proprietà pubbliche: lo stato e il simbolo che rappresentano lo stato 
	corrente e il simbolo sulla posizione corrente del nastro con cui cercare poi una transizione corrispondente. */
class TransitionKey
	{
  public:
	/// Stato corrente della MdT.
	int currentState;
	/// Simbolo corrente della MdT.
	char currentSymbol;
	/// Costruttore della chiave: imposta lo stato e il simbolo della chiave.
	TransitionKey(int currentState, char currentSymbol);
	/// Distruttore vuoto.
	~TransitionKey();

	/// Overloading dell'operatore < utilizzato per implementare questa classe come chiave di una mappa.
	/** Necessario a std::map per costruire l'albero di rappresentazione della mappa: ha bisogno di sapere in che ordine
	porre gli elementi all'internod della struttura dati.*/
	friend bool operator<(const TransitionKey &one, const TransitionKey &that);
	};
	bool operator<(const TransitionKey & one, const TransitionKey & that);
}

#endif
