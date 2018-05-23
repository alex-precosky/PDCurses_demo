cmake_minimum_required(VERSION 3.2)
project(MyProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(SOURCE_FILES main.cpp)

include_directories(include)

add_executable(MyProject ${SOURCE_FILES})

target_link_libraries(MyProject ${CONAN_LIBS})
install(TARGETS MyProject DESTINATION bin)

