cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

project(Deamer_External VERSION 1.1.0
                  DESCRIPTION "Deamer CC output dependencies."
                  LANGUAGES CXX)

include(GNUInstallDirs)

set(CMAKE_BUILD_WITH_INSTALL_NAME_DIR ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "No build type selected, default to Debug")
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type (default Debug)" FORCE)
endif()

add_subdirectory(lib)

macro(option_enable OPTION_NAME OPTION_TEXT OPTION_DEFAULT)
	if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
		option(${OPTION_NAME} ${OPTION_TEXT} ${OPTION_DEFAULT})
	else()
		option(${OPTION_NAME} ${OPTION_TEXT} OFF)
	endif()
endmacro()

option_enable(DEAMER_EXTERNAL_ENABLE_DOXYGEN "Build the examples" OFF)
option_enable(DEAMER_EXTERNAL_BUILD_EXAMPLES "Build the examples" OFF)
option_enable(DEAMER_EXTERNAL_BUILD_TESTS "Build the tests" ON)

if(DEAMER_EXTERNAL_ENABLE_DOXYGEN)
	find_package(Doxygen)
	if(Doxygen_FOUND)
		add_subdirectory(docs)
	else()
		message(STATUS "Doxygen not found, not building docs")
	endif()
endif()

if(DEAMER_EXTERNAL_BUILD_TESTS)
	find_package(GTest)
	if (GTEST_FOUND)
		enable_testing()
		add_subdirectory(tests)
	else()
		enable_testing()
		include(GoogleTest)
		add_subdirectory(tests)
	endif()
endif()

# Package

include(CMakePackageConfigHelpers)

configure_package_config_file(${Deamer_External_SOURCE_DIR}/cmake/Deamer_ExternalConfig.cmake.in
  "${Deamer_External_BINARY_DIR}/Deamer_ExternalConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Deamer_External
)

write_basic_package_version_file(
	"Deamer_ExternalConfigVersion.cmake"
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion
)

install(FILES
	${Deamer_External_BINARY_DIR}/Deamer_ExternalConfig.cmake
	${Deamer_External_BINARY_DIR}/Deamer_ExternalConfigVersion.cmake
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Deamer_External
)