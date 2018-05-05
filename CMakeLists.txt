INCLUDE(CheckCXXCompilerFlag)

PROJECT(TuringMachineSimulatorCpp)
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)

IF(COMPILER_SUPPORTS_CXX14)
    ADD_COMPILE_OPTIONS("-std=c++14")
ELSE()
    MESSAGE(FATAL_ERROR "Compilatore ${CMAKE_CXX_COMPILER} non supporta C++14.")
ENDIF()

IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
    ADD_COMPILE_OPTIONS("-g")
    ADD_COMPILE_OPTIONS("-O1")
    IF (CMAKE_COMPILER_IS_GNUCXX)
        ADD_COMPILE_OPTIONS("-ggdb3")
    ELSEIF (CMAKE_CXX_COMPILER_ID EQUAL "Clang")
        ADD_COMPILE_OPTIONS("-fsanitize=address")
        ADD_COMPILE_OPTIONS("-fno-omit-frame-pointer")
    ENDIF()
ELSEIF (CMAKE_BUILD_TYPE STREQUAL "Release") # "Release" mode
    ADD_COMPILE_OPTIONS("-O2")
ENDIF()


INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include")
FILE(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)

ADD_COMPILE_OPTIONS("-Wall")
ADD_COMPILE_OPTIONS("-Wextra")
ADD_COMPILE_OPTIONS("-pedantic")


SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

ADD_CUSTOM_TARGET(doc
    COMMAND doxygen doxyfile.cfg 
    COMMENT "Documentation generation"
)

ADD_CUSTOM_TARGET(rm
COMMAND rm -rf Makefile
COMMAND rm -rf *.o 
COMMAND rm -rf ./CMakeFiles
COMMAND rm -rf CMakeCache.txt
COMMAND rm -rf cmake_install.cmake
COMMAND rm -rf bin/TuringSimulatorOut.x
COMMAND rm -rf doc/html
COMMAND rm -rf ./Testing
COMMAND rm -rf *.json *.cmake
COMMENT "Clear CMAKE, DOC and BUILD assets")

ADD_CUSTOM_TARGET(scan-build
    COMMAND scan-build make
    COMMENT "Scan-build tool analysis"
)

ADD_CUSTOM_TARGET(stats
    COMMAND cloc .
    COMMENT "Building code stats"
)

ADD_CUSTOM_TARGET(valgrind
    COMMAND valgrind ./bin/TuringSimulatorOut.x
    COMMENT "Clang-formatting code documents"
)

ADD_CUSTOM_TARGET(format
    COMMAND clang-format -style=llvm -dump-config > .clang-format
    COMMAND clang-format ./src/*.cpp
    COMMAND clang-format ./include/*.h
    COMMENT "Clang-formatting code documents"
)

ENABLE_TESTING()

ADD_TEST(NAME Test1 
WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
COMMAND TuringSimulatorOut.x)

ADD_TEST(NAME Test2
WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
COMMAND TuringSimulatorOut.x) 

SET_TESTS_PROPERTIES(Test2
PROPERTIES PASS_REGULAR_EXPRESSION "Correct")

ADD_EXECUTABLE(TuringSimulatorOut.x ${SRCS})