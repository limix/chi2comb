function(chi2comb_add_test name)
    set(target test_${name})
    add_executable(${target} ${name}.c)
    target_link_libraries(${target} PRIVATE CHI2COMB::chi2comb)
    target_compile_options(${target} PRIVATE ${WARNING_FLAGS})
    target_compile_definitions(${target} PRIVATE $<$<BOOL:${WIN32}>:_CRT_SECURE_NO_WARNINGS>)
    target_compile_definitions(${target} PRIVATE $<$<BOOL:${WIN32}>:_CRT_NONSTDC_NO_DEPRECATE>)

    add_test(NAME ${name} COMMAND ${target} -E environment
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

    add_custom_command(TARGET ${target} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_CURRENT_BINARY_DIR}/${name}.tmp"
    )

    # Ugly hacky to make the tests work on Windows.
    file(TO_CMAKE_PATH "$ENV{PATH}" PATH)
    list(APPEND PATH $<TARGET_FILE_DIR:CHI2COMB::chi2comb>)
    string(REPLACE ";" "\\;" PATH "${PATH}")
    set_tests_properties(${name} PROPERTIES ENVIRONMENT "PATH=${PATH}" )
endfunction()


chi2comb_add_test(chi2comb)
