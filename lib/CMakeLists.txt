file(GLOB_RECURSE HEADER_LIST "${Deamer_External_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE SOURCE_LIST "${Deamer_External_SOURCE_DIR}/lib/*.cpp")

add_library(Deamer_External STATIC ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(Deamer_External PUBLIC 
    $<BUILD_INTERFACE:${Deamer_External_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/>
)

target_compile_features(Deamer_External PUBLIC cxx_std_17)
set_target_properties(Deamer_External PROPERTIES LINKER_LANGUAGE CXX POSITION_INDEPENDENT_CODE ON)

add_library(Deamer_External_Shared SHARED ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(Deamer_External_Shared PUBLIC 
    $<BUILD_INTERFACE:${Deamer_External_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/>
)

target_compile_features(Deamer_External_Shared PUBLIC cxx_std_17)
set_target_properties(Deamer_External_Shared PROPERTIES LINKER_LANGUAGE CXX)

install(TARGETS Deamer_External
    EXPORT Deamer_ExternalConfig
    DESTINATION lib/Deamer_External
    )