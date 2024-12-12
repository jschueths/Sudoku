cmake_minimum_required(VERSION 3.28)

project(sudoku_solver
    VERSION 0.1.0
    DESCRIPTION ""
    HOMEPAGE_URL "https://github.com/jschueths/Sudoku"
    LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake/Modules)
include(project-api)

# Add project sources
add_subdirectory(src)

# Add project tests
#add_subdirectory(test)

