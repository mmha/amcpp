#
#  Copyright Christopher Di Bella
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
cmake_minimum_required(VERSION 3.10)
project(amcpp CXX)

enable_testing()
include(CTest)

function(build file)
   set(target "amcpp.${file}")
   add_executable("${target}" "${file}.cpp")
   target_compile_options("${target}" PUBLIC
      -Wall
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
      -fdiagnostics-color=always
      $<$<CONFIG:Debug>:
         -O0
         -g3
         -fno-inline
         -fstack-protector-all
         -fno-omit-frame-pointer
         -fno-optimize-sibling-calls>
      $<$<CONFIG:Release>:
         -O3
         -g0
         -DNDEBUG>
      $<$<CONFIG:MinSizeRel>:
         -Os
         -g0
         -DNDEBUG>
      $<$<CONFIG:RelWithDebInfo>:
         -O3
         -g3
         -DNDEBUG>)
   if (NOT WIN32)
      target_compile_options("${target}" PUBLIC
         $<$<CONFIG:Debug>:
            -fsanitize=address
            -fsanitize=undefined>
         $<$<CONFIG:RelWithDebInfo>:
            -fsanitize=address
            -fsanitize=undefined>)
   endif()
   target_compile_definitions("${target}" PUBLIC
      $<$<CONFIG:Release>: NDEBUG>
      $<$<CONFIG:MinSizeRel>: NDEBUG>)
   target_compile_features("${target}" PUBLIC cxx_std_17)
endfunction()

include_directories(include)
add_subdirectory(00-hello-world)
add_subdirectory(01-types)
add_subdirectory(02-computation)
