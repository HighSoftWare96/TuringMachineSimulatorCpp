#ifndef TRANSITION_VALUE
#define TRANSITION_VALUE
namespace mdtModels {
	/// Enum per i movimenti della testina della MdT.
	/** Questa enum utilizzata in questo namespace rappresenta 
	i valori ammessi per i movimenti della testina ed ha associati 
	gli interi corrispondenti da sommare al valore della posizione attuale
	della testina. */
	enum Movement {
		L = -1,
		N = 0,
		R = 1
	};
	/// Classe per rappresentare i valori di una transizione.
	/** Usata nella mappa delle transizioni per ricavare il prossimo stato della macchina, il simbolo da scrivere 
	e il movimento da fare data una certa chiave. */
	class TransitionValue
	{
	public:
		/// Prossimo stato della MdT.
		int nextState;
		/// Prossimo simbolo della MdT.
		char nextSymbol;
		/// Prossimo movimento della MdT.
		Movement nextMove;

		/// Costruttore vuoto, usato per la std::map.
		TransitionValue();
		/// Costruttore che riceve tutte i dati da assegnare alle proprietà 
		/// dell'oggetto stesso.
		TransitionValue(int nextState, char nextSymbol, Movement nextMove);
		/// Distruttore vuoto.
		~TransitionValue();
	};
}
#endif 



