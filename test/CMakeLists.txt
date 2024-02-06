add_executable(demoEasyFileStream test.cpp)
target_link_libraries(demoEasyFileStream libEasyFileStream)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test.txt ${CMAKE_CURRENT_BINARY_DIR}/test.txt COPYONLY)
add_test(NAME demoEasyFileStream COMMAND demoEasyFileStream)
