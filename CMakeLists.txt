cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

project(University)

set(SRC_LIST
    src/address.cpp
    src/data-generator.cpp
    src/menu.cpp
    src/person.cpp
    src/student.cpp
    src/employee.cpp
    src/university.cpp
)

add_library(${PROJECT_NAME}-lib STATIC ${SRC_LIST})

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)


target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wpedantic -Wextra)

enable_testing()

add_subdirectory(tests)

# include(FetchContent)
# FetchContent_Declare(
#     googletest
#     URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#     )
    
#     set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#     FetchContent_MakeAvailable(googletest)
    

#     add_executable(${PROJECT_NAME}-ut tests/main-ut.cpp)
#     target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib GTest::gtest_main)
    
#     include(GoogleTest)
#     gtest_discover_tests(${PROJECT_NAME}-ut)
    
    
    