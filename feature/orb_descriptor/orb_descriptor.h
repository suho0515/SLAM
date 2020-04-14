// OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <vector>

#include <time.h>

using namespace std;



void ORB_descriptor(cv::Mat img, std::vector<cv::KeyPoint>& key_points, cv::Mat& desp)	{   //uses FAST as of now, modify parameters as necessary

  clock_t start, end;
  double result;

  start = clock();

  cv::Ptr <cv::DescriptorExtractor> descriptor;
	descriptor = cv::ORB::create();
	descriptor->compute( img, key_points, desp );

  end = clock();
  result = (double)(end-start);
  cout << "ORB_descriptor process time : " << result << endl;

}
