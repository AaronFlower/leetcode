cmake_minimum_required(VERSION 3.10 )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON )

project(leetCode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11" )

set(IGNORE_LIST .git build lib Xcode)
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

enable_testing()
add_subdirectory(lib/googletest)

# Add subdirectories 
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
      IF(IS_DIRECTORY ${curdir}/${child} AND NOT ${child} IN_LIST IGNORE_LIST)
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

FOREACH(subdir ${SUBDIRS})
    message(STATUS "Add subdirectory: ${subdir}")
    ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()
