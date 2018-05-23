cmake_minimum_required(VERSION 3.10)

include(GoogleTest)

project(test_runner)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

set(SOURCE_FILES sample1_unittest.cpp)

#add_subdirectory(lib/googletest)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

include_directories(lib/googletest/googletest/include)

enable_testing()

add_executable(test_runner ${SOURCE_FILES})
target_link_libraries(test_runner CONAN_PKG::gtest)

add_test(NAME that-test-I-made COMMAND test_runner)

install(TARGETS test_runner DESTINATION bin)
