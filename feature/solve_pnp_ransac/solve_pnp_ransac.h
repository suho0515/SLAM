// OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <vector>


void solve_pnp_ransac( std::vector<cv::Point3f>& pts_obj, std::vector< cv::Point2f>& pts_img, cv::Mat& rvec, cv::Mat& tvec, cv::Mat& inliers, CAMERA_INTRINSIC_PARAMETERS& camera )
{
	double camera_matrix_data[3][3] = {
        {camera.fx, 0, camera.cx},
        { 0 , camera. fy , camera. cy },
        { 0 , 0 , 1 }
    	};
        cv::Mat cameraMatrix( 3, 3, CV_64F, camera_matrix_data );
	cv::solvePnPRansac( pts_obj, pts_img, cameraMatrix, cv::Mat(), rvec, tvec, false, 100, 8.0, 0.99, inliers );

}



