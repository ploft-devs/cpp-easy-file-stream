# CMakeLists.txt

cmake_minimum_required(VERSION 3.12)
project(libEasyFileStream VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add header files to the library target
add_library(libEasyFileStream INTERFACE)
target_include_directories(libEasyFileStream INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Set compiler optimization flags
target_compile_options(libEasyFileStream INTERFACE -O2)

# Add executable for testing
add_executable(testExecutable test/test.cpp)
target_link_libraries(testExecutable PRIVATE libEasyFileStream)

# Copy test.txt to the binary directory during build
configure_file(test/test.txt ${CMAKE_CURRENT_BINARY_DIR}/bin/test.txt COPYONLY)

# Set the output directory for the test executable
set_target_properties(testExecutable PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
)

# You can add additional compiler options or flags here if needed

# Optional: Install the library
install(TARGETS libEasyFileStream
    EXPORT libEasyFileStreamTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)

# Optional: Export the library targets
export(TARGETS libEasyFileStream FILE libEasyFileStreamTargets.cmake)

# Optional: Create a package configuration file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    libEasyFileStreamConfigVersion.cmake
    VERSION 1.0.0
    COMPATIBILITY AnyNewerVersion
)

install(FILES libEasyFileStreamConfig.cmake ${CMAKE_CURRENT_BINARY_DIR}/libEasyFileStreamConfigVersion.cmake
    DESTINATION lib/cmake/libEasyFileStream
)

