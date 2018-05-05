/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file GpUtils.h
 */

#pragma once
#include <string>
#include <vector>
using namespace std;

/// Namespace che contiene tutte le definizioni general purpose del progetto.
namespace gpUtils {
/// Funzione per verificare se un elemento intero è all'interno di un vector di
/// interi.
bool arrayContains(vector<int> *array, int item);

/// Funzione che converte in-place una stringa nella sua corrispondente tutta
/// minuscola.
/** Per comodità la stringa viene anche restituita oltre che modificata
 * permanentemente. */
string toLower(string item);

/// Funzione che ritorna un intero dato una stringa da cui prelevarlo e un range
/// di valori ammessi.
/** Se la stringa non corrisponde ad un intero o l'intero non è nel range
 * corretto viene lanciata un'eccezione. */
template <typename T> int checkInput(T input, int inRange, int outRange);
template <> int checkInput<string>(string input, int inRange, int outRange);
template <> int checkInput<int>(int input, int inRange, int outRange);

} // namespace gpUtils
