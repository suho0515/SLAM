# OpenCV
it's the library for image processing.  
  
# install
reference link is below.  
Link : https://agiantmind.tistory.com/183

# Setting
if you want use OpenCV in ROS enviroments, you should edit "CMakeLists.txt" in your package.


## CMakeList.txt
~~~
...
**find_package(OpenCV REQUIRED)**

include_directories(
  **include**
  ${catkin_INCLUDE_DIRS}
  **${OpenCV_INCLUDE_DIRS}**
)

add_executable(slam 
    src/slam.cpp
)

target_link_libraries(slam
    ${catkin_LIBRARIES}
    **${OpenCV_LIBRARIES}**
)

...
~~~

if you have any header which has opencv header, then just put it in include folder.  
cause you already include "include" folder in "include_directories", the package would recognize it.




