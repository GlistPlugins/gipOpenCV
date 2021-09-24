#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gflags_shared" for configuration "Release"
set_property(TARGET gflags_shared APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gflags_shared PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libgflags.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libgflags.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS gflags_shared )
list(APPEND _IMPORT_CHECK_FILES_FOR_gflags_shared "${_IMPORT_PREFIX}/lib/libgflags.dll.a" "${_IMPORT_PREFIX}/bin/libgflags.dll" )

# Import target "gflags_nothreads_shared" for configuration "Release"
set_property(TARGET gflags_nothreads_shared APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gflags_nothreads_shared PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libgflags_nothreads.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libgflags_nothreads.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS gflags_nothreads_shared )
list(APPEND _IMPORT_CHECK_FILES_FOR_gflags_nothreads_shared "${_IMPORT_PREFIX}/lib/libgflags_nothreads.dll.a" "${_IMPORT_PREFIX}/bin/libgflags_nothreads.dll" )

# Import target "gflags_static" for configuration "Release"
set_property(TARGET gflags_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gflags_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libgflags_static.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS gflags_static )
list(APPEND _IMPORT_CHECK_FILES_FOR_gflags_static "${_IMPORT_PREFIX}/lib/libgflags_static.a" )

# Import target "gflags_nothreads_static" for configuration "Release"
set_property(TARGET gflags_nothreads_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gflags_nothreads_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libgflags_nothreads_static.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS gflags_nothreads_static )
list(APPEND _IMPORT_CHECK_FILES_FOR_gflags_nothreads_static "${_IMPORT_PREFIX}/lib/libgflags_nothreads_static.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
