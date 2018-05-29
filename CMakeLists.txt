INCLUDE(CheckCXXCompilerFlag)

PROJECT(TuringMachineSimulatorCpp)
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)

IF(COMPILER_SUPPORTS_CXX14)
    ADD_COMPILE_OPTIONS("-std=c++14")
ELSE()
    MESSAGE(FATAL_ERROR "Compilatore ${CMAKE_CXX_COMPILER} non supporta C++14.")
ENDIF()

ADD_COMPILE_OPTIONS("-g")
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

SET(WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${PROJECT_SOURCE_DIR}/lib)

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include")
file(GLOB_RECURSE sources "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE testing_sources "${PROJECT_SOURCE_DIR}/test/*.cpp")
ADD_EXECUTABLE(TuringSimulatorOut.x ${sources})
ADD_EXECUTABLE(Testing.x ${testing_sources})
target_link_libraries(Testing.x Catch)

ADD_COMPILE_OPTIONS("-Wall")
ADD_COMPILE_OPTIONS("-Wextra")
ADD_COMPILE_OPTIONS("-pedantic")

ADD_CUSTOM_TARGET(doc
    COMMAND doxygen ${PROJECT_SOURCE_DIR}/doxyfile.cfg 
    COMMENT "Documentation generation"
)

ADD_CUSTOM_TARGET(rm 
COMMAND rm -rf ${PROJECT_SOURCE_DIR}/build/*
COMMAND rm -rf ${PROJECT_SOURCE_DIR}/bin/TuringSimulatorOut.x
COMMAND rm -rf ${PROJECT_SOURCE_DIR}/bin/Testing.x
COMMAND rm -rf ${PROJECT_SOURCE_DIR}/doc/*
COMMAND rm -rf ${PROJECT_SOURCE_DIR}/build/.clang-format
COMMENT "Clear CMAKE, DOC and BUILD assets")

INSTALL (
    FILES ${PROJECT_SOURCE_DIR}/build/bin/Testing.x ${PROJECT_SOURCE_DIR}/build/bin/TuringSimulatorOut.x
    DESTINATION ${PROJECT_SOURCE_DIR}/bin/
)

ADD_CUSTOM_TARGET(scan-build
    COMMAND scan-build make
    COMMENT "Scan-build tool analysis"
)

ADD_CUSTOM_TARGET(stats
    COMMAND cloc ${PROJECT_SOURCE_DIR}
    COMMENT "Building code stats"
)

ADD_CUSTOM_TARGET(valgrind
    COMMAND valgrind ${PROJECT_SOURCE_DIR}/bin/TuringSimulatorOut.x
    COMMENT "Valgrind..."
)

ADD_CUSTOM_TARGET(format
    COMMAND clang-format -style=llvm -dump-config > .clang-format
    COMMAND clang-format -i ${PROJECT_SOURCE_DIR}/src/*.cpp
    COMMAND clang-format -i ${PROJECT_SOURCE_DIR}/include/*.hpp
    COMMENT "Clang-formatting code documents"
)

ENABLE_TESTING()

ADD_TEST(NAME AllTests
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/test
    COMMAND ${PROJECT_SOURCE_DIR}/bin/Testing.x -r xml -o ${PROJECT_SOURCE_DIR}/test/test_report.xml
)