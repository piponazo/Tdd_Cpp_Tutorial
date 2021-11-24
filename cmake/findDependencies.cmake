# we rely on the conan cmake_find_package generator
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

if(BUILD_UNIT_TESTS)
  find_package(GTest REQUIRED)
endif()
