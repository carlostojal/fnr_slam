#ifndef VIDEO_STREAM_H_
#define VIDEO_STREAM_H_

#include <eigen3/Eigen/Dense>
#include <opencv2/opencv.hpp>

// this class defines a video stream
// a video stream is, pretty much, a camera
// it has a transformation in relation to the base of the robot and streams images

class VideoStream {

	private:
		Eigen::Affine3d tfToBase; // this is basically the [R|t] matrix
		bool tfWasSet = false;
		cv::Mat lastColorImage; // in the future could implement a fixed size buffer
		bool colorImageWasSet = false;
		cv::Mat lastDepthImage; // same as the color image, could implement a buffer
		bool depthImageWasSet = false;
		Eigen::Matrix3d intrinsics; // the intrinsic matrix K
		bool intrinsicsWasSet = false;

	public:
		VideoStream();

		Eigen::Affine3d getTfToBase();
		void setTfToBase(Eigen::Affine3d tf);
		cv::Mat getLastColorImage();
		void addColorImage(cv::Mat img);
		cv::Mat getLastDepthImage();
		void addDepthImage(cv::Mat img);
		Eigen::Matrix3d getIntrinsics();
		void setIntrinsics(Eigen::Matrix3d K);

		cv::Mat getLastTopView(); // get top view of the last color image
};

#endif
