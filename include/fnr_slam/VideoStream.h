#ifndef VIDEO_STREAM_H_
#define VIDEO_STREAM_H_

#include <eigen3/Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <cstdint>
#include <vector>
#include <stdexcept>

// this class defines a video stream
// a video stream is, pretty much, a camera
// it has a transformation in relation to the base of the robot and streams images

using namespace cv;
using namespace Eigen;

namespace fnr_slam {

	class VideoStream {

		private:
			Eigen::Matrix<double, 3, 4> extrinsic; // this is basically the [R|t] matrix
			bool extrinsicWasSet = false;
			cv::Mat lastColorImage; // in the future could implement a fixed size buffer
			bool colorImageWasSet = false;
			cv::Mat lastDepthImage; // same as the color image, could implement a buffer
			bool depthImageWasSet = false;
			cv::Mat lastTopView;
			Eigen::Matrix3d intrinsic; // the intrinsic matrix K
			bool intrinsicWasSet = false;
			Eigen::Matrix<double, 3, 4> projection; // camera projection matrix
			Eigen::Matrix<double, 3, 4> computeProjectionMatrix();
			cv::Mat homography; // the homography matrix is stored as opencv matrix instead of eigen to avoid additional conversions
			cv::Mat computeHomographyMatrix(); // compute the homography matrix to the top-view

		public:
			VideoStream();

			Eigen::Matrix<double, 3, 4> getExtrinsic();
			void setExtrinsic(Eigen::Matrix<double, 3, 4> Rt);
			cv::Mat getLastColorImage();
			void addColorImage(cv::Mat img);
			cv::Mat getLastDepthImage();
			void addDepthImage(cv::Mat img);
			Eigen::Matrix3d getIntrinsic();
			void setIntrinsic(Eigen::Matrix3d K);
			Eigen::Matrix<double, 3, 4> getProjectionMatrix();

			cv::Mat getLastTopView(); // get top view of the last color image
	};
}

#endif
