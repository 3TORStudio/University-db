project(StudentClassTest)

add_executable(${PROJECT_NAME} student-ut.cpp)

target_include_directories(${PROJECT_NAME}
PRIVATE
${CMAKE_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME} GTest::gtest_main University-lib)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})