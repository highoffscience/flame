##
# @file    build.cmake
# @version 1.0.0
# @author  Forrest Jablonski
#

cmake_minimum_required(VERSION 3.27)

set(Target flame-src)

add_library(${Target} SHARED)

target_sources(${Target} PRIVATE
   ${RootDir}/src/flame.cpp
)

set_target_properties(${Target} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${Target} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${UtLibDir})

target_compile_options(${Target} PRIVATE ${CompileFlags})

## flame_subbuild
#
# @param NameOfUtSubDir -- Name of file (SUT, or Ut Dir) under test.
#
function(flame_subbuild NameOfUtSubDir)
   set(Target        flame-src-${NameOfUtSubDir})
   set(UtDirOfTarget ${CMAKE_SOURCE_DIR}/flame/src/${NameOfUtSubDir})

   add_library(${Target} SHARED)

   target_sources(${Target} PRIVATE
      ${UtDirOfTarget}/testsuite.cpp
   )

   target_include_directories(${Target} PRIVATE
      ${RootDir}/ym/common/
      ${RootDir}/src/
      ${CMAKE_SOURCE_DIR}/common/
   )

   target_link_directories(${Target} PRIVATE ${UtLibDir})
   target_link_libraries(${Target} PRIVATE ut-common)
   target_link_libraries(${Target} PRIVATE ym-common)
   target_link_libraries(${Target} PRIVATE flame-src)

   set_target_properties(${Target} PROPERTIES VERSION ${PROJECT_VERSION})
   set_target_properties(${Target} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${UtLibDir})

   string(TOUPPER -DYM_COMMON_UT_DBG_${NameOfUtSubDir} DbgFlags)
   set(DbgFlags ${DbgFlags} -DYM_COMMON_UT_DBG -DFLAME_UT_DBG)

   target_compile_options(${Target} PRIVATE ${CompileFlags} ${DbgFlags})
endfunction()
