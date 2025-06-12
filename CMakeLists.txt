cmake_minimum_required(VERSION 4.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(todos)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SRC_FILES 
	"src/*.cpp"
	"src/*.hpp"
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

if (EXISTS build/compile_commands.json)
	file(COPY_FILE build/compile_commands.json ./compile_commands.json)
endif()
