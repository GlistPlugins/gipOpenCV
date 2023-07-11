#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "md4c::md4c" for configuration "Release"
set_property(TARGET md4c::md4c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(md4c::md4c PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libmd4c.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libmd4c.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS md4c::md4c )
list(APPEND _IMPORT_CHECK_FILES_FOR_md4c::md4c "${_IMPORT_PREFIX}/lib/libmd4c.dll.a" "${_IMPORT_PREFIX}/bin/libmd4c.dll" )

# Import target "md4c::md4c-html" for configuration "Release"
set_property(TARGET md4c::md4c-html APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(md4c::md4c-html PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libmd4c-html.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libmd4c-html.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS md4c::md4c-html )
list(APPEND _IMPORT_CHECK_FILES_FOR_md4c::md4c-html "${_IMPORT_PREFIX}/lib/libmd4c-html.dll.a" "${_IMPORT_PREFIX}/bin/libmd4c-html.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
