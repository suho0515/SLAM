// OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <vector>

void feature_distance_filtering(std::vector<cv::KeyPoint>& key_points, int threshold=50)	{   

	int x_1,y_1,
		x_2,y_2,
		distance;

	for(int i=0;i<key_points.size()-1;i++)
	{
		x_1 = key_points.at(i).pt.x;
		y_1 = key_points.at(i).pt.y;
		for(int j=i+1;j<key_points.size();j++)
		{
			x_2 = key_points.at(j).pt.x;
			y_2 = key_points.at(j).pt.y;
			distance = sqrt(pow(x_2-x_1,2)+pow(y_2-y_1,2));
			if(distance<threshold) key_points.erase(key_points.begin()+(j-1));
		}
	}
}
