/**
* @copyright TuringMachineSimulatorCpp
* license Apache
* @author Bertoncelli Giovanni
* @version v1.0.1
* @date May, 2018
* @file TuringMachine.h
*/

#pragma once
#include <map>
#include <vector>
#include "TransitionBase.h"
#include "TransitionValue.h"
#include <string>

/// Namespace per le classi di rappresentazione delle MdT. 
/** Il namespace contiene tutte le classi per la rappresentazione corretta della MdT tra cui la classe 
* TuringMachine che rappresenta il modello stesso, la classe TuringMachineState che contiene le informazioni per 
* l'esecuzione di una mdt su un nastro e altre sotto-classi per la rappresentazione delle transizioni. 
*/
namespace mdtModels {

	/// Classe per la rappresentazione di una macchina di Turing. 
	/** Contiene tutte le informazioni rappresentanti una mdt tra cui gli stati,
	uno stato finale, uno stato iniziale, una serie di transizioni, l'alfabeto è implicito. */
	class TuringMachine
	{

	private:
		/// Vector contenente gli stati della MdT, dinamico.
		std::vector<int> *states;
		/// Stato iniziale della mdt.
		int initialState;
		/// Stato finale della mdt.
		int finalState;
		/// Transizioni della macchina di turing.
		/** Mappo ogni transizione con un oggetto TransitionKey che contiene stato attuale e simbolo attuale con un TransitionValue che contiene uno stato successivo
		, un simbolo da scrivere e un movimento da fare della testina.*/
		std::map<TransitionBase, TransitionValue> *transitions;

	public:
		/// Costruttore vuoto.
		TuringMachine();
		/// Distruttore vuoto.
		~TuringMachine();
		/// Permette di inserire un nuovo elemento all'interno della macchina di turing. 
		bool addNewState(int stateToInsert);
		/// Permette di impostare lo stato iniziale della mdt valutandolo da una stringa.
		bool setInitialState(std::string initialStateToInsert);
		/// Permette di impostare lo stato finale della mdt valutandolo da una stringa.
		bool setFinalState(std::string finalStateToInsert);
		/// Restituisce il vettore contenente gli stati della mdt.
		std::vector<int> *getStates();
		/// Restituisce una rappresentazione a stringa degli stati della mdt.
		std::string printStates();
		/// Inserisce una transizione ricevuti tutti gli argomenti necessari.
		bool insertTransition(int state, char symbol, int nextState, char nextSymbol, Movement nextMove);
		/// Controlla la presenza di uno stato nella mdt.
		bool checkStatusPresent(int state);
		/// Restituisce una rappresentazione a stringa delle transizioni della mdt.
		std::string printTransitions();
		/// Restituisce lo stato iniziale.
		int getInitialState();
		/// Restituisce lo stato finale.
		int getFinalState();
		/// Restituisce le transizioni come mappa.
		std::map<TransitionBase, TransitionValue> *getTransitions();
	};
}
