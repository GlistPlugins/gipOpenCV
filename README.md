# gipEmpty
This is a baseplate for all the GlistEngine plugins and should be cloned under `~dev/glist/glistplugins` whenever developing a new plugin for the engine.
# gipOpenCV
OpenCV plugin for [GlistEngine](https://github.com/GlistEngine/GlistEngine).
#### Requierements
- [GlistEngine](https://github.com/GlistEngine/GlistEngine)
- Data set

The developer should put his external precompiled library files into the plugin's libs folder.
## Installation
Fork & clone this project into ~/dev/glist/glistplugins

- Windows developers should not forget to add
```
${workspace_loc}\..\..\..\..\glistplugins\gipYourPlugin\libs\bin
```
directory to the GlistApp project's PATH list.
(Project->Properties->C/C++ Build->Environment->PATH)
## Usage
- 2D and 3D feature toolkits
- Object detection
- Facial recognition system
- Human-computer interaction

## How To Use 
1. Add gipOpenCV into plugins of your GlistApp/CMakeLists.txt
2. Include gipOpenCV.h in GameCanvas.h

## Functions
1. ##### makeGray
> Makes the imported image binary.
2. ##### makeCanny
> Finds the locations of objects basd on the XML file put in.
3. ##### objectDetection
> Finds the locations of faces from image.
4. ##### faceDetection 
> Draws squares on the image entered with locations taken from the location list.
5. ##### objectsDraw
> Finds contours.
6. ##### contourDetection
> Detects the contour values of the uploaded image as integers.
7. ##### readTextFromImage
> Detects the text from uploaded image.
8. ##### updateImagefromCam
> Updates the image that is detected from the cam matrix using its data.
9. ##### updateImagefromVideo
> Updates the image that is detected from the video as matrix using its data.
10. ##### setCam
> Assignes a number to the camera for easy access to videos.
11. ##### setMatData
> Turns the data of the image to a matrix as its components and turns it to a color number.
12. ##### setVideo
> Gets the video file by its path.
