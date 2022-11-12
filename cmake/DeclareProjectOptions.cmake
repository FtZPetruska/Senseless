include_guard()

if(HAVE_ADDRESS_SANITIZER)
  option(SL_ENABLE_ADDRESS_SANITIZER "Enable Address Sanitizer" OFF)
endif()

if(HAVE_THREAD_SANITIZER)
  option(SL_ENABLE_THREAD_SANITIZER "Enable Thread Sanitizer" OFF)
endif()

if(HAVE_MEMORY_SANITIZER)
  option(SL_ENABLE_MEMORY_SANITIZER "Enable Memory Sanitizer" OFF)
endif()

if(HAVE_UB_SANITIZER)
  option(SL_ENABLE_UB_SANITIZER "Enable Undefined Behaviour Sanitizer" OFF)
endif()

if(HAVE_LEAK_SANITIZER)
  option(SL_ENABLE_LEAK_SANITIZER "Enable Leak Sanitizer" OFF)
endif()

if(HAVE_NATIVE_OPTIMISATION)
  option(SL_ENABLE_NATIVE_OPTIMISATION "Enable non-portable optimisations" OFF)
endif()

if(HAVE_PROFILER)
  option(SL_ENABLE_PROFILER "Enable profiling" OFF)
endif()

if(HAVE_GCOV)
  option(SL_ENABLE_GCOV "Enable GNU Coverage tool" OFF)
endif()

if(HAVE_IPO)
  option(SL_ENABLE_LTO "Enable link-time optimisations" OFF)
endif()

if(CMAKE_CXX_LINK_PIE_SUPPORTED)
  option(SL_ENABLE_PIE "Enable position-independent code" ON)
endif()

if(CCACHE)
  option(SL_ENABLE_CCACHE "Speedup builds with ccache" ON)
endif()

if(CLANG_TIDY)
  option(SL_ENABLE_CLANG_TIDY "Enable clang-tidy analysis during build" OFF)
endif()

if(CLANG_FORMAT)
  option(SL_ENABLE_CLANG_FORMAT "Emable code format check during build" OFF)
endif()

if(IWYU)
  option(SL_ENABLE_IWYU "Emable include-what-you-use during build" OFF)
endif()

option(SL_ENABLE_TESTS "Enable tests" ${SL_IS_TOPLEVEL_PROJECT})

if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type specified, defaulting to 'Debug'")
  set(CMAKE_BUILD_TYPE
      "Debug"
      CACHE STRING "Build configuration to use" FORCE)
  set_property(
    CACHE CMAKE_BUILD_TYPE
    PROPERTY STRINGS
             "Debug"
             "Release"
             "MinSizeRel"
             "RelWithDebInfo")
endif()
