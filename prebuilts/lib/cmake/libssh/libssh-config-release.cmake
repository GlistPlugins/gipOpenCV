#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ssh" for configuration "Release"
set_property(TARGET ssh APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ssh PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libssh.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libssh.dll"
  )

list(APPEND _cmake_import_check_targets ssh )
list(APPEND _cmake_import_check_files_for_ssh "${_IMPORT_PREFIX}/lib/libssh.dll.a" "${_IMPORT_PREFIX}/bin/libssh.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
