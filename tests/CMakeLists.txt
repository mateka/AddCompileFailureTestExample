
add_executable(int_sum int_sum.cpp)
target_link_libraries(int_sum PRIVATE hlib::hlib)
add_test(NAME int_sum COMMAND int_sum)

get_target_property(HLIB_INCLUDES hlib::hlib INTERFACE_INCLUDE_DIRECTORIES)
add_compile_failure_test(
    NAME FailWithoutPlus
    SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/failing_withous_plus.cpp
    INCLUDE_DIRECTORIES ${HLIB_INCLUDES}
)
