# CMakeLists.txt in cpp-easy-file-stream

cmake_minimum_required(VERSION 3.12)
project(easyFileStream VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Option to enable/disable the test executable
option(BUILD_TEST_EXECUTABLE "Build the test executable" OFF)

# Add header files to the library target
add_library(libEasyFileStream INTERFACE)
target_include_directories(libEasyFileStream INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Set compiler optimization flags
target_compile_options(libEasyFileStream INTERFACE -O2)

enable_testing()
add_subdirectory(test)

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

