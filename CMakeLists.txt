cmake_minimum_required(VERSION 3.31.6)


project(ILCMDS
VERSION 0.1.0
LANGUAGES CXX)

# Global Project Settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(ARCH_X64 "Compile this program in 64 bit" OFF)
option(ARCH_X86 "Compile this program in 32 bit" ON)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(FetchContent)

FetchContent_Declare(
	FTXUI
	GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
	GIT_TAG v6.1.9
	GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(FTXUI)

FetchContent_Declare(
	nlohmann/json
	GIT_REPOSITORY https://github.com/nlohmann/json
	GIT_TAG v3.12.0
	GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(nlohmann/json)



#Project variables
set(PROJ_EXE "ILCMDS")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)


add_executable(${PROJ_EXE} "src/main.cpp" "src/core/Application.cpp")
target_link_libraries(${PROJ_EXE} PRIVATE ftxui::screen ftxui::dom ftxui::component nlohmann_json::nlohmann_json)



target_include_directories(${PROJ_EXE} PRIVATE "./include" "${CMAKE_BINARY_DIR}/config_files/")
target_precompile_headers(${PROJ_EXE} PRIVATE "./include/PCH.hpp")

add_subdirectory(ProjConfigure)
add_subdirectory(src)

