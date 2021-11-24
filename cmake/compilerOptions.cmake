if (${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
  set(COMPILER_IS_GCC ON)
elseif (${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
  set(COMPILER_IS_CLANG ON)
endif()

if (UNIX)
  add_compile_options(-Werror)                                            # Treat warnings as errors
  add_compile_options(-Wall -Wextra -Wshadow)                             # Recommended warnings flags
  add_compile_options(-Wcast-align)
  add_compile_options(-Wsign-conversion)
  add_compile_options(-Wunreachable-code)
  add_compile_options(-Wfloat-equal)
  add_compile_options(-Wformat=2)
  add_compile_options(-Woverlength-strings)
  add_compile_options(-Wunreachable-code)

  set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

  # This one triggers many warnings that are actually valid and will cause issues when fuzzing the
  # software. For example: uint_16 + uint16 can overflow.
  # add_compile_options(-Wconversion)

  if(BUILD_WITH_COVERAGE)
    add_compile_options(--coverage)
    add_link_options(--coverage)
  endif()
endif()

if (MSVC)
  #set(CMAKE_CXX_FLAGS_DEBUG "/Zi /Ob0 /Od /Oy-") # Useful for running DrMemory
  # /OPT:REF eliminates functions and data that are never referenced;
  # Use ICF[=iterations] to perform identical COMDAT folding. Redundant COMDATs can be removed from the linker output.
  # https://gitlab.kitware.com/cmake/cmake/-/issues/20812
  #set(CMAKE_CXX_FLAGS_RELEASE "/O2 /Ob2 /DNDEBUG /Zi /Zf") # Adding /Zi to the default options for generating PDBs
  #set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/DEBUG /OPT:REF /OPT:ICF")
  #set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/DEBUG /OPT:REF /OPT:ICF")

  set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/INCREMENTAL:NO /OPT:REF /OPT:ICF")
  set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/INCREMENTAL:NO /OPT:REF /OPT:ICF")

  add_compile_options(/MP)
  add_compile_options(/WX)                                                # Treat warnings as errors
  add_compile_options(/W4)                                                # Warning level
  add_compile_options(/EHsc)

  add_definitions(-DNOMINMAX -DWIN32_LEAN_AND_MEAN -DNOCOMM)
endif()

