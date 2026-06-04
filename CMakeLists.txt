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
	"include/SFUI/widget.hpp"
	"include/SFUI/Label/label.hpp"
	"include/SFUI/Button/button.hpp"
	"include/SFUI/Button/check_box.hpp"
	"include/SFUI/Button/radio_button.hpp"
	"include/SFUI/Button/button_interface.hpp"
	"include/SFUI/ProgressBar/progress_bar.hpp"
	"include/SFUI/Range/range.hpp"
	"include/SFUI/TextBox/text_box.hpp"
	"include/SFUI/Image/image.hpp"
	"include/SFUI/Window/window.hpp"
	"include/SFUI/utils.hpp"
)

set(
	SRC_FILES
	"src/SFUI/core.cpp"
	"src/SFUI/Label/label.cpp"
	"src/SFUI/Button/button.cpp"
	"src/SFUI/Button/check_box.cpp"
	"src/SFUI/Button/radio_button.cpp"
	"src/SFUI/ProgressBar/progress_bar.cpp"
	"src/SFUI/Range/range.cpp"
	"src/SFUI/TextBox/text_box.cpp"
	"src/SFUI/Image/image.cpp"
	"src/SFUI/Window/window.cpp"
	"src/SFUI/utils.cpp"
)

#if(BUILD_EXAMPLE STREQUAL "ON")
add_subdirectory("example")
#endif()
set(DEFAULT_FONT "${CMAKE_CURRENT_SOURCE_DIR}/resources/ArialRegular.ttf")
configure_file(
   "${CMAKE_CURRENT_SOURCE_DIR}/include/SFUI/config.h.in"
   "${CMAKE_CURRENT_BINARY_DIR}/config.h"
    @ONLY
)
list(APPEND INCLUDE_FILES  "${CMAKE_CURRENT_BINARY_DIR}/config.h")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources/ArialRegular.ttf" DESTINATION "${PROJECT_BINARY_DIR}/resources/")

set(SFML_STATIC_LIBRARIES TRUE )
find_package(SFML 3.0.0 COMPONENTS Graphics REQUIRED)
add_library(${PROJECT_NAME} STATIC ${INCLUDE_FILES} ${SRC_FILES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_include_directories(${PROJECT_NAME} PUBLIC ${SRC_FILES} ${INCLUDE_FILES})

# Link SFML
target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} SFML::Graphics)