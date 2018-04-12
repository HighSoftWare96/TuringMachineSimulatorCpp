#include <iostream>
#include <string>
#include "GpUtils.h"
using namespace std;
using namespace gpUtils;

int main() {
	int choice = 0;
	cout << "== SIMULATORE MACCHINE DI TURING == " << endl;
	while (choice != 3) {

		string rawChoice;
		cout << "Opzioni disponibili: " << endl << "1) Nuova macchina di Turing\n2) Esegui macchina di turing\n3) Esci\n:> ";
		cin >> rawChoice;
		try {
			choice = checkInput(rawChoice, 1, 3);
		}
		catch (...) {
			choice = 0;
			cout << "Input scorretto!\n";
		}
		switch (choice)
		{
		case 1:
			// TODO: implementare
			break;
		case 2:
			// TODO: eseguire
			break;
		default:
			break;
		}
	}
	return 0;
}