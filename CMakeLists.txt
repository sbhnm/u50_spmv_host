# Minimum required CMake version
cmake_minimum_required(VERSION 3.0)

# Project name
project(U50_SPMV_HOST)

# Set the C++ standard (adjust as needed)
set(CMAKE_C_STANDARD 11)

# Directories
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(BIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(BUILD_DIR build)

# Source files
file(GLOB SRCS ${SRC_DIR}/*.cpp)

# Create a list of source files
add_executable(${PROJECT_NAME} ${SRCS})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${INC_DIR})

# Set the output directory for the binary
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
)

# Create a separate build directory
set(CMAKE_BINARY_DIR ${BUILD_DIR})
set(EXECUTABLE_OUTPUT_PATH ${BUILD_DIR})
set(LIBRARY_OUTPUT_PATH ${BUILD_DIR})

# Clean up
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${BUILD_DIR})

# Optional: If you want to create a "make clean" target
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${BIN_DIR}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${BUILD_DIR}
)

# Optional: If you want to install the executable to a specific location
install(TARGETS ${PROJECT_NAME} DESTINATION /usr/local/bin)  # Modify the destination as needed
