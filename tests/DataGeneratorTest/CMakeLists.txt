project(DataGeneratorClassTest)

add_executable(${PROJECT_NAME} data-generator-ut.cpp)

target_link_libraries(${PROJECT_NAME} GTest::gtest_main University-lib)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})