##
# @file    CMakeLists.txt
# @version 1.0.0
# @author  Forrest Jablonski
#

cmake_minimum_required(VERSION 3.27)

project(
   Flame
   VERSION     1.0.0
   DESCRIPTION "Builds flame program")

set(Target flame)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${Target})

file(GLOB YmCommonSrcs "ym/common/*.cpp")

target_sources(${Target} PRIVATE
   ${CMAKE_SOURCE_DIR}/src/fitter.cpp
   ${CMAKE_SOURCE_DIR}/src/flame.cpp
   ${CMAKE_SOURCE_DIR}/src/render.cpp

   ${YmCommonSrcs}
)

find_package(PNG REQUIRED) # libpng

target_include_directories(${Target} PRIVATE
   ${CMAKE_SOURCE_DIR}/ym/common/
   ${CMAKE_SOURCE_DIR}/src/
   ${CMAKE_SOURCE_DIR}/common/

   ${PNG_INCLUDE_DIR}
)

target_link_libraries(${Target} ${PNG_LIBRARY})

set_target_properties(${Target} PROPERTIES VERSION ${PROJECT_VERSION})

set(CompileFlags
   -Werror
   -Wall
   -Wextra
   -Wno-format-security
   -Ofast
   -DYM_PRINT_TO_SCREEN)
target_compile_options(${Target} PRIVATE ${CompileFlags})
