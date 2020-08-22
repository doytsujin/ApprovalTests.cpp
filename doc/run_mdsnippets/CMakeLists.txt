find_program(mdsnippets_FOUND mdsnippets)
if (NOT mdsnippets_FOUND)
    message(STATUS "mdsnippets not found: Will not regenerate markdown files")
    return()
endif ()

# Depend on an intentionally missing file, to force
# mdsnippets to always run.
# This is because mdsnippets overwrites .md output
# files, when working in-place, and so there is no way
# for us to detect whether or not the .md files are
# out-of-date and need to be updated.
set(NON_EXISTENT_TARGET "_non_existent_file.md")

add_custom_command(OUTPUT ${NON_EXISTENT_TARGET}
        COMMAND mdsnippets
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        )

# Nice named target so we can run the job easily
add_custom_target(RunMdsnippets DEPENDS ${NON_EXISTENT_TARGET})
