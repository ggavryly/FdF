cmake_minimum_required(VERSION 3.13)
project(FdF C)

set(CMAKE_C_STANDARD 99)

include_directories(libft minilibx_macos)
include_directories(libft/include)
include_directories(include)
link_directories(libft minilibx_macos)

set(SOURCE
        src/draw_3d.c
        src/draw.c
        src/read.c
        src/main.c
        src/init.c)

add_executable(FdF ${SOURCE})

target_link_libraries(FdF -lmlx -lft "-framework OpenGL" "-framework AppKit")