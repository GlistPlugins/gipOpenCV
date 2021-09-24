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
			${PREBUILT_DIR}/include/opencv4
			${PREBUILT_DIR}/include/opencv4/opencv2
			${PREBUILT_DIR}/include/boost
			${PREBUILT_DIR}/include/brotli
			${PREBUILT_DIR}/include/cairo
			${PREBUILT_DIR}/include/ceres
			${PREBUILT_DIR}/include/cppunit
			${PREBUILT_DIR}/include/curl
			${PREBUILT_DIR}/include/datrie
			${PREBUILT_DIR}/include/editline
			${PREBUILT_DIR}/include/eigen3
			${PREBUILT_DIR}/include/fontconfig
			${PREBUILT_DIR}/include/freetype2
			${PREBUILT_DIR}/include/fribidi
			${PREBUILT_DIR}/include/gflags
			${PREBUILT_DIR}/include/gio-win32-2.0
			${PREBUILT_DIR}/include/GL
			${PREBUILT_DIR}/include/glib-2.0
			${PREBUILT_DIR}/include/glog
			${PREBUILT_DIR}/include/google
			${PREBUILT_DIR}/include/graphite2
			${PREBUILT_DIR}/include/harfbuzz
			${PREBUILT_DIR}/include/jasper
			${PREBUILT_DIR}/include/jemalloc
			${PREBUILT_DIR}/include/jxrlib
			${PREBUILT_DIR}/include/leptonica
			${PREBUILT_DIR}/include/libpng16
			${PREBUILT_DIR}/include/libraw
			${PREBUILT_DIR}/include/libxml2
			${PREBUILT_DIR}/include/lzma
			${PREBUILT_DIR}/include/lzo
			${PREBUILT_DIR}/include/metalink
			${PREBUILT_DIR}/include/ncurses
			${PREBUILT_DIR}/include/ncursew
			${PREBUILT_DIR}/include/nettle
			${PREBUILT_DIR}/include/nghttp2
			${PREBUILT_DIR}/include/OGRE
			${PREBUILT_DIR}/include/OpenBLAS
			${PREBUILT_DIR}/include/OpenEXR
			${PREBUILT_DIR}/include/openjpeg-2.3
			${PREBUILT_DIR}/include/openssl
			${PREBUILT_DIR}/include/p11-kit-1
			${PREBUILT_DIR}/include/pango-1.0
			${PREBUILT_DIR}/include/pixman-1
			${PREBUILT_DIR}/include/python3.9
			${PREBUILT_DIR}/include/readline
			${PREBUILT_DIR}/include/SDL2
			${PREBUILT_DIR}/include/shared
			${PREBUILT_DIR}/include/static
			${PREBUILT_DIR}/include/tbb
			${PREBUILT_DIR}/include/tcl8.6
			${PREBUILT_DIR}/include/tesseract
			${PREBUILT_DIR}/include/thai
			${PREBUILT_DIR}/include/tk8.6
			${PREBUILT_DIR}/include/tre
			${PREBUILT_DIR}/include/unicode
			${PREBUILT_DIR}/include/unistring
			${PREBUILT_DIR}/include/vk_video
			${PREBUILT_DIR}/include/vulkan
			${PREBUILT_DIR}/include/webp
			${PREBUILT_DIR}/include/X11
			${PREBUILT_DIR}/include/zzip
)


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
				opencv_core
	)
elseif(LINUX)
	list(APPEND PLUGIN_LINKLIBS
				opencv_core
	)
elseif(APPLE)
	list(APPEND PLUGIN_LINKLIBS
	)
endif(WIN32)