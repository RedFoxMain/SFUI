cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
project ("SFUI_EXAMPLE")

add_executable(${PROJECT_NAME} "main.cpp")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME} PRIVATE SFUI)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
	"${CMAKE_CURRENT_SOURCE_DIR}/ArialRegular.ttf"
	"${PROJECT_BINARY_DIR}/ArialRegular.ttf"
)