/**
 * @copyright TuringMachineSimulatorCpp license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file GpUtils.hpp
 */

#pragma once
#include <string>
#include <vector>

/// Namespace che contiene tutte le definizioni general purpose del progetto.
namespace gpUtils {

/// Funzione costante che mi restituisce dato un tipo T se questo è contenuto in
/// un vector di elementi di questo tipo T.
template <typename T> constexpr bool contains(std::vector<T> &array, T item) {
  for (T i : array) {
    if (item == i)
      return true;
  }
  return false;
}

/// Funzione per verificare se un elemento intero è all'interno di un vector di
/// interi.
template <typename T> bool arrayContains(std::vector<T> &array, T item) {
  return contains(array, item);
}
/// Funzione che converte in-place una stringa nella sua corrispondente tutta
/// minuscola.
/** Per comodità la stringa viene anche restituita oltre che modificata
 * permanentemente. */
std::string toLower(std::string &item);

/// Funzione che ritorna un intero dato una stringa da cui prelevarlo e un range
/// di valori ammessi.
/** Se la stringa non corrisponde ad un intero o l'intero non è nel range
 * corretto viene lanciata un'eccezione. */
template <typename T> const int checkInput(T input, int inRange, int outRange);
template <>
const int checkInput<const std::string &>(const std::string &input, int inRange,
                                          int outRange);
template <> const int checkInput<int>(int input, int inRange, int outRange);

} // namespace gpUtils