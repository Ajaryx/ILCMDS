cmake_minimum_required(VERSION 3.31.6)


project(ILCMDS
VERSION 0.1.0
LANGUAGES CXX)

# Global Project Settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
	FTXUI
	GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
	GIT_TAG v6.1.9
	GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(FTXUI)

#Project variables
set(PROJ_EXE "ILCMDS")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)


add_executable(${PROJ_EXE} "src/main.cpp" "src/core/Application.cpp"  "src/menus/AppMenu.cpp" "src/menus/AppMainMenu.cpp")
target_link_libraries(${PROJ_EXE} PRIVATE ftxui::screen ftxui::dom ftxui::component)


target_include_directories(${PROJ_EXE} PRIVATE "./include")
target_precompile_headers(${PROJ_EXE} PRIVATE "./include/PCH.hpp")

add_subdirectory(src)

