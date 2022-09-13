cmake_minimum_required(VERSION 3.9)
FUNCTION(PREPEND var prefix)
   SET(listVar "")
   FOREACH(f ${ARGN})
      LIST(APPEND listVar "${prefix}/${f}")
   ENDFOREACH(f)
   SET(${var} "${listVar}" PARENT_SCOPE)
ENDFUNCTION(PREPEND)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(INC Includes)

set(NAME fractol)
project(${NAME} C)

set(LIBFT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libft)
set(LIBFT_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libft/CMakeFiles)

set(SDIR Srcs)

set(SOURCES
		"rose.c"
		"rose_point.c"
		"web.c"
		"web_point.c"
		"ancients.c"
		"ancients_point.c"
		"fish.c"
		"fish_point.c"
		"drawing.c"
		"julia.c"
		"julia_point.c"
		"mandelbrot_key_hook.c"
		"burning_ship_point.c"
        "burning_ship.c"
		"mandelbrot.c"
		"mandelbrot_point.c"
		"new_image.c"
		"key_hook.c"
		"errors.c"
		"main.c")
PREPEND(SOURCES_REL ${SDIR} ${SOURCES})

message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Executable output dir" FORCE)
message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")

set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

add_executable(${NAME} ${SOURCES_REL} Srcs/julia.c Srcs/burning_ship.c Srcs/julia_key_hook.c Srcs/fish_point.c)
target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${INC})

add_subdirectory(${LIBFT_SOURCE_DIR} ${LIBFT_BINARY_DIR})
target_link_libraries(${NAME} libft.a)
target_link_libraries(${NAME} "-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit")
include_directories(${LIBFT_INC})
