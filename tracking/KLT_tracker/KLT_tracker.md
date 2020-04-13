# KLT_tracker
it's from Avi Singh's research.  
you can find the original source from the link below.  
Link : https://github.com/avisingh599/mono-vo  



# Structure
the inputs are **two sequencial images** and **feature points of first input image**.
and the output came from **"calcOpticalFlowPyrLK"** function is **"tracked feature points of second input image"** and **"status"**, the OutputArray vector(uchar). **"status"** having information about tracked feature points.

and this function also get rid of feature points outside of window. 


# Dependency
you need OpenCV Library.

specific info about setting OpenCV is below.

Link : https://github.com/suho0515/SLAM/blob/master/ros/library/OpenCV.md
