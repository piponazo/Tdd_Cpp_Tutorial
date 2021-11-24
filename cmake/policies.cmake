# enable MSVC_RUNTIME_LIBRARY target property
# see https://cmake.org/cmake/help/latest/policy/CMP0091.html
if(POLICY CMP0091)
  cmake_policy(SET CMP0091 NEW)
endif()

cmake_policy(SET CMP0092 NEW) # MSVC warning flags are not in CMAKE_<LANG>_FLAGS by default.
