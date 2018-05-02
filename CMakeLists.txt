cmake_minimum_required(VERSION 3.10)
project(amcpp CXX)

enable_testing()
include(CTest)

# Compiler flags
## Debug flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g3 -fno-inline -fstack-protector-all")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-optimize-sibling-calls")

if (NOT WIN32)
   #set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fsanitize=undefined")
endif()

## Release flags
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -g0 -DNDEBUG")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -g0 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-Og -DNDEBUG")

function(build file)
   set(target "amcpp.${file}")
   add_executable("${target}" "${file}.cpp")
   target_compile_options("${target}" PUBLIC -Wall
                                      -Wextra
                                      -Wno-attributes
                                      -Wconversion
                                      -Wzero-as-null-pointer-constant
                                      -Wsign-promo
                                      -Woverloaded-virtual
                                      -Wlogical-op
                                      -Wcast-qual
                                      -Wold-style-cast
                                      -Wnon-virtual-dtor
                                      -Wodr
                                      -Werror
                                      -fdiagnostics-color=always)
   target_compile_features("${target}" PUBLIC cxx_std_17)
endfunction()

include_directories(include)
add_subdirectory(00-hello-world)
add_subdirectory(01-types)
add_subdirectory(02-computation)
