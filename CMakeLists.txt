cmake_minimum_required (VERSION 3.10.2)

##### PLUGIN NAME #####
set(pluginname gipOpenCV)


##### PLUGIN PATHS #####
set(PLUGIN_DIR ${PLUGINS_DIR}/${pluginname})
set(PLUGIN_LIBS_DIR ${PLUGIN_DIR}/libs)
set(PLUGIN_PREBUILTS_DIR ${PLUGIN_DIR}/prebuilts)


##### EXTRACT COMPRESSED PREBUILT LIBRARIES IF MISSING #####
if(EXISTS "${PLUGIN_PREBUILTS_DIR}")
	file(GLOB_RECURSE COMPRESSED_PREBUILTS "${PLUGIN_PREBUILTS_DIR}/*.a.zip")
	foreach(ZIP_PATH ${COMPRESSED_PREBUILTS})
		get_filename_component(ZIP_DIR "${ZIP_PATH}" DIRECTORY)
		get_filename_component(ZIP_NAME "${ZIP_PATH}" NAME)
		string(REGEX REPLACE "\\.zip$" "" EXTRACTED_NAME "${ZIP_NAME}")
		set(TARGET_LIB_PATH "${ZIP_DIR}/${EXTRACTED_NAME}")

		if(NOT EXISTS "${TARGET_LIB_PATH}")
			message(STATUS "[gipOpenCV] Extracting ${ZIP_NAME}...")
			execute_process(
				COMMAND ${CMAKE_COMMAND} -E tar xf "${ZIP_PATH}"
				WORKING_DIRECTORY "${ZIP_DIR}"
				RESULT_VARIABLE EXTRACT_RESULT
			)
			if(NOT EXTRACT_RESULT EQUAL 0)
				message(WARNING "[gipOpenCV] Failed to extract ${ZIP_PATH}!")
			else()
				message(STATUS "[gipOpenCV] Successfully extracted ${EXTRACTED_NAME}")
			endif()
		endif()
	endforeach()
endif()


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
if(EXISTS "${PLUGIN_PREBUILTS_DIR}/include/opencv5")
	list(APPEND PLUGIN_INCLUDES "${PLUGIN_PREBUILTS_DIR}/include/opencv5")
endif()


##### PLUGIN DEPENDENCY LOCATIONS & DLL COPYING (IF ANY) #####
if(WIN32)
	# 1. Copy required runtime DLLs from zbin by explicit filename (no wildcard globbing)
	set(ZBIN_REQUIRED_DLLS
		avcodec-60.dll
		avfilter-9.dll
		avformat-60.dll
		avutil-58.dll
		glew32.dll
		glfw3.dll
		libLerc.dll
		libSvtAv1Enc.dll
		libabsl_base.dll
		libabsl_city.dll
		libabsl_cord.dll
		libabsl_cord_internal.dll
		libabsl_cordz_handle.dll
		libabsl_cordz_info.dll
		libabsl_crc32c.dll
		libabsl_crc_cord_state.dll
		libabsl_crc_internal.dll
		libabsl_die_if_null.dll
		libabsl_examine_stack.dll
		libabsl_hash.dll
		libabsl_int128.dll
		libabsl_log_globals.dll
		libabsl_log_internal_check_op.dll
		libabsl_log_internal_format.dll
		libabsl_log_internal_globals.dll
		libabsl_log_internal_log_sink_set.dll
		libabsl_log_internal_message.dll
		libabsl_log_internal_nullguard.dll
		libabsl_log_internal_proto.dll
		libabsl_log_sink.dll
		libabsl_low_level_hash.dll
		libabsl_malloc_internal.dll
		libabsl_raw_hash_set.dll
		libabsl_raw_logging_internal.dll
		libabsl_spinlock_wait.dll
		libabsl_stacktrace.dll
		libabsl_status.dll
		libabsl_statusor.dll
		libabsl_str_format_internal.dll
		libabsl_strerror.dll
		libabsl_strings.dll
		libabsl_strings_internal.dll
		libabsl_symbolize.dll
		libabsl_synchronization.dll
		libabsl_throw_delegate.dll
		libabsl_time.dll
		libabsl_time_zone.dll
		libaom.dll
		libarchive-13.dll
		libassimp-6.dll
		libasprintf-0.dll
		libb2-1.dll
		libbluray-2.dll
		libbrotlicommon.dll
		libbrotlidec.dll
		libbrotlienc.dll
		libbz2-1.dll
		libc++.dll
		libcairo-2.dll
		libcairo-gobject-2.dll
		libcrypto-3-x64.dll
		libcurl-4.dll
		libdatrie-1.dll
		libdav1d.dll
		libexpat-1.dll
		libffi-8.dll
		libfreetype-6.dll
		libfribidi-0.dll
		libgdk_pixbuf-2.0-0.dll
		libgif-7.dll
		libgio-2.0-0.dll
		libglib-2.0-0.dll
		libgme.dll
		libgmodule-2.0-0.dll
		libgmp-10.dll
		libgmpxx-4.dll
		libgobject-2.0-0.dll
		libgraphite2.dll
		libgsm.dll
		libgstallocators-1.0-0.dll
		libgstapp-1.0-0.dll
		libgstaudio-1.0-0.dll
		libgstbase-1.0-0.dll
		libgstcheck-1.0-0.dll
		libgstcontroller-1.0-0.dll
		libgstfft-1.0-0.dll
		libgstgl-1.0-0.dll
		libgstnet-1.0-0.dll
		libgstpbutils-1.0-0.dll
		libgstreamer-1.0-0.dll
		libgstriff-1.0-0.dll
		libgstrtp-1.0-0.dll
		libgstrtsp-1.0-0.dll
		libgstsdp-1.0-0.dll
		libgsttag-1.0-0.dll
		libgstvideo-1.0-0.dll
		libgthread-2.0-0.dll
		libharfbuzz-0.dll
		libharfbuzz-cairo-0.dll
		libharfbuzz-gobject-0.dll
		libharfbuzz-raster-0.dll
		libharfbuzz-subset-0.dll
		libharfbuzz-vector-0.dll
		libhogweed-6.dll
		libiconv-2.dll
		libidn2-0.dll
		libjbig-0.dll
		libleptonica-6.dll
		liblz4.dll
		liblzma-5.dll
		libmfx-1.dll
		libminizip-1.dll
		libmp3lame-0.dll
		libnettle-8.dll
		libnghttp2-14.dll
		libnghttp3-9.dll
		libngtcp2-16.dll
		libngtcp2_crypto_ossl-0.dll
		libogg-0.dll
		libomp.dll
		libopenblas.dll
		libopencore-amrnb-0.dll
		libopencore-amrwb-0.dll
		libopenjp2-7.dll
		libopus-0.dll
		liborc-0.4-0.dll
		libpcre2-8-0.dll
		libpixman-1-0.dll
		libpng16-16.dll
		libpsl-5.dll
		librtmp-1.dll
		libspeex-1.dll
		libsrt.dll
		libssh2-1.dll
		libssl-3-x64.dll
		libtasn1-6.dll
		libtbb12.dll
		libtesseract-5.dll
		libthai-0.dll
		libtheora-0.dll
		libtheoradec-1.dll
		libtheoraenc-1.dll
		libunwind.dll
		libvorbis-0.dll
		libvorbisenc-2.dll
		libvorbisfile-3.dll
		libwinpthread-1.dll
		libx264-164.dll
		libx265.dll
		libxml2-2.dll
		libzstd.dll
		postproc-57.dll
		rav1e.dll
		swresample-4.dll
		swscale-7.dll
		xvidcore.dll
		zlib1.dll
	)
	foreach(zdll ${ZBIN_REQUIRED_DLLS})
		if(EXISTS "${MINGW64_DIR}/bin/${zdll}")
			file(COPY "${MINGW64_DIR}/bin/${zdll}" DESTINATION ${CMAKE_BINARY_DIR})
		endif()
	endforeach()

	# 2. Copy plugin-specific prebuilt runtime DLLs
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
		file(GLOB GST_PLUGIN_DLLS "${PLUGIN_PREBUILTS_DIR}/lib/gstreamer-1.0/*.dll")
		if(GST_PLUGIN_DLLS)
			file(COPY ${GST_PLUGIN_DLLS} DESTINATION ${CMAKE_BINARY_DIR}/lib/gstreamer-1.0)
			file(COPY ${GST_PLUGIN_DLLS} DESTINATION ${CMAKE_BINARY_DIR}/gstreamer-1.0)
		endif()
		list(APPEND PLUGIN_LINKDIRS "${PLUGIN_PREBUILTS_DIR}/lib/gstreamer-1.0")
		list(APPEND PLUGIN_LIBDIRS "${PLUGIN_PREBUILTS_DIR}/lib/gstreamer-1.0")
	endif()
elseif(ANDROID)
	add_compile_definitions(ANDROID=1 GLIST_ANDROID=1 GLIST_OPENGLES=1)
	# Android libs & includes here (${ANDROID_ABI} -> arm64-v8a, armeabi-v7a, x86_64)
	if(EXISTS "${PLUGIN_LIBS_DIR}/lib/android/${ANDROID_ABI}")
		list(APPEND PLUGIN_LINKDIRS "${PLUGIN_LIBS_DIR}/lib/android/${ANDROID_ABI}")
		list(APPEND PLUGIN_LIBDIRS "${PLUGIN_LIBS_DIR}/lib/android/${ANDROID_ABI}")
		link_directories("${PLUGIN_LIBS_DIR}/lib/android/${ANDROID_ABI}")
	endif()
	if(EXISTS "${PLUGIN_PREBUILTS_DIR}/lib/android/${ANDROID_ABI}")
		list(APPEND PLUGIN_LINKDIRS "${PLUGIN_PREBUILTS_DIR}/lib/android/${ANDROID_ABI}")
		list(APPEND PLUGIN_LIBDIRS "${PLUGIN_PREBUILTS_DIR}/lib/android/${ANDROID_ABI}")
		link_directories("${PLUGIN_PREBUILTS_DIR}/lib/android/${ANDROID_ABI}")
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
	if(EXISTS "${PLUGIN_PREBUILTS_DIR}/lib/android/${ANDROID_ABI}/libpng.a")
		add_library(gip_opencv_libpng STATIC IMPORTED)
		set_target_properties(gip_opencv_libpng PROPERTIES IMPORTED_LOCATION
				"${PLUGIN_PREBUILTS_DIR}/lib/android/${ANDROID_ABI}/libpng.a")
	elseif(EXISTS "${PLUGIN_LIBS_DIR}/libpng/${ANDROID_ABI}/libpng.a")
		add_library(gip_opencv_libpng STATIC IMPORTED)
		set_target_properties(gip_opencv_libpng PROPERTIES IMPORTED_LOCATION
				"${PLUGIN_LIBS_DIR}/libpng/${ANDROID_ABI}/libpng.a")
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
		opencv_alphamat
		opencv_bgsegm
		opencv_calib
		opencv_core
		opencv_datasets
		opencv_dnn_objdetect
		opencv_dnn_superres
		opencv_dpm
		opencv_face
		opencv_features
		opencv_flann
		opencv_freetype
		opencv_fuzzy
		opencv_gapi
		opencv_geometry
		opencv_hfs
		opencv_img_hash
		opencv_imgcodecs
		opencv_imgproc
		opencv_intensity_transform
		opencv_line_descriptor
		opencv_ml
		opencv_objdetect
		opencv_optflow
		opencv_phase_unwrapping
		opencv_photo
		opencv_plot
		opencv_ptcloud
		opencv_quality
		opencv_rapid
		opencv_reg
		opencv_rgbd
		opencv_saliency
		opencv_shape
		opencv_signal
		opencv_stereo
		opencv_stitching
		opencv_structured_light
		opencv_superres
		opencv_surface_matching
		opencv_tracking
		opencv_video
		opencv_videoio
		opencv_videostab
		opencv_wechat_qrcode
		opencv_xfeatures2d
		opencv_ximgproc
		opencv_xobjdetect
		opencv_xphoto
		opencv_xstereo
	)
elseif(ANDROID)
	list(APPEND PLUGIN_LINKLIBS
		opencv_xobjdetect
		opencv_objdetect
		opencv_dnn
		opencv_stitching
		opencv_calib
		opencv_features
		opencv_flann
		opencv_imgcodecs
		opencv_imgproc
		opencv_video
		opencv_videoio
		opencv_photo
		opencv_geometry
		opencv_ptcloud
		opencv_core
		protobuf
		jpeg-turbo
		gip_opencv_libpng
		webp
		tiff
		openjp2
		harfbuzz
		ittnotify
		cpufeatures
		tesseract
		leptonica
		camera2ndk
		mediandk
		z
		log
		jnigraphics
		android
	)
	if(ANDROID_ABI MATCHES "^arm")
		list(APPEND PLUGIN_LINKLIBS
			kleidicv
			kleidicv_hal
			kleidicv_thread
			tegra_hal
		)
	endif()
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

