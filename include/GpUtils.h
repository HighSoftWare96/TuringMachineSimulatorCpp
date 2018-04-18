#ifndef GP_UTILS
#define GP_UTILS
#include <string>
#include <vector>
using namespace std;
/// Namespace che contiene tutte le definizioni general purpose del progetto.
namespace gpUtils {
	/// Funzione per verificare se un elemento intero è all'interno di un vector di interi.
	bool arrayContains(vector<int> array, int item);
	/// Funzione che ritorna un intero dato una stringa da cui prelevarlo e un range di valori ammessi.
	/** Se la stringa non corrisponde ad un intero o l'intero non è nel range corretto viene lanciata un'eccezione. */
	int checkInput(string stringa, int inRange, int outRange);
	/// Funzione che converte in-place una stringa nella sua corrispondente tutta minuscola.
	/** Per comodità la stringa viene anche restituita oltre che modificata permanentemente. */
	string toLower(string item);
}
#endif
