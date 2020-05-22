cmake_minimum_required(VERSION 3.1.0)

project(05)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_C_STANDARD 11)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(MyParser ${CMAKE_CURRENT_SOURCE_DIR}/ejemplo2.y ${CMAKE_CURRENT_BINARY_DIR}/parser.c)
FLEX_TARGET(MyScanner ${CMAKE_CURRENT_SOURCE_DIR}/ejemplo2.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.c)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
set(SRC 
    ${CMAKE_CURRENT_BINARY_DIR}/parser.c
    ${CMAKE_CURRENT_BINARY_DIR}/scanner.c
    )
add_executable(05
    ${SRC}
    ${BISON_MyParser_OUTPUTS}
    ${FLEX_MyScanner_OUTPUTS}
)
target_link_libraries(05 ${FLEX_LIBRARIES} ${BISON_LIBRARIES})
