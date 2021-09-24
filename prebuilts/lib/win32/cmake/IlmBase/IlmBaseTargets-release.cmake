#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "IlmBase::Half" for configuration "Release"
set_property(TARGET IlmBase::Half APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(IlmBase::Half PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libHalf.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libHalf-2_5.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS IlmBase::Half )
list(APPEND _IMPORT_CHECK_FILES_FOR_IlmBase::Half "${_IMPORT_PREFIX}/lib/libHalf.dll.a" "${_IMPORT_PREFIX}/bin/libHalf-2_5.dll" )

# Import target "IlmBase::Iex" for configuration "Release"
set_property(TARGET IlmBase::Iex APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(IlmBase::Iex PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libIex.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libIex-2_5.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS IlmBase::Iex )
list(APPEND _IMPORT_CHECK_FILES_FOR_IlmBase::Iex "${_IMPORT_PREFIX}/lib/libIex.dll.a" "${_IMPORT_PREFIX}/bin/libIex-2_5.dll" )

# Import target "IlmBase::IexMath" for configuration "Release"
set_property(TARGET IlmBase::IexMath APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(IlmBase::IexMath PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libIexMath.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libIexMath-2_5.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS IlmBase::IexMath )
list(APPEND _IMPORT_CHECK_FILES_FOR_IlmBase::IexMath "${_IMPORT_PREFIX}/lib/libIexMath.dll.a" "${_IMPORT_PREFIX}/bin/libIexMath-2_5.dll" )

# Import target "IlmBase::Imath" for configuration "Release"
set_property(TARGET IlmBase::Imath APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(IlmBase::Imath PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libImath.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libImath-2_5.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS IlmBase::Imath )
list(APPEND _IMPORT_CHECK_FILES_FOR_IlmBase::Imath "${_IMPORT_PREFIX}/lib/libImath.dll.a" "${_IMPORT_PREFIX}/bin/libImath-2_5.dll" )

# Import target "IlmBase::IlmThread" for configuration "Release"
set_property(TARGET IlmBase::IlmThread APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(IlmBase::IlmThread PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libIlmThread.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libIlmThread-2_5.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS IlmBase::IlmThread )
list(APPEND _IMPORT_CHECK_FILES_FOR_IlmBase::IlmThread "${_IMPORT_PREFIX}/lib/libIlmThread.dll.a" "${_IMPORT_PREFIX}/bin/libIlmThread-2_5.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
