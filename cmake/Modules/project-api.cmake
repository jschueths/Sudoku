include(CommonOptions)

function(add_project_library name)
    # Create target
    add_library(${name})
    add_library(${PROJECT_NAME}::${name} ALIAS ${name})
endfunction()
