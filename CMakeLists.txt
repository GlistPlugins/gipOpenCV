cmake_minimum_required (VERSION 3.10.2)

##### PLUGIN NAME #####
set(pluginname gipOpenCV)


##### PLUGIN PATHS #####
set(PLUGIN_DIR ${PLUGINS_DIR}/${pluginname})
set(PLUGIN_LIBS_DIR ${PLUGIN_DIR}/libs)
set(PLUGIN_PREBUILTS_DIR ${PLUGIN_DIR}/prebuilts)


##### PLUGIN SOURCES #####
list(APPEND PLUGIN_SRCS
			${PLUGIN_DIR}/src/gipOpenCV.cpp
			${PLUGIN_DIR}/src/gGuiOpenCVCamera.cpp
)


##### PLUGIN HEADERS #####
list(APPEND PLUGIN_INCLUDES
			${PLUGIN_DIR}/src
)
if(EXISTS "${PLUGIN_LIBS_DIR}/include")
	list(APPEND PLUGIN_INCLUDES "${PLUGIN_LIBS_DIR}/include")
endif()
if(EXISTS "${PLUGIN_PREBUILTS_DIR}/include")
	list(APPEND PLUGIN_INCLUDES "${PLUGIN_PREBUILTS_DIR}/include")
endif()
if(EXISTS "${PLUGIN_PREBUILTS_DIR}/include/glib")
	list(APPEND PLUGIN_INCLUDES "${PLUGIN_PREBUILTS_DIR}/include/glib")
endif()
if(EXISTS "${PLUGIN_PREBUILTS_DIR}/include/harfbuzz")
	list(APPEND PLUGIN_INCLUDES "${PLUGIN_PREBUILTS_DIR}/include/harfbuzz")
endif()


##### PLUGIN DEPENDENCY LOCATIONS & DLL COPYING (IF ANY) #####
if(WIN32)
	# Automatically copy all prebuilt runtime DLLs to application binary directory
	file(GLOB PLUGIN_DLLS
		"${PLUGIN_LIBS_DIR}/bin/*.dll"
		"${PLUGIN_PREBUILTS_DIR}/bin/*.dll"
	)
	if(PLUGIN_DLLS)
		file(COPY ${PLUGIN_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
	endif()

	if(EXISTS "${PLUGIN_LIBS_DIR}/lib/win32")
		list(APPEND PLUGIN_LINKDIRS "${PLUGIN_LIBS_DIR}/lib/win32")
		list(APPEND PLUGIN_LIBDIRS "${PLUGIN_LIBS_DIR}/lib/win32")
	endif()
	if(EXISTS "${PLUGIN_LIBS_DIR}/bin")
		list(APPEND PLUGIN_LINKDIRS "${PLUGIN_LIBS_DIR}/bin")
	endif()

	if(EXISTS "${PLUGIN_PREBUILTS_DIR}/lib/win32")
		list(APPEND PLUGIN_LINKDIRS "${PLUGIN_PREBUILTS_DIR}/lib/win32")
		list(APPEND PLUGIN_LIBDIRS "${PLUGIN_PREBUILTS_DIR}/lib/win32")
	endif()
	if(EXISTS "${PLUGIN_PREBUILTS_DIR}/bin")
		list(APPEND PLUGIN_LINKDIRS "${PLUGIN_PREBUILTS_DIR}/bin")
	endif()
	if(EXISTS "${PLUGIN_PREBUILTS_DIR}/lib/gstreamer-1.0")
		list(APPEND PLUGIN_LINKDIRS "${PLUGIN_PREBUILTS_DIR}/lib/gstreamer-1.0")
		list(APPEND PLUGIN_LIBDIRS "${PLUGIN_PREBUILTS_DIR}/lib/gstreamer-1.0")
	endif()
elseif(ANDROID)
	# Android libs & includes here (${ANDROID_ABI} -> arm64-v8a, armeabi-v7a, x86_64)
	if(EXISTS "${PLUGIN_LIBS_DIR}/lib/android/${ANDROID_ABI}")
		list(APPEND PLUGIN_LINKDIRS "${PLUGIN_LIBS_DIR}/lib/android/${ANDROID_ABI}")
	endif()
	if(EXISTS "${PLUGIN_PREBUILTS_DIR}/lib/android/${ANDROID_ABI}")
		list(APPEND PLUGIN_LINKDIRS "${PLUGIN_PREBUILTS_DIR}/lib/android/${ANDROID_ABI}")
	endif()
	if(EXISTS "${PLUGIN_PREBUILTS_DIR}/lib/android/${ANDROID_ABI}/libopencv_java4.so")
		add_library(opencv_java4 SHARED IMPORTED)
		set_target_properties(opencv_java4 PROPERTIES IMPORTED_LOCATION
				"${PLUGIN_PREBUILTS_DIR}/lib/android/${ANDROID_ABI}/libopencv_java4.so")
	endif()
	if(EXISTS "${PLUGIN_PREBUILTS_DIR}/lib/android/${ANDROID_ABI}/libtesseract.so")
		add_library(tesseract SHARED IMPORTED)
		set_target_properties(tesseract PROPERTIES IMPORTED_LOCATION
				"${PLUGIN_PREBUILTS_DIR}/lib/android/${ANDROID_ABI}/libtesseract.so")
	endif()
	if(EXISTS "${PLUGIN_PREBUILTS_DIR}/lib/android/${ANDROID_ABI}/libleptonica.so")
		add_library(leptonica SHARED IMPORTED)
		set_target_properties(leptonica PROPERTIES IMPORTED_LOCATION
				"${PLUGIN_PREBUILTS_DIR}/lib/android/${ANDROID_ABI}/libleptonica.so")
	endif()
elseif(LINUX)
	# Linux libs & includes here
	list(APPEND PLUGIN_LINKDIRS
		glib-2.0
	)
	find_package(PkgConfig REQUIRED)
	pkg_check_modules(deps REQUIRED IMPORTED_TARGET glib-2.0)
	pkg_check_modules(Libopencv REQUIRED IMPORTED_TARGET opencv4)

	add_library(Lib_lept SHARED IMPORTED)
	set_target_properties(Lib_lept PROPERTIES IMPORTED_LOCATION
			/usr/lib/x86_64-linux-gnu/liblept.so)

	add_library(Lib_tesseract SHARED IMPORTED)
	set_target_properties(Lib_tesseract PROPERTIES IMPORTED_LOCATION
			/usr/lib/x86_64-linux-gnu/libtesseract.so)
elseif(APPLE)
	# macOS / iOS libs & includes here
	find_package(OpenCV REQUIRED)
	if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
		execute_process(
				COMMAND brew --prefix libarchive
				OUTPUT_VARIABLE LIBARCHIVE_PREFIX
				OUTPUT_STRIP_TRAILING_WHITESPACE
				COMMAND_ERROR_IS_FATAL ANY
		)
		set(LibArchive_INCLUDE_DIR "${LIBARCHIVE_PREFIX}/include")
	endif()
	find_package(LibArchive REQUIRED)
	find_package(PkgConfig REQUIRED)
	pkg_check_modules(glib REQUIRED IMPORTED_TARGET glib-2.0)
	pkg_check_modules(pango REQUIRED IMPORTED_TARGET pango)
	pkg_check_modules(tesseract REQUIRED IMPORTED_TARGET tesseract)
endif(WIN32)


##### PLUGIN DEPENDENCY LINKING (IF ANY) #####					
if(WIN32)
	list(APPEND PLUGIN_LINKLIBS
		leptonica
		tesseract
		archive
		cairo
		cairo-gobject
		cairo-script-interpreter
		pango-1.0
		pangocairo-1.0
		pangoft2-1.0
		pangowin32-1.0
		glib-2.0
		gio-2.0
		gmodule-2.0
		gobject-2.0
		gthread-2.0
		harfbuzz
		harfbuzz-gobject
		harfbuzz-icu
		z
		opencv_calib3d
		opencv_core
		opencv_dnn
		opencv_features2d
		opencv_flann
		opencv_gapi
		opencv_highgui
		opencv_imgcodecs
		opencv_imgproc
		opencv_ml
		opencv_objdetect
		opencv_photo
		opencv_stitching
		opencv_video
		opencv_videoio
		opencv_alphamat
		opencv_aruco
		opencv_bgsegm
		opencv_ccalib
		opencv_datasets
		opencv_dnn_objdetect
		opencv_dnn_superres
		opencv_dpm
		opencv_face
		opencv_freetype
		opencv_fuzzy
		opencv_hfs
		opencv_img_hash
		opencv_intensity_transform
		opencv_line_descriptor
		opencv_mcc
		opencv_optflow
		opencv_phase_unwrapping
		opencv_plot
		opencv_quality
		opencv_rapid
		opencv_reg
		opencv_rgbd
		opencv_saliency
		opencv_shape
		opencv_stereo
		opencv_structured_light
		opencv_superres
		opencv_surface_matching
		opencv_text
		opencv_tracking
		opencv_videostab
		opencv_wechat_qrcode
		opencv_xfeatures2d
		opencv_ximgproc
		opencv_xobjdetect
		opencv_xphoto
	)
elseif(ANDROID)
	list(APPEND PLUGIN_LINKLIBS
		opencv_java4
		tesseract
		leptonica
	)
elseif(LINUX)
	list(APPEND PLUGIN_LINKLIBS
		PkgConfig::deps
		PkgConfig::Libopencv
		Lib_lept
		Lib_tesseract
	)
elseif(APPLE)
	list(APPEND PLUGIN_LINKLIBS
		${OpenCV_LIBS}
		${LibArchive_LIBRARIES}
		PkgConfig::glib
		PkgConfig::pango
		PkgConfig::tesseract
	)
endif(WIN32)
