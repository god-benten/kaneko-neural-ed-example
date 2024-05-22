cmake_minimum_required(VERSION 2.8.12)
project(new C)

find_package(X11 REQUIRED)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-deprecated-declarations -Wno-dangling-else")

add_executable(
	new
	graphic.c
	neuro.c
	main.c
	output_calc.c
	param_input.c
	teach_calc.c
	weight_calc.c
	write.c
	teach_input.c
)

target_include_directories(new SYSTEM PUBLIC ${X11_INCLUDE_DIR})
target_link_libraries(new ${X11_LIBRARIES} m)
