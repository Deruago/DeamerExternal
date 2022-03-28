set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(INSTALL_GTEST off)
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

set_target_properties(gtest PROPERTIES FOLDER Deamer_External/extern)
set_target_properties(gtest_main PROPERTIES FOLDER Deamer_External/extern)
set_target_properties(gmock PROPERTIES FOLDER Deamer_External/extern)
set_target_properties(gmock_main PROPERTIES FOLDER Deamer_External/extern)

macro(package_add_test TESTNAME)
    # create an exectuable in which the tests will be stored
    add_executable(${TESTNAME} ${ARGN})

    # link the Google test infrastructure, mocking library
    target_link_libraries(${TESTNAME} PRIVATE gtest gmock gtest_main)
    target_link_libraries(${TESTNAME} PRIVATE External)
	target_include_directories(${TESTNAME} PRIVATE ${Deamer_External_SOURCE_DIR}/include/ ${Deamer_External_SOURCE_DIR}/extern/googletest)

    gtest_discover_tests(${TESTNAME}
        WORKING_DIRECTORY ${PROJECT_DIR}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
    )
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
	
	target_compile_features(${TESTNAME} PRIVATE cxx_std_17)
endmacro()

file(GLOB_RECURSE UNIT_TESTS *.cpp)
package_add_test(deamer_external_unit_tests ${UNIT_TESTS})