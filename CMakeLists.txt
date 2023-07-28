cmake_minimum_required (VERSION 3.10.2)

##### PLUGIN NAME #####
set(pluginname gipOpenCV)


##### PLUGIN PATHS #####
set(PLUGIN_DIR ${PLUGINS_DIR}/${pluginname})
set(PREBUILT_DIR ${PLUGIN_DIR}/prebuilts)



##### PLUGIN SOURCES #####
list(APPEND PLUGIN_SRCS
			${PLUGIN_DIR}/src/gipOpenCV.cpp
			${PLUGIN_DIR}/src/gipGUICameraStream.cpp
)

##### PLUGIN HEADERS #####
list(APPEND PLUGIN_INCLUDES
			${PLUGIN_DIR}/src
			${PREBUILT_DIR}/include
			${PREBUILT_DIR}/include/glib
			${PREBUILT_DIR}/include/harfbuzz
)

if(WIN32)
	list(APPEND PLUGIN_INCLUDES
				${PREBUILT_DIR}/lib/win32/glib/include
	)
elseif(LINUX)
	list(APPEND PLUGIN_INCLUDES
		/usr/include/opencv4
	)
endif(LINUX)


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
				#Lib names
	)
endif(WIN32)
