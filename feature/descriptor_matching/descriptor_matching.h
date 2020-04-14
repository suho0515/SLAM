// OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <vector>

#include <time.h>

using namespace std;

void descriptor_maching(cv::Mat desp_1, cv::Mat desp_2, std::vector<cv::DMatch>& matches_vector)	{   

    clock_t start, end;
    double result;

    start = clock();

    cv::BFMatcher matches;
    matches.match(desp_1 , desp_2 , matches_vector);
   
    cout<<"find total "<<matches_vector.size()<<" matches."<<endl;



    std::vector<cv::DMatch> goodMatches;
    double minDis = 9999;
    double good_match_threshold = 10;
    for ( size_t i=0; i<matches_vector.size(); i++ )
    {
        if ( matches_vector[i].distance < minDis )
            minDis = matches_vector[i].distance;
    }

    cout<<"min dis = "<<minDis<<endl;
    if ( minDis < 10 ) 
        minDis = 10 ;

    for ( size_t i=0; i<matches_vector.size(); i++ )
    {
        if (matches_vector[i].distance < good_match_threshold*minDis)
            goodMatches.push_back( matches_vector[i] );
    }

    cout<<"good matches: "<<goodMatches.size()<<endl;

    end = clock();
    result = (double)(end-start);
    cout << "descriptor_maching process time : " << result << endl;
}
