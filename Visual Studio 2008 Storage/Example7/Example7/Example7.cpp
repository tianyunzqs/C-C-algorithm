// 特征点匹配.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdio.h>
#include <iostream>

#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/nonfree/features2d.hpp>

using namespace cv;

int main( int argc, char** argv )
{
	//Mat img_1=imread("image0.jpg");
	//Mat img_2=imread("image1.jpg");

	//Mat img_1=imread("box.png");
	//Mat img_2=imread("box_in_scene.png");

	Mat img_1=imread("Lena.jpg");
	Mat img_2=imread("Lena_wrap_rotate.jpg");

	if( !img_1.data || !img_2.data )
	{ std::cout<< " --(!) Error reading images " << std::endl; return -1; }

	//-- Step 1: Detect the keypoints using SURF Detector
	int minHessian = 400;

	SiftFeatureDetector detector( minHessian );
	//SurfFeatureDetector detector( minHessian );

	std::vector keypoints_1, keypoints_2;

	detector.detect( img_1, keypoints_1 );
	detector.detect( img_2, keypoints_2 );

	//-- Step 2: Calculate descriptors (feature vectors)
	SiftDescriptorExtractor extractor;
	//SurfDescriptorExtractor extractor;

	Mat descriptors_1, descriptors_2;

	extractor.compute( img_1, keypoints_1, descriptors_1 );
	extractor.compute( img_2, keypoints_2, descriptors_2 );

	//-- Step 3: Matching descriptor vectors using FLANN matcher
	FlannBasedMatcher matcher;
	std::vector< DMatch > matches;
	matcher.match( descriptors_1, descriptors_2, matches );

	double max_dist = 0; double min_dist = 100;

	//-- Quick calculation of max and min distances between keypoints
	for( int i = 0; i < descriptors_1.rows; i++ )
	{ double dist = matches.distance;
	if( dist < min_dist ) min_dist = dist;
	if( dist > max_dist ) max_dist = dist;
	}

	printf("-- Max dist : %f \n", max_dist );
	printf("-- Min dist : %f \n", min_dist );

	//-- Draw only "good" matches (i.e. whose distance is less than 2*min_dist )
	//-- PS.- radiusMatch can also be used here.
	std::vector< DMatch > good_matches;

	for( int i = 0; i < descriptors_1.rows; i++ )
	{ if( matches.distance < 2*min_dist )
	{ good_matches.push_back( matches); }
	}

	//-- Draw only "good" matches
	Mat img_matches;
	drawMatches( img_1, keypoints_1, img_2, keypoints_2,
		good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
		vector(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

	//-- Show detected matches
	imshow( "Good Matches", img_matches );
	//imwrite("Lena_match_surf.jpg",img_matches);
	//imwrite("Lena_match_sift.jpg",img_matches);
	for( int i = 0; i < good_matches.size(); i++ )
		//{ 
		// printf( "-- Good Match [%d] Keypoint 1: %d  -- Keypoint 2: %d  \n", i,  good_matches.queryIdx,good_matches.trainIdx ); 
		//}
	{
		//good_matches.queryIdx保存着第一张图片匹配点的序号，keypoints_1[good_matches.queryIdx].pt.x 为该序号对应的点的x坐标。y坐标同理
		//good_matches.trainIdx保存着第二张图片匹配点的序号，keypoints_2[good_matches.trainIdx].pt.x 为为该序号对应的点的x坐标。y坐标同理
		printf( "-- Good Match [%d] Keypoint 1(%f,%f): %d  -- Keypoint 2(%f,%f): %d  \n", i, 
			keypoints_1[good_matches.queryIdx].pt.x,keypoints_1[good_matches.queryIdx].pt.y, good_matches.queryIdx, 
			keypoints_2[good_matches.trainIdx].pt.x,keypoints_2[good_matches.trainIdx].pt.y,good_matches.trainIdx );
	}
	waitKey(0);
	return 0;
}

