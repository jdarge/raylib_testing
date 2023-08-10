cmake_minimum_required(VERSION 3.23.2)

# Setting a variable to use for both the project name and the resulting binary executable
set(REPO scarfy)
project(${REPO})
set(PROJECT_NAME ${REPO})


# Set the C standard to C99
set(CMAKE_C_STANDARD 99)

# Compiler flags
set(CPP_FLAGS "-Wall -Wextra -pedantic")


# Add the src directory to the include path
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add all the source files in the src directory to the project
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.c)

# Create the executable from the source files
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/driver.c ${SOURCES})


# Set the output directory to the build/bin directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)
set_target_properties(${PROJECT_NAME}
        PROPERTIES
        COMPILE_FLAGS ${CPP_FLAGS}
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin
        )

# Set the object directory to the build/obj directory
set_property(
        TARGET ${PROJECT_NAME}
        PROPERTY
        CMAKE_OBJECT_PATH_PREFIX ${PROJECT_SOURCE_DIR}/build/obj/
)


# Set the cmake binary directory to the build/cmake directory
set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build/cmake)

# Add the build/cmake directory to the include path
include_directories(${PROJECT_SOURCE_DIR}/build/cmake)


# Add any other dependencies here, such as libraries or additional build options
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

set_target_properties(${PROJECT_NAME} PROPERTIES
    INSTALL_RPATH "/usr/local/lib;/usr/local/lib64"
    BUILD_WITH_INSTALL_RPATH TRUE
)
