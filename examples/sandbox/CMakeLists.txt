cmake_minimum_required(VERSION 3.28)

project(sandbox)

file(GLOB_RECURSE SOURCE_FILES src/*.hpp src/*.cpp)

add_executable(sandbox ${SOURCE_FILES})

target_link_libraries(sandbox PRIVATE mellohi)

add_custom_target(remove_sandbox_assets ALL
        COMMAND ${CMAKE_COMMAND} -E remove_directory
        ${CMAKE_BINARY_DIR}/assets/sandbox
)
add_custom_target(copy_sandbox_assets ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/sandbox
        ${CMAKE_BINARY_DIR}/assets/sandbox
)
add_dependencies(copy_sandbox_assets remove_sandbox_assets)
add_dependencies(sandbox copy_sandbox_assets)
