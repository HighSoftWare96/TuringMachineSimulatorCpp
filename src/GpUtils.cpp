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

using namespace std;

string gpUtils::toLower(string item) {
  std::transform(item.begin(), item.end(), item.begin(), ::tolower);
  return item;
}

template <> int gpUtils::checkInput<string>(string input, int inRange, int outRange) {
  int result;
  try {
    result = stoi(input);
  } catch (std::invalid_argument) {
    return inRange - 1;
  }
  if (result < inRange || result > outRange)
    return inRange - 1;

  return result;
}

template <> int gpUtils::checkInput<int>(int input, int inRange, int outRange) {
  if (input < inRange || input > outRange)
    return inRange - 1;
  return input;
}