cmake_minimum_required(VERSION 3.16)
project(Error LANGUAGES CXX) # specify the project name and the language used

if (UNIX)
    set(CMAKE_CXX_FLAGS "-g3 -O2")
elseif(WIN32)
    set(CMAKE_CXX_FLAGS "-O2 /EHsc")
endif() # set extra flags

file(GLOB SOURCES "*.cpp") # specify the source files
add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(Error PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET Error PROPERTY POSITION_INDEPENDENT_CODE ON)
