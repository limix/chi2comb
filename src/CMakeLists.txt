function(define_sources BASE_DIR _SOURCES)

    list(APPEND REL_SOURCES chi2comb.c)
    limix_convert_rel_to_full(FULL_SOURCES ${BASE_DIR} "${REL_SOURCES}")
    set(${_SOURCES} ${FULL_SOURCES} PARENT_SCOPE)

endfunction(define_sources)
