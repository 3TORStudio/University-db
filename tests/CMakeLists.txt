project(UniversityDBTest)

include(FetchContent)
FetchContent_Declare(
   googletest
   GIT_REPOSITORY https://github.com/google/googletest
   GIT_TAG main)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

# subdirectories with tests
add_subdirectory(PersonTests)
add_subdirectory(AddressTest)
add_subdirectory(StudentTest)
add_subdirectory(EmployeeTest)
add_subdirectory(DataGeneratorTest)
add_subdirectory(UniversityTest)
    