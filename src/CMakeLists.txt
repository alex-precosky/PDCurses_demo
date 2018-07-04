cmake_minimum_required(VERSION 3.2)
project(PdCursesDemo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(SOURCE_FILES main.cpp)

include_directories(include)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
install(TARGETS PdCursesDemo DESTINATION bin)

