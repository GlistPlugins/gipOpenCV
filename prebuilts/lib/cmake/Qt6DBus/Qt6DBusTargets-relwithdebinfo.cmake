#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::DBus" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::DBus APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Qt6::DBus PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libQt6DBus.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "dbus-1"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/Qt6DBus.dll"
  )

list(APPEND _cmake_import_check_targets Qt6::DBus )
list(APPEND _cmake_import_check_files_for_Qt6::DBus "${_IMPORT_PREFIX}/lib/libQt6DBus.dll.a" "${_IMPORT_PREFIX}/bin/Qt6DBus.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
