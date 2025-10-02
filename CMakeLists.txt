cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
project("SFUI")

option(BUILD_EXAMPLE "Build example" OFF)
set(EXECUTABLE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
set(LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")

set(
	INCLUDE_FILES
	"include/SFUI/core.hpp"
	"include/SFUI/Button/button.hpp"
	"include/SFUI/widget.hpp"
	"include/SFUI/ProgressBar/progress_bar.hpp"
	"include/SFUI/Range/range.hpp"
	"include/SFUI/Button/button_interface.hpp"
	"include/SFUI/TextBox/text_box.hpp"
	"include/SFUI/Button/check_box.hpp"
	"include/SFUI/Button/radio_button.hpp"
	"include/SFUI/Window/window.hpp"
	"include/SFUI/Text/text.hpp"
)

set(
	SRC_FILES
	"src/SFUI/core.cpp"
	"src/SFUI/Button/button.cpp"
	"src/SFUI/ProgressBar/progress_bar.cpp"
	"src/SFUI/TextBox/text_box.cpp"
	"src/SFUI/Range/range.cpp"
	"src/SFUI/Button/check_box.cpp"
	"src/SFUI/Button/radio_button.cpp"
	"src/SFUI/Window/window.cpp"
	"src/SFUI/Text/text.cpp"
)

if(BUILD_EXAMPLE STREQUAL "ON")
	add_subdirectory("example")
endif()

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/thirdparty/SFML-3.0.0")
set(SFML_STATIC_LIBRARIES TRUE )
find_package(SFML 3.0.0 COMPONENTS Graphics REQUIRED)
add_library(${PROJECT_NAME} STATIC ${INCLUDE_FILES} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_FILES} ${INCLUDE_FILES})

# Link SFML
target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} SFML::Graphics)