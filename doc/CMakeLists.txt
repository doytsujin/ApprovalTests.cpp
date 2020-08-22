# Find all the public source
file(GLOB_RECURSE
        APPROVAL_TESTS_PUBLIC_SOURCE
        CONFIGURE_DEPENDS
        ${PROJECT_SOURCE_DIR}/ApprovalTests/*.h
        ${PROJECT_SOURCE_DIR}/ApprovalTests/*.cpp)

file(GLOB_RECURSE
        APPROVAL_TESTS_ALL_TEST_FILES
        CONFIGURE_DEPENDS
        ${PROJECT_SOURCE_DIR}/tests/*.approved.*
        ${PROJECT_SOURCE_DIR}/tests/*.cpp
        ${PROJECT_SOURCE_DIR}/tests/*.h
        )

file(GLOB_RECURSE
        APPROVAL_TESTS_ALL_EXAMPLE_FILES
        CONFIGURE_DEPENDS
        ${PROJECT_SOURCE_DIR}/examples/*.approved.*
        ${PROJECT_SOURCE_DIR}/examples/*.cpp
        ${PROJECT_SOURCE_DIR}/examples/*.h
        )

# Find all the .md files in doc/ directory
# APPROVAL_TESTS_ALL_DOC_SOURCE_MD_FILES will contain all .md files that mdsnippets should update
file(GLOB_RECURSE
        APPROVAL_TESTS_GEN_DOC_MD_FILES
        CONFIGURE_DEPENDS
        ${PROJECT_SOURCE_DIR}/doc/*.md)

list(FILTER APPROVAL_TESTS_GEN_DOC_MD_FILES EXCLUDE REGEX ".*sphinx.*")
list(FILTER APPROVAL_TESTS_GEN_DOC_MD_FILES EXCLUDE REGEX ".*.include.md")

foreach (loop_var ${APPROVAL_TESTS_GEN_DOC_MD_FILES})
    message(info " value = ${loop_var}")
endforeach (loop_var)

add_subdirectory(doxygen)
add_subdirectory(run_mdsnippets)
add_subdirectory(sphinx)
