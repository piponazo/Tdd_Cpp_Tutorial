cmake_minimum_required(VERSION 3.15)

include(cmake/policies.cmake              REQUIRED) # Must be before project() command

project(TddTutorial
  DESCRIPTION "TDD tutorial for C++"
  VERSION 0.0.1
  LANGUAGES CXX
)

include(cmake/mainSetup.cmake             REQUIRED)
include(cmake/findDependencies.cmake      REQUIRED)
include(cmake/compileroptions.cmake       REQUIRED)

option(BUILD_UNIT_TESTS        "Build unit tests"                                   ON )

add_subdirectory(lib)

if (GTest_FOUND)
  add_subdirectory(tests)
endif()

include(cmake/printSummary.cmake             REQUIRED)
