cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(chi2comb VERSION 0.0.4 LANGUAGES C)
set(PROJECT_DESCRIPTION "CDF of independent chi-square random variables and a standard Normal distribution.")

# Generate compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
# Set RPATH only if it's not a system directory
list(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
if("${isSystemDir}" STREQUAL "-1")
    set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
endif()

# merge request fix: https://gitlab.kitware.com/cmake/cmake/-/merge_requests/1799
if(CMAKE_VERSION VERSION_GREATER 3.12.0)
    # Hide things by default
    set(CMAKE_C_VISIBILITY_PRESET hidden)
    set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)
endif()

add_library(chi2comb
    src/chi2comb.c
)
add_library(CHI2COMB::chi2comb ALIAS chi2comb)

if(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    set(WARNING_FLAGS /W3)
else()
    set(WARNING_FLAGS -Wall -Wextra -pedantic -Wstrict-prototypes -Wshadow
        -Wconversion -Wmissing-prototypes -Wno-unused-parameter -Wsign-conversion
    )
endif()

include(GenerateExportHeader)
generate_export_header(chi2comb BASE_NAME CHI2COMB
    INCLUDE_GUARD_NAME CHI2COMB_EXPORT_H
    EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/chi2comb/export.h)

target_include_directories(chi2comb
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
set_target_properties(chi2comb PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(chi2comb PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})
set_target_properties(chi2comb PROPERTIES C_STANDARD 99)
target_compile_definitions(chi2comb PRIVATE $<$<BOOL:${WIN32}>:_CRT_SECURE_NO_WARNINGS>)
target_compile_definitions(chi2comb PRIVATE $<$<BOOL:${WIN32}>:_CRT_NONSTDC_NO_DEPRECATE>)

install(TARGETS chi2comb EXPORT chi2comb-targets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/chi2comb/export.h
    DESTINATION include/chi2comb
)
install(EXPORT chi2comb-targets
    FILE chi2comb-targets.cmake
    NAMESPACE CHI2COMB::
    DESTINATION lib/cmake/chi2comb
)
include(CMakePackageConfigHelpers)
configure_package_config_file(chi2comb-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/chi2comb-config.cmake
    INSTALL_DESTINATION lib/cmake/chi2comb
    NO_SET_AND_CHECK_MACRO
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/chi2comb-config.cmake
    DESTINATION lib/cmake/chi2comb
)

enable_testing()
add_subdirectory(test)
