
add_library(stl-modules)
target_sources(stl-modules PUBLIC FILE_SET CXX_MODULES FILES
    stl.cpp
)

add_library(sudoku)
target_sources(sudoku PUBLIC FILE_SET CXX_MODULES FILES
    solver.cpp
    board.cpp
)
target_link_libraries(sudoku PRIVATE stl-modules)

add_executable(solver
	main.cpp
)
target_link_libraries(solver PRIVATE sudoku stl-modules)

