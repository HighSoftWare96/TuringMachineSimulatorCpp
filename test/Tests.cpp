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
#include "../include/State.h"
#include "../src/State.cpp"

#include <iostream>
#include <string>
#include <vector>

TEST_CASE("Array Contains", "[arrayContains]") {
  std::vector<mdtModels::State<int>> vector = std::vector<mdtModels::State<int>>();
  REQUIRE(gpUtils::arrayContains(vector, mdtModels::State<int>(1)) == false);
  vector.push_back(mdtModels::State<int>(1));
  REQUIRE(gpUtils::arrayContains(vector, mdtModels::State<int>(1)) == true);
}

TEST_CASE("To lower", "[toLower]") {
  std::string testString = "CIAO";
  REQUIRE(gpUtils::toLower(testString) == "ciao");
}

TEST_CASE("Check input", "[checkInput]") {
  REQUIRE(gpUtils::checkInput<const std::string&>("wrong", 1, 10) == 0);
  REQUIRE(gpUtils::checkInput<const std::string&>("uioyg9sgdas", -10, 10) == -11);
  REQUIRE(gpUtils::checkInput<const std::string&>("11", -10, 10) == -11);
  REQUIRE(gpUtils::checkInput<const std::string&>("-100", -10, 10) == -11);
  REQUIRE(gpUtils::checkInput<const std::string&>("-100", -200, 10) == -100);
  REQUIRE(gpUtils::checkInput<const std::string&>("100", -10, 100) == 100);
  REQUIRE(gpUtils::checkInput<int>(11, -10, 10) == -11);
  REQUIRE(gpUtils::checkInput<int>(-100, -10, 10) == -11);
  REQUIRE(gpUtils::checkInput<int>(-100, -200, 10) == -100);
  REQUIRE(gpUtils::checkInput<int>(100, -10, 100) == 100);
}

TEST_CASE("TransitionBase: Operator <", "[operator<]") {
  mdtModels::TransitionBase *transitionBase1 = new mdtModels::TransitionBase(1, 'a');
  mdtModels::TransitionBase *transitionBase2 = new mdtModels::TransitionBase(1, 'b');
  REQUIRE((*transitionBase1) < (*transitionBase2));
  delete transitionBase2;
  transitionBase2 = new mdtModels::TransitionBase(2, 'b');
  REQUIRE((*transitionBase1) < (*transitionBase2));
  delete transitionBase1;
  delete transitionBase2;
}

TEST_CASE("TuringMachine: addNewState", "[addNewState]") {
  mdtModels::TuringMachine *turingMachine = new mdtModels::TuringMachine();
  REQUIRE(turingMachine->getStates().size() == 0);
  REQUIRE(turingMachine->addNewState(1) == true);
  REQUIRE(turingMachine->addNewState(1) == false);
  REQUIRE(turingMachine->addNewState(2) == true);
  REQUIRE(turingMachine->getStates().size() != 0);
  delete turingMachine;
}

TEST_CASE("TuringMachine: setInitialState", "[setInitialState]") {
  mdtModels::TuringMachine *turingMachine = new mdtModels::TuringMachine();
  REQUIRE(turingMachine->setInitialState("") == false);
  REQUIRE(turingMachine->setInitialState("1") == false);
  REQUIRE(turingMachine->addNewState(1) == true);
  REQUIRE(turingMachine->setInitialState("1") == true);
  REQUIRE(turingMachine->setInitialState("-1") == false);
  delete turingMachine;
}

TEST_CASE("TuringMachine: setFinalState", "[setFinalState]") {
  mdtModels::TuringMachine *turingMachine = new mdtModels::TuringMachine();
  REQUIRE(turingMachine->setFinalState("") == false);
  REQUIRE(turingMachine->setFinalState("1") == false);
  REQUIRE(turingMachine->addNewState(1) == true);
  REQUIRE(turingMachine->setFinalState("1") == true);
  REQUIRE(turingMachine->setFinalState("-1") == false);
  delete turingMachine;
}

TEST_CASE("TuringMachine: insertTransition", "[insertTransition]") {
  mdtModels::TuringMachine *turingMachine = new mdtModels::TuringMachine();
  REQUIRE(turingMachine->insertTransition(1, 'a', 2, 'b', mdtModels::Movement::L) ==
          false);
  turingMachine->addNewState(1);
  REQUIRE(turingMachine->insertTransition(1, 'a', 2, 'b', mdtModels::Movement::L) ==
          false);
  turingMachine->addNewState(2);
  REQUIRE(turingMachine->insertTransition(1, 'a', 2, 'b', mdtModels::Movement::L) == true);
  delete turingMachine;
}

TEST_CASE("TuringMachine: checkStatusPresent", "[checkStatusPresent]") {
  mdtModels::TuringMachine *turingMachine = new mdtModels::TuringMachine();
  REQUIRE(turingMachine->checkStatusPresent(1) == false);
  turingMachine->addNewState(1);
  REQUIRE(turingMachine->checkStatusPresent(1) == true);
  delete turingMachine;
}

TEST_CASE("TuringMachine: getInitialState", "[getInitialState]") {
  mdtModels::TuringMachine *turingMachine = new mdtModels::TuringMachine();
  turingMachine->addNewState(1);
  turingMachine->addNewState(2);
  REQUIRE(turingMachine->setInitialState("1") == true);
  REQUIRE(turingMachine->setFinalState("2") == true);
  REQUIRE(turingMachine->getInitialState().getState() == 1);
  delete turingMachine;
}

TEST_CASE("TuringMachineState: addSymbol", "[addSymbol]") {
  mdtModels::TuringMachine *turingMachine = new mdtModels::TuringMachine();
  mdtModels::TuringMachineState *turingMachineState =
      new mdtModels::TuringMachineState(turingMachine);
  turingMachineState->addSymbol(0, 'a');
  REQUIRE(turingMachineState->getTapeSize() != 0);
  delete turingMachineState;
  delete turingMachine;
}
