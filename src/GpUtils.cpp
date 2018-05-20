/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file GpUtils.cpp
 */
#include "../include/GpUtils.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

string gpUtils::toLower(string& item) {
  std::transform(item.begin(), item.end(), item.begin(), ::tolower);
  return item;
}

template <> const int gpUtils::checkInput<const string&>(const string& input, 
int inRange, int outRange) {
  int result;
  try { // non posso NON fare uso della gestione delle eccezioni 
  // qui se voglio usare la funzione stoi().
    result = std::stoi(input);
  } catch (std::invalid_argument) {
    return inRange - 1;
  }
  if (result < inRange || result > outRange)
    return inRange - 1;

  return result;
}

template <> const int gpUtils::checkInput<int>(int input, int inRange, int outRange) {
  if (input < inRange || input > outRange)
    return inRange - 1;
  return input;
}