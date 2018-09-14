cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
include(cmake/limix.cmake)
limix_initialise()
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C)
limix_config()

set(CMAKE_C_STANDARD 11)
if (NOT WIN32)
    set(LIMIX_CMAKE_ENVIRONMENT FALSE)
endif()

limix_process_default_dirs()

limix_require_cmath_library()
limix_add_library(${PROJECT_NAME} ${PROJECT_VERSION} "${SOURCES}" "${HEADERS}"
                  "${LIMIX_CMAKE_CMATH_LIBRARY}")

add_subdirectory(test)
