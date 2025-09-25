#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ugv_sdk" for configuration "Release"
set_property(TARGET ugv_sdk APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ugv_sdk PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libugv_sdk.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS ugv_sdk )
list(APPEND _IMPORT_CHECK_FILES_FOR_ugv_sdk "${_IMPORT_PREFIX}/lib/libugv_sdk.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
