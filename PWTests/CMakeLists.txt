include(GoogleTest)

find_package(GTest)

add_executable(test_project main.cpp PWTests.cpp)
if(ENABLE_CODE_COVERAGE)
    message("Preparing code coverage")

    if(CI_CD_COVERAGE)
    setup_target_for_coverage_lcov(NAME ctest_coverage
    EXECUTABLE  ctest -j ${PROCESSOR_COUNT}
    DEPENDENCIES test_project 
    BASE_DIRECTORY ../)
    else()
    setup_target_for_coverage_gcovr_html(NAME ctest_coverage
    EXECUTABLE  ctest -j ${PROCESSOR_COUNT}
    DEPENDENCIES test_project 
    BASE_DIRECTORY ../)
    target_link_libraries(test_project gcov)
    endif()
endif()
target_link_libraries(test_project PW::SERVER GTest::gtest)
gtest_discover_tests(test_project)

add_custom_target(unit_tests 
COMMAND
ctest -V
DEPENDS test_project)