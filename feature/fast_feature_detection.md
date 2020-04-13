# fast_feature_detection
It's from Abi Singh's Research.  
original source could be found in "https://github.com/avisingh599/mono-vo"  
  
# Structure
The input is cv::Mat type color image,  
with FAST function you can get output keypoints_1 which is type vector<KeyPoint>.  
after that change vector<KeyPoint> type to vector<Point2f> for using tracking.  

# Dependency
OpenCV Install  
Link : https://agiantmind.tistory.com/183  

setting for CmakeLists.txt  

~~~
find_package(OpenCV REQUIRED)

include_directories(
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(specific_package_you're_developing
    ${OpenCV_LIBS}
)
~~~

if you want to make it library then CmakeLists.txt setting is like below.  
~~~
# library
target_link_libraries(visualOdometry
    slam_lib
)

add_library(slam_lib src/fast_feature_detection.h)

target_link_libraries(slam_lib 
    ${OpenCV_LIBS}
)

~~~
