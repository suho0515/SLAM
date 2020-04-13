# fast_feature_detection
It's from Abi Singh's Research.  
original source could be found in "https://github.com/avisingh599/mono-vo"  
  
# Structure
The input is cv::Mat type color image,  
with FAST function you can get output keypoints_1 which is type vector<KeyPoint>.  
after that change vector<KeyPoint> type to vector<Point2f> for using tracking.  

# Dependency
take a look at link below.

https://github.com/suho0515/SLAM/blob/master/ros/library/OpenCV.md
