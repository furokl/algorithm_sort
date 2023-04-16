cmake_minimum_required (VERSION 3.5)

set(PROJECT_NAME Algorithm_Sort)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES 
	main.cpp)

file(GLOB MY_SRC 
	"src/*.h" 
	"src/*.cpp")

project(${PROJECT_NAME} CXX)
add_executable(${PROJECT_NAME} ${SOURCES} ${MY_SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

message(STATUS "\nUse C++20")
