cmake_minimum_required(VERSION 3.1)
project(pool-2012 LANGUAGES C)

function(add_my_executable SOURCE)
    get_filename_component(TARGET ${SOURCE} NAME_WE)
    add_executable(${TARGET} ${SOURCE})
    target_compile_definitions(${TARGET} PRIVATE $<UPPER_CASE:${TARGET}>)
    set_target_properties(${TARGET} PROPERTIES C_EXTENSIONS OFF COMPILE_OPTIONS -UNDEBUG)
    if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
        target_compile_options(${TARGET} PRIVATE -ansi -pedantic-errors -Wall -Wextra -Werror)
    elseif("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
        target_compile_options(${TARGET}
            PRIVATE
                $<$<NOT:$<STREQUAL:${CMAKE_C_SIMULATE_ID},MSVC>>:-ansi -pedantic-errors>
                -Weverything -Wno-deprecated-declarations
        )
    elseif("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
        target_compile_options(${TARGET}
            PRIVATE
                /wd4146 # negative unsigned still unsigned
                /wd4996 # write, read, ... not POSIX
        )
    endif()
endfunction()

file(GLOB SOURCES *.c)
foreach(SRC ${SOURCES})
    add_my_executable(${SRC})
endforeach()
