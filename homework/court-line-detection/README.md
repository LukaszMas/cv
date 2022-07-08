# Homework

R&amp;D project for finding tennis court lines in given image

## Building the program:
* **(Preferred) Call make from the project's root directory:**
  * $ `make` - executable file 'Court' will be created in the bin dir
* **Cd to src folder and type the g++ following command:**
  * $ ``g++ -o court court.cpp `pkg-config opencv4 --cflags --libs` ``
* **Remarks:**
	* For ubuntu and family install OpenCV with `apt install libopencv-dev`
	* If building with older version of OpenCV library - 'opencv4' has to be changed  
    to 'opencv' and if building with make the same change is required in the makefile.

### Invoke the 'Court' program in two ways:
 1) No arguments - If court was build the "preferred" way, then:
    * invoke court with:
        * `./bin/court`
    * The 'court.png' file will be processed with the default parameters

 2) With up to three arguments:
    * file_name of image to process
    * kernel_thickness - must be odd number, to meet blur kernel requirements.
    * slope_tolerance - threshold for merging detected adjacent lines.

#### Description
* Program detects lines in the picture by utilizing `OpenCV` library APIs.  
Image is converted to greyscale for ease of edge detection then Gaussian blur  
is applied to eliminate color noises.  
Next, blurred image is processed for edge detection with Canny function and lines are detected  
with HoughTransform. Detected similar lines are merged by parameter averages to reduce their  
number and single line is being drawn on the image representing calculated averages.  
End results are displayed.

* In next stage of the project, detected lines would be used for finding crossing points  
in order to perform some kind of "fitting algorithm" using characteristics of the standard court  
and its properties. The positions of these points are the result of perspective projection on the  
image surface, that is - perspective transform determined by the position, orientation and other  
parameters of the camera. Knowing the real positions of the court in the 3D space, from the standard  
specification of a tennis court, the perspective transform can be found. If such a transform exists  
and is unequivocal for the selected two groups of points, on the image and on the standard court,  
the selected image points do represent the real court, and from the parameters of the transform, the  
parameters of the camera in relation to the court can be found, allowing for navigation in its space.  
Additionally, finding the right group of points could be made easier, by selecting for the transform  
calculation only such two groups of points, on the image and on the standard court, of which the line  
connection structure is the same.

* For further exploring: [3D_projection at wikipedia][1]

[1]: <https://en.wikipedia.org/wiki/3D_projection.> "3D projection at wiki"
