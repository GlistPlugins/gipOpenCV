cmake_minimum_required (VERSION 3.10.2)

##### PLUGIN NAME #####
set(pluginname gipOpenCV)


##### PLUGIN PATHS #####
set(PLUGIN_DIR ${PLUGINS_DIR}/${pluginname})
set(PREBUILT_DIR ${PLUGIN_DIR}/prebuilts)



##### PLUGIN SOURCES #####
list(APPEND PLUGIN_SRCS
			${PLUGIN_DIR}/src/gipOpenCV.cpp
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
	list(APPEND PLUGIN_LINKDIRS
				${PREBUILT_DIR}/lib/win32
				${PREBUILT_DIR}/bin	
	)
	
	#set(PLUGIN_LIBDIRS ${PREBUILT_DIR}/lib/win32)
	list(APPEND PLUGIN_LIBDIRS
				${PREBUILT_DIR}/lib/win32
	)
elseif(LINUX)
	#Linux libs here
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
        harfbuzz-subset
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
        opencv_cvv
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
        opencv_ovis
        opencv_phase_unwrapping
        opencv_plot
        opencv_quality
        opencv_rapid
        opencv_reg
        opencv_rgbd
        opencv_saliency
        opencv_sfm
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
        opencv_xfeatures2d
        opencv_ximgproc
        opencv_xobjdetect
        opencv_xphoto
        
        
    )
elseif(LINUX)
	list(APPEND PLUGIN_LINKLIBS
				#Lib names
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
