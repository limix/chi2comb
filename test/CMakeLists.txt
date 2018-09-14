include_directories("${TEST_SOURCE_DIR}/src")

if (NOT WIN32)
    limix_add_test(chi2comb ${PROJECT_NAME} "chi2comb.c;acutest.h")
endif()