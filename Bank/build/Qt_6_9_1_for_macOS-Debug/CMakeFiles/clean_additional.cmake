# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Bank_autogen"
  "CMakeFiles/Bank_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Bank_autogen.dir/ParseCache.txt"
  )
endif()
