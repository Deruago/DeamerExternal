file(GLOB_RECURSE HEADER_LIST "${Deamer_External_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE SOURCE_LIST "${Deamer_External_SOURCE_DIR}/lib/*.cpp")

add_library(External STATIC ${HEADER_LIST})
target_sources(External PRIVATE ${SOURCE_LIST})

target_include_directories(External PUBLIC 
    $<BUILD_INTERFACE:${Deamer_External_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_features(External PUBLIC cxx_std_17)
set_target_properties(External PROPERTIES LINKER_LANGUAGE CXX POSITION_INDEPENDENT_CODE ON)

add_library(Deamer::External ALIAS External)

# Install Targets

install(TARGETS External
    EXPORT Deamer_External_Exports
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}/Deamer_External"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}/Deamer_External"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}/Deamer_External"
    )

export(TARGETS
	External
    NAMESPACE Deamer::
	FILE "${CMAKE_CURRENT_BINARY_DIR}/Deamer_External_Exports.cmake"
)

install(EXPORT
	Deamer_External_Exports
    NAMESPACE Deamer::
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/Deamer_External"
)

# Install Headers

install(DIRECTORY ${Deamer_External_SOURCE_DIR}/include/Deamer
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING
    PATTERN "*.h"
    PATTERN "LICENSE"
    )
