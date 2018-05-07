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

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)

enable_testing()
include(CTest)

find_package(MSGSL REQUIRED)
find_package(Sanitizer COMPONENTS address undefined)

function(build file)
   set(target "amcpp.${file}")
   add_executable(${target} "${file}.cpp")
   target_compile_options(${target} PUBLIC
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
         -fstack-protector-all>)
   target_link_libraries(${target} PUBLIC
      $<$<CONFIG:Debug>:Sanitizer::all>
      $<$<CONFIG:RelWithDebInfo>:Sanitizer::all>)
   target_compile_features(${target} PUBLIC cxx_std_17)
   target_link_libraries(${target} PUBLIC MSGSL::gsl)
   target_include_directories(${target} PUBLIC "${PROJECT_SOURCE_DIR}/include")
endfunction()

add_subdirectory(00-hello-world)
add_subdirectory(01-types)
add_subdirectory(02-computation)
