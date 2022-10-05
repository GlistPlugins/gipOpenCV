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
			${PREBUILT_DIR}/include
			${PREBUILT_DIR}/include/glib
)

if(LINUX)
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
		
	add_library(opencv_core SHARED IMPORTED)
	set_target_properties(opencv_core PROPERTIES IMPORTED_LOCATION
			/usr/lib/x86_64-linux-gnu/libopencv_core.so)
	
elseif(APPLE)
	#Macos libs here
endif(WIN32)


##### PLUGIN DEPENDENCY LINKING (IF ANY) #####					
if(WIN32)
	list(APPEND PLUGIN_LINKLIBS
		lept
		tesseract
		archive
		cairo
		cairo-gobject
		libcairo-script-interpreter
		icudt
		icuin
		icuio
		icutest
		icutu
		icuuc
		lept
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
		opencv_calib3d455
		opencv_core455
		opencv_dnn455
		opencv_features2d455
		opencv_flann455
		opencv_gapi455
		opencv_highgui455
		opencv_imgcodecs455
		opencv_imgproc455
		opencv_ml455
		opencv_objdetect455
		opencv_photo455
		opencv_stitching455
		opencv_video455
		opencv_videoio455
	)
elseif(LINUX)
	list(APPEND PLUGIN_LINKLIBS
				#Lib names
		opencv_calib3d
		opencv_core
		opencv_dnn
		opencv_features2d
		opencv_flann
#		opencv_gapi
		opencv_highgui
		opencv_imgcodecs
		opencv_imgproc
		opencv_ml
		opencv_objdetect
		opencv_photo
		opencv_stitching
		opencv_video
		opencv_videoio
	)
elseif(APPLE)
	list(APPEND PLUGIN_LINKLIBS
				#Lib names
	)
endif(WIN32)
