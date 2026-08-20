cmake_minimum_required (VERSION 3.10.2)

##### PLUGIN NAME #####
set(pluginname gipOpenCV)


##### PLUGIN PATHS #####
set(PLUGIN_DIR ${PLUGINS_DIR}/${pluginname})
set(PREBUILT_DIR ${PLUGIN_DIR}/prebuilts)



##### PLUGIN SOURCES #####
list(APPEND PLUGIN_SRCS
			${PLUGIN_DIR}/src/gipOpenCV.cpp
			${PLUGIN_DIR}/src/gGuiOpenCVCamera.cpp
)

##### PLUGIN HEADERS #####
list(APPEND PLUGIN_INCLUDES
		${PLUGIN_DIR}/src
)

if(WIN32)
	list(APPEND PLUGIN_INCLUDES
			${PREBUILT_DIR}/include
			${PREBUILT_DIR}/include/glib
			${PREBUILT_DIR}/include/harfbuzz
	)
elseif(LINUX)
	list(APPEND PLUGIN_INCLUDES
		/usr/include/opencv4
		/usr/include/pango-1.0
		/usr/include/harfbuzz
		/usr/include/tesseract
		/usr/include/leptonica
	)
elseif(APPLE)
	find_package(OpenCV REQUIRED)
	if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
		# Homebrew ships libarchive keg only, include dirs have to be set manually
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

	list(APPEND PLUGIN_INCLUDES
			${OpenCV_INCLUDE_DIRS}
			${LibArchive_INCLUDE_DIRS}
			${GLIB_INCLUDE_DIRS}
			${PANGO_INCLUDE_DIRS}
	)
endif(WIN32)


##### PLUGIN DEPENDENCY LOCATIONS (IF ANY) #####
if(WIN32)
	# 1. Copy only required runtime DLLs from zbin (excluding heavy compiler tools like LLVM/Clang)
	get_filename_component(TOOLCHAIN_BIN_DIR "${CMAKE_CXX_COMPILER}" DIRECTORY)
	if(EXISTS "${TOOLCHAIN_BIN_DIR}")
		set(REQUIRED_RUNTIME_DLLS
			libc++.dll
			libunwind.dll
			libwinpthread-1.dll
			zlib1.dll
			libpng16-16.dll
			libfreetype-6.dll
			libbrotlidec.dll
			libbrotlienc.dll
			libbrotlicommon.dll
			libbz2-1.dll
			libcrypto-3-x64.dll
			libcurl-4.dll
			libexpat-1.dll
			libgio-2.0-0.dll
			libglib-2.0-0.dll
			libgmodule-2.0-0.dll
			libgobject-2.0-0.dll
			libgthread-2.0-0.dll
			libharfbuzz-0.dll
			libharfbuzz-gobject-0.dll
			libharfbuzz-icu-0.dll
			libharfbuzz-subset-0.dll
			libiconv-2.dll
			libidn2-0.dll
			liblzma-5.dll
			libomp.dll
			libp11-kit-0.dll
			libpcre2-16-0.dll
			libpcre2-8-0.dll
			libtasn1-6.dll
			libzstd.dll
			libopenblas.dll
			libtiff-6.dll
			libjpeg-8.dll
			libwebp-7.dll
			libsharpyuv-0.dll
			libvulkan-1.dll
			libxml2-16.dll
		)
		foreach(dll_name ${REQUIRED_RUNTIME_DLLS})
			if(EXISTS "${TOOLCHAIN_BIN_DIR}/${dll_name}")
				file(COPY "${TOOLCHAIN_BIN_DIR}/${dll_name}" DESTINATION ${CMAKE_BINARY_DIR})
			endif()
		endforeach()
	endif()

	# 2. Copy plugin-specific prebuilt DLLs (overriding any incompatible stock ones)
	file(GLOB OPENCV_DLLS "${PREBUILT_DIR}/bin/*.dll")
	file(COPY ${OPENCV_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
	if(EXISTS "${PREBUILT_DIR}/lib/gstreamer-1.0")
		file(COPY "${PREBUILT_DIR}/lib/gstreamer-1.0" DESTINATION "${CMAKE_BINARY_DIR}/lib")
	endif()
	if(EXISTS "${PREBUILT_DIR}/share/tessdata")
		file(COPY "${PREBUILT_DIR}/share/tessdata" DESTINATION "${CMAKE_BINARY_DIR}/assets/files")
	endif()

	list(APPEND PLUGIN_LINKDIRS
				${PREBUILT_DIR}/lib/win32
				${PREBUILT_DIR}/bin
	)
	
	#set(PLUGIN_LIBDIRS ${PREBUILT_DIR}/lib/win32)
	list(APPEND PLUGIN_LIBDIRS
				${PREBUILT_DIR}/lib/win32
				${PREBUILT_DIR}/lib/gstreamer-1.0
	)
elseif(ANDROID)
	# Android OpenCV SDK includes and libraries (${ANDROID_ABI})
	if(EXISTS "${PLUGIN_DIR}/libs/opencv/android/${ANDROID_ABI}")
		list(APPEND PLUGIN_LINKDIRS "${PLUGIN_DIR}/libs/opencv/android/${ANDROID_ABI}")
	endif()
elseif(LINUX)
	#Linux libs here
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
	#Macos libs here
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
#        harfbuzz-subset
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
#        opencv_cvv
        opencv_datasets
        opencv_dnn_objdetect
        opencv_dnn_superres
        opencv_dpm
        opencv_face
        opencv_freetype
        opencv_fuzzy
#        opencv_hdf
        opencv_hfs
        opencv_img_hash
        opencv_intensity_transform
        opencv_line_descriptor
        opencv_mcc
        opencv_optflow
#        opencv_ovis
        opencv_phase_unwrapping
        opencv_plot
        opencv_quality
        opencv_rapid
        opencv_reg
        opencv_rgbd
        opencv_saliency
#        opencv_sfm
        opencv_shape
        opencv_stereo
        opencv_structured_light
        opencv_superres
        opencv_surface_matching
        opencv_text
        opencv_tracking
        opencv_videostab
#        opencv_viz
        opencv_wechat_qrcode
        opencv_xfeatures2d
        opencv_ximgproc
        opencv_xobjdetect
        opencv_xphoto
    )
elseif(LINUX)
	list(APPEND PLUGIN_LINKLIBS
				#Lib names
		PkgConfig::deps
		PkgConfig::Libopencv
        leptonica
        lept
        tesseract
        Lib_lept
        Lib_tesseract
        archive
        cairo
        cairo-gobject
        cairo-script-interpreter
        pango-1.0
        pangocairo-1.0
        pangoft2-1.0
        gio-2.0
        gmodule-2.0
        gobject-2.0
        gthread-2.0
        harfbuzz
        harfbuzz-gobject
        harfbuzz-icu
#        harfbuzz-subset
        z
        opencv_calib3d
        opencv_core
        opencv_dnn
        opencv_features2d
        opencv_flann
#        opencv_gapi
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
#        opencv_cvv
        opencv_datasets
        opencv_dnn_objdetect
        opencv_dnn_superres
        opencv_dpm
        opencv_face
        opencv_freetype
        opencv_fuzzy
        opencv_hdf
        opencv_hfs
        opencv_img_hash
        opencv_intensity_transform
        opencv_line_descriptor
        opencv_mcc
        opencv_optflow
#        opencv_ovis
        opencv_phase_unwrapping
        opencv_plot
        opencv_quality
        opencv_rapid
        opencv_reg
        opencv_rgbd
        opencv_saliency
#        opencv_sfm
        opencv_shape
        opencv_stereo
        opencv_structured_light
        opencv_superres
        opencv_surface_matching
        opencv_text
        opencv_tracking
        opencv_videostab
        opencv_viz
        opencv_wechat_qrcode
#        opencv_xfeatures2d
        opencv_ximgproc
        opencv_xobjdetect
        opencv_xphoto
	)
elseif(ANDROID)
	list(APPEND PLUGIN_LINKLIBS
		# Android OpenCV native libraries (e.g. opencv_java4, opencv_core)
	)
elseif(APPLE)
	#Macos libs here
	list(APPEND PLUGIN_LINKLIBS
			${OpenCV_LIBS}
			${LibArchive_LIBRARIES}
			PkgConfig::glib
			PkgConfig::pango
			PkgConfig::tesseract
	)
endif(WIN32)
