#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "double-conversion::double-conversion" for configuration "Release"
set_property(TARGET double-conversion::double-conversion APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(double-conversion::double-conversion PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libdouble-conversion.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libdouble-conversion.dll"
  )

list(APPEND _cmake_import_check_targets double-conversion::double-conversion )
list(APPEND _cmake_import_check_files_for_double-conversion::double-conversion "${_IMPORT_PREFIX}/lib/libdouble-conversion.dll.a" "${_IMPORT_PREFIX}/bin/libdouble-conversion.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
