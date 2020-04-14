// OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <vector>

//#include "camera_intrinsic_parameter.h"

cv::Point3f point2dTo3d( cv::Point3f& point, CAMERA_INTRINSIC_PARAMETERS& camera )
{
    cv :: Point3f p; // 3D point
    p.z = double( point.z ) / camera.scale;
    p.x = ( point.x - camera.cx) * p.z / camera.fx;
    p.y = ( point.y - camera.cy) * p.z / camera.fy;
    return p;
}

void match_key_points( cv::Mat& image_depth, std::vector<cv::DMatch>& matches_vector, std::vector<cv::Point2f>& pts_img, std::vector<cv::Point3f>& pts_obj, std::vector<cv::KeyPoint>& kp_1,std::vector<cv::KeyPoint>& kp_2, CAMERA_INTRINSIC_PARAMETERS& camera )
{
    for (size_t i=0; i<matches_vector.size(); i++)
    {
        // query is the first and train is the second
        cv::Point2f p = kp_1[matches_vector[i].queryIdx].pt;    
	// Be careful about getting d! x is right, y is down, so y is the row, x is the column!
	ushort d = image_depth.ptr<ushort>( int(p.y) )[ int(p.x) ];
	if (d == 0)
		continue;
	pts_img.push_back( cv::Point2f( kp_2[matches_vector[i].trainIdx].pt ) );

	// Convert (u, v, d) to (x, y, z)
	cv::Point3f pt ( p.x, p.y, d );
	cv::Point3f pd = point2dTo3d( pt, camera );
	pts_obj.push_back( pd );
    }
}


