/**
 * @copyright TuringMachineSimulatorCpp
 * license Apache
 * @author Bertoncelli Giovanni
 * @version v1.0.1
 * @date May, 2018
 * @file Tests.h
 */
#define CATCH_CONFIG_MAIN
#include "../include/GpUtils.h"
#include "../include/TransitionBase.h"
#include "../include/TransitionValue.h"
#include "../include/TuringMachine.h"
#include "../include/TuringMachineState.h"
#include "../lib/catch.hpp"
#include "../src/GpUtils.cpp"
#include "../src/TuringMachineState.cpp"
#include "../src/TransitionBase.cpp"
#include "../src/TransitionValue.cpp"
#include "../src/TuringMachine.cpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace gpUtils;
using namespace mdtModels;

TEST_CASE("Array Contains", "[arrayContains]") {
  std::vector<int> *vector = new std::vector<int>();
  REQUIRE(arrayContains(vector, 1) == false);
  vector->push_back(1);
  REQUIRE(arrayContains(vector, 1) == true);
  delete vector;
}

TEST_CASE("To lower", "[toLower]") {
  string testString = "CIAO";
  REQUIRE(toLower(testString) == "ciao");
}

TEST_CASE("Check input", "[checkInput]") {
  REQUIRE(checkInput<string>("wrong", 1, 10) == 0);
  REQUIRE(checkInput<string>("uioyg9sgdas", -10, 10) == -11);
  REQUIRE(checkInput<string>("11", -10, 10) == -11);
  REQUIRE(checkInput<string>("-100", -10, 10) == -11);
  REQUIRE(checkInput<string>("-100", -200, 10) == -100);
  REQUIRE(checkInput<string>("100", -10, 100) == 100);
  REQUIRE(checkInput<int>(11, -10, 10) == -11);
  REQUIRE(checkInput<int>(-100, -10, 10) == -11);
  REQUIRE(checkInput<int>(-100, -200, 10) == -100);
  REQUIRE(checkInput<int>(100, -10, 100) == 100);
}

TEST_CASE("TransitionBase: Operator <", "[operator<]") {
  TransitionBase *transitionBase1 = new TransitionBase(1, 'a');
  TransitionBase *transitionBase2 = new TransitionBase(1, 'b');
  REQUIRE((*transitionBase1) < (*transitionBase2));
  delete transitionBase2;
  transitionBase2 = new TransitionBase(2, 'b');
  REQUIRE((*transitionBase1) < (*transitionBase2));
  delete transitionBase1;
  delete transitionBase2;
}

TEST_CASE("TuringMachine: addNewState", "[addNewState]") {
  TuringMachine *turingMachine = new TuringMachine();
  REQUIRE(turingMachine->getStates()->size() == 0);
  REQUIRE(turingMachine->addNewState(1) == true);
  REQUIRE(turingMachine->addNewState(1) == false);
  REQUIRE(turingMachine->addNewState(2) == true);
  REQUIRE(turingMachine->getStates()->size() != 0);
  delete turingMachine;
}

TEST_CASE("TuringMachine: setInitialState", "[setInitialState]") {
  TuringMachine *turingMachine = new TuringMachine();
  REQUIRE(turingMachine->setInitialState("") == false);
  REQUIRE(turingMachine->setInitialState("1") == false);
  REQUIRE(turingMachine->addNewState(1) == true);
  REQUIRE(turingMachine->setInitialState("1") == true);
  REQUIRE(turingMachine->setInitialState("-1") == false);
  delete turingMachine;
}

TEST_CASE("TuringMachine: setFinalState", "[setFinalState]") {
  TuringMachine *turingMachine = new TuringMachine();
  REQUIRE(turingMachine->setFinalState("") == false);
  REQUIRE(turingMachine->setFinalState("1") == false);
  REQUIRE(turingMachine->addNewState(1) == true);
  REQUIRE(turingMachine->setFinalState("1") == true);
  REQUIRE(turingMachine->setFinalState("-1") == false);
  delete turingMachine;
}

TEST_CASE("TuringMachine: insertTransition", "[insertTransition]") {
  TuringMachine *turingMachine = new TuringMachine();
  REQUIRE(turingMachine->insertTransition(1, 'a', 2, 'b', Movement::L) ==
          false);
  turingMachine->addNewState(1);
  REQUIRE(turingMachine->insertTransition(1, 'a', 2, 'b', Movement::L) ==
          false);
  turingMachine->addNewState(2);
  REQUIRE(turingMachine->insertTransition(1, 'a', 2, 'b', Movement::L) == true);
  delete turingMachine;
}

TEST_CASE("TuringMachine: checkStatusPresent", "[checkStatusPresent]") {
  TuringMachine *turingMachine = new TuringMachine();
  REQUIRE(turingMachine->checkStatusPresent(1) == false);
  turingMachine->addNewState(1);
  REQUIRE(turingMachine->checkStatusPresent(1) == true);
  delete turingMachine;
}

TEST_CASE("TuringMachine: getInitialState", "[getInitialState]") {
  TuringMachine *turingMachine = new TuringMachine();
  turingMachine->addNewState(1);
  turingMachine->addNewState(2);
  REQUIRE(turingMachine->setInitialState("1") == true);
  REQUIRE(turingMachine->setFinalState("2") == true);
  REQUIRE(turingMachine->getInitialState() == 1);
  REQUIRE(turingMachine->getFinalState()->isFinalState(2));
  delete turingMachine;
}

TEST_CASE("TuringMachineState: addSymbol", "[addSymbol]") {
  TuringMachine *turingMachine = new TuringMachine();
  TuringMachineState *turingMachineState =
      new TuringMachineState(turingMachine);
  turingMachineState->addSymbol(0, 'a');
  REQUIRE(turingMachineState->getTapeSize() != 0);
  delete turingMachineState;
  delete turingMachine;
}