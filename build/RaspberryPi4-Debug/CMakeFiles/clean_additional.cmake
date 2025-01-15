# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/SoundPlayerViaBluetooth_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/SoundPlayerViaBluetooth_autogen.dir/ParseCache.txt"
  "SoundPlayerViaBluetooth_autogen"
  )
endif()
