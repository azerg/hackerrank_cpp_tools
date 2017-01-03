set (test_executable_name test)

add_executable (${test_executable_name} testMain.cpp PointsTest.cpp)

include_directories ("${PROJECT_SOURCE_DIR}" "${GTEST_FOLDER}/include" "${PROJECT_SOURCE_DIR}/util")

if (WIN32)
    message ("---linking windows libs")
	target_link_libraries (${test_executable_name} optimized ${GTEST_FOLDER}/msvc/gtest/Release/gtest.lib)
	target_link_libraries (${test_executable_name} debug ${GTEST_FOLDER}/msvc/gtest/Debug/gtestd.lib)
	
	########################################################################
	# replacing MD with MT, MDd with MTd
    set(variables CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE)
	foreach(variable ${variables})
		if(${variable} MATCHES "/MD")
		  string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
		elseif(${variable} MATCHES "/MDd")
		  string(REGEX REPLACE "/MDd" "/MTd" ${variable} "${${variable}}")
		endif()		
	endforeach()
	########################################################################
else()
	message ("---linking linux gtest libs")
	target_link_libraries (${test_executable_name} ${GTEST_FOLDER}/cmake/libgtest.so)
endif()