# cam3d

TODO search for similar camera libraries, but I can't find any in C++!

## Including

To add this library to your project, simply add these two lines to your *CMakeLists.txt*:
```cmake
add_subdirectory(path/to/cam3d)
target_link_libraries(${PROJECT_NAME} PRIVATE cam3d::cam3d)
```

Then include it as:
```cpp
#include <cam3d/cam3d.hpp>
```

## Camera Data

View and Projection go together because they both contribute to define the camera frustum. This frustum is required by some controllers to make sure a point alwaysremain under the mouse (needs to project from 3D-world to screen), and by some operations (shooting a ray for a given pixel i nscreen-space)

## Controler

https://stackoverflow.com/a/33061294
https://vvise.iat.sfu.ca/user/data/papers/comparerotation.pdf
https://blender.stackexchange.com/questions/657/what-is-the-difference-between-the-trackball-and-turntable-style-view-modes That's not what I thought trackball did in Blender!
[Generalized Trackball and 3D Touch Interaction](https://core.ac.uk/download/pdf/14704955.pdf): Look the *CHAPTER 2. STATE OF THE ART* section, it does a great job at presenting new controlers (*Navidget*, *HoverCam*). Also, *CHAPTER 3. TOUCH-BASED VIRTUAL TRACKBALL* does a great presentation of the trackball.
-> check out MeshLab's camera

ZOOMING IS A MULTIPLICATIVE OPERATION!

### Orbital

#### Trackball

#### Turntable

#### AxisFree

### Freefly

## Running the tests

Simply use "tests/CMakeLists.txt" to generate a project, then run it.<br/>
If you are using VSCode and the CMake extension, this project already contains a *.vscode/settings.json* that will use the right CMakeLists.txt automatically.
