// OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <vector>

void ORB_descriptor(cv::Mat img, std::vector<cv::KeyPoint>& key_points, cv::Mat desp)	{   //uses FAST as of now, modify parameters as necessary

  cv::Ptr<cv::DescriptorExtractor> _descriptor;
  _descriptor = cv::ORB::create();
  _descriptor->compute( img, key_points, desp );


  // for (size_t i = 0; i < 100; ++i) {
  //     std::cout << "ORB Keypoint #:" << i;
  //     std::cout << " Size " << feature_points[i].size << " Angle " << feature_points[i].angle << " Response " << feature_points[i].response << " Octave " << feature_points[i].octave << std::endl;
  //}
}
