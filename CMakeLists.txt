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
#			${OpenCV_INCLUDE_DIRS}
)

#set(OpenCV_DIR ${PREBUILT_DIR}/lib/win32)
#find_package(OpenCV REQUIRED)

##### PLUGIN DEPENDENCY LOCATIONS (IF ANY) #####
if(WIN32)
	list(APPEND PLUGIN_LINKDIRS
				${PREBUILT_DIR}/lib/win32
				${PREBUILT_DIR}/bin			
	#			${OpenCV_LIBS}
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
			opencv_calib3d455.dll
			opencv_core455.dll
			opencv_dnn455.dll
			opencv_features2d455.dll
			opencv_flann455.dll
			opencv_gapi455.dll
			opencv_highgui455.dll
			opencv_imgcodecs455.dll
			opencv_imgproc455.dll
			opencv_ml455.dll
			opencv_objdetect455.dll
			opencv_photo455.dll
			opencv_stitching455.dll
			opencv_video455.dll
			opencv_videoio455.dll
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
