cmake_minimum_required(VERSION 3.10)

# ===============================================

enable_testing()

# Set this source directory as the tree root for project.
set(ae2f_ProjRoot ${CMAKE_CURRENT_SOURCE_DIR} CACHE STRING "Tree root for project")
set(ae2f_BinRoot ${CMAKE_CURRENT_BINARY_DIR} CACHE STRING "Tree root for project")
set(ae2f_submod  .submod CACHE STRING "Relative path to submodule (subdirectory)")
set(ae2f_Preproc_Wh ${ae2f_ProjRoot}/${ae2f_submod}/ae2f/Preproc)

# Execute git to fetch CoreScript when repository does not exist
if(NOT EXISTS ${ae2f_Preproc_Wh})
	execute_process(
		COMMAND git clone https://codeberg.org/ae2f/Preproc
		${ae2f_Preproc_Wh}
		)
endif()

# add subdirectory
if(NOT TARGET ae2f::Preproc)
	add_subdirectory(${ae2f_Preproc_Wh} ${ae2f_submod}/ae2f/Preproc)
endif()

# ===============================================

project(Pat VERSION 0)
ae2f_CoreLibFetchX(ae2f Core main)

ae2f_Macro_init(1 30 100)
ae2f_Macro_Lib_V2_REL(
	ae2f Pat INTERFACE 
	${PROJECT_SOURCE_DIR}/src/ "NOTHING" 
	${PROJECT_SOURCE_DIR}/src/ "*.c" 
	inc/ae2f/pat/ ".auto.h"
	${PROJECT_SOURCE_DIR}/cfg/pat.cmake.in
	inc ON
	)

target_link_libraries(ae2f-Pat INTERFACE ae2f::Core)
ae2f_CoreTestTentVerbose(ae2f-Pat test)
