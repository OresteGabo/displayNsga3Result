# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/displayNsga3Result_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/displayNsga3Result_autogen.dir/ParseCache.txt"
  "displayNsga3Result_autogen"
  )
endif()
