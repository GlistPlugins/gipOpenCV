#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Imath::Imath" for configuration "Release"
set_property(TARGET Imath::Imath APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Imath::Imath PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libImath.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libImath-3_1.dll"
  )

list(APPEND _cmake_import_check_targets Imath::Imath )
list(APPEND _cmake_import_check_files_for_Imath::Imath "${_IMPORT_PREFIX}/lib/libImath.dll.a" "${_IMPORT_PREFIX}/bin/libImath-3_1.dll" )

# Import target "Imath::PyImath_Python3_10" for configuration "Release"
set_property(TARGET Imath::PyImath_Python3_10 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Imath::PyImath_Python3_10 PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libPyImath_Python3_10.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Python3::Python"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libPyImath_Python3_10-3_1.dll"
  )

list(APPEND _cmake_import_check_targets Imath::PyImath_Python3_10 )
list(APPEND _cmake_import_check_files_for_Imath::PyImath_Python3_10 "${_IMPORT_PREFIX}/lib/libPyImath_Python3_10.dll.a" "${_IMPORT_PREFIX}/bin/libPyImath_Python3_10-3_1.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
