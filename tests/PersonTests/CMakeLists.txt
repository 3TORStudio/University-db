project(PersonClassTest)

add_executable(${PROJECT_NAME} person-ut.cpp)

target_link_libraries(${PROJECT_NAME} GTest::gtest_main University-lib)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})