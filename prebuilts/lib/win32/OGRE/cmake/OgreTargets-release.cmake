#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "OgreMain" for configuration "Release"
set_property(TARGET OgreMain APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OgreMain PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libOgreMain.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/OgreMain.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS OgreMain )
list(APPEND _IMPORT_CHECK_FILES_FOR_OgreMain "${_IMPORT_PREFIX}/lib/libOgreMain.dll.a" "${_IMPORT_PREFIX}/bin/OgreMain.dll" )

# Import target "OgreGLSupport" for configuration "Release"
set_property(TARGET OgreGLSupport APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OgreGLSupport PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/OgreGLSupport.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS OgreGLSupport )
list(APPEND _IMPORT_CHECK_FILES_FOR_OgreGLSupport "${_IMPORT_PREFIX}/lib/OgreGLSupport.a" )

# Import target "OgreBites" for configuration "Release"
set_property(TARGET OgreBites APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OgreBites PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libOgreBites.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "SDL2::SDL2"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/OgreBites.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS OgreBites )
list(APPEND _IMPORT_CHECK_FILES_FOR_OgreBites "${_IMPORT_PREFIX}/lib/libOgreBites.dll.a" "${_IMPORT_PREFIX}/bin/OgreBites.dll" )

# Import target "OgrePaging" for configuration "Release"
set_property(TARGET OgrePaging APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OgrePaging PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libOgrePaging.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/OgrePaging.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS OgrePaging )
list(APPEND _IMPORT_CHECK_FILES_FOR_OgrePaging "${_IMPORT_PREFIX}/lib/libOgrePaging.dll.a" "${_IMPORT_PREFIX}/bin/OgrePaging.dll" )

# Import target "OgreMeshLodGenerator" for configuration "Release"
set_property(TARGET OgreMeshLodGenerator APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OgreMeshLodGenerator PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libOgreMeshLodGenerator.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/OgreMeshLodGenerator.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS OgreMeshLodGenerator )
list(APPEND _IMPORT_CHECK_FILES_FOR_OgreMeshLodGenerator "${_IMPORT_PREFIX}/lib/libOgreMeshLodGenerator.dll.a" "${_IMPORT_PREFIX}/bin/OgreMeshLodGenerator.dll" )

# Import target "OgreProperty" for configuration "Release"
set_property(TARGET OgreProperty APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OgreProperty PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libOgreProperty.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/OgreProperty.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS OgreProperty )
list(APPEND _IMPORT_CHECK_FILES_FOR_OgreProperty "${_IMPORT_PREFIX}/lib/libOgreProperty.dll.a" "${_IMPORT_PREFIX}/bin/OgreProperty.dll" )

# Import target "OgreTerrain" for configuration "Release"
set_property(TARGET OgreTerrain APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OgreTerrain PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libOgreTerrain.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/OgreTerrain.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS OgreTerrain )
list(APPEND _IMPORT_CHECK_FILES_FOR_OgreTerrain "${_IMPORT_PREFIX}/lib/libOgreTerrain.dll.a" "${_IMPORT_PREFIX}/bin/OgreTerrain.dll" )

# Import target "OgreRTShaderSystem" for configuration "Release"
set_property(TARGET OgreRTShaderSystem APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OgreRTShaderSystem PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libOgreRTShaderSystem.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/OgreRTShaderSystem.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS OgreRTShaderSystem )
list(APPEND _IMPORT_CHECK_FILES_FOR_OgreRTShaderSystem "${_IMPORT_PREFIX}/lib/libOgreRTShaderSystem.dll.a" "${_IMPORT_PREFIX}/bin/OgreRTShaderSystem.dll" )

# Import target "OgreVolume" for configuration "Release"
set_property(TARGET OgreVolume APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OgreVolume PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libOgreVolume.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/OgreVolume.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS OgreVolume )
list(APPEND _IMPORT_CHECK_FILES_FOR_OgreVolume "${_IMPORT_PREFIX}/lib/libOgreVolume.dll.a" "${_IMPORT_PREFIX}/bin/OgreVolume.dll" )

# Import target "OgreOverlay" for configuration "Release"
set_property(TARGET OgreOverlay APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OgreOverlay PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libOgreOverlay.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/OgreOverlay.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS OgreOverlay )
list(APPEND _IMPORT_CHECK_FILES_FOR_OgreOverlay "${_IMPORT_PREFIX}/lib/libOgreOverlay.dll.a" "${_IMPORT_PREFIX}/bin/OgreOverlay.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
