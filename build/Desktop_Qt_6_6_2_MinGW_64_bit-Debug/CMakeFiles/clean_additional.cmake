# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Store_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Store_autogen.dir\\ParseCache.txt"
  "Store_autogen"
  )
endif()
