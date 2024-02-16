cmake_minimum_required(VERSION 3.27)
project(so_long LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g") # Add debug information

# Define paths
set(SRC_PATH "srcs/")
set(INC_PATH "includes/")
set(LIB_PATH "libft/")
set(OBJ_PATH "${CMAKE_BINARY_DIR}/obj/") # CMake's binary dir for output
set(MLX_PATH "mlx_linux/")
set(TEXTURES_PATH "${CMAKE_SOURCE_DIR}/textures/")

# Include directories for compiler
include_directories(${INC_PATH})
include_directories(${LIB_PATH})
include_directories(${MLX_PATH})

# File globs for sources and headers
file(GLOB_RECURSE SRC_FILES "${SRC_PATH}*.c")
file(GLOB_RECURSE HEADER_FILES "${INC_PATH}*.h")

# Add the executable
add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES})

# Assuming libft.a is already compiled and available
# No need for add_custom_target(libft ...) here

# Ensure the MLX library is available
if(NOT EXISTS ${CMAKE_SOURCE_DIR}/${MLX_PATH})
    execute_process(COMMAND git clone https://github.com/42Paris/minilibx-linux.git ${MLX_PATH})
endif()
add_custom_target(mlx
        COMMAND make
        WORKING_DIRECTORY ${MLX_PATH}
)
add_dependencies(${PROJECT_NAME} mlx)

add_definitions(-DTEXTURES_PATH="${TEXTURES_PATH}")

# Find X11
find_package(X11 REQUIRED)
find_package(ZLIB REQUIRED)


# Link libraries
target_link_libraries(${PROJECT_NAME}
        ${CMAKE_SOURCE_DIR}/${LIB_PATH}libft.a
        ${CMAKE_SOURCE_DIR}/${MLX_PATH}libmlx_Linux.a
        ${X11_LIBRARIES}
        ${ZLIB_LIBRARIES}
        m # math library
)

# Include X11 and ZLIB includes
target_include_directories(${PROJECT_NAME} PRIVATE ${X11_INCLUDE_DIR} ${ZLIB_INCLUDE_DIRS})

# Custom clean and fclean targets remain unchanged
add_custom_target(custom_clean
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${OBJ_PATH}
        COMMAND make clean -C ${LIB_PATH}
        COMMAND make clean -C ${MLX_PATH}
)

add_custom_target(custom_fclean
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
        COMMAND make fclean -C ${LIB_PATH}
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${MLX_PATH}
)
