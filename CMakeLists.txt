cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(testhlib VERSION 0.0.0.1 LANGUAGES CXX)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

include(AddCompileFailureTest/AddCompileFailureTest)

enable_testing()

add_library(hlib INTERFACE)
target_include_directories(
    hlib
    INTERFACE
        $<BUILD_INTERFACE:${testhlib_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

add_library(hlib::hlib ALIAS hlib)
install(
    TARGETS hlib EXPORT hlibTargets
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)
install(DIRECTORY include DESTINATION include)
install(
    EXPORT hlibTargets
    FILE hlibTargets.cmake
    NAMESPACE hlib::
    DESTINATION lib/cmake/hlib
)

add_subdirectory(tests)
