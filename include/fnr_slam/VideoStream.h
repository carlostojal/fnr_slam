#ifndef VIDEO_STREAM_H_
#define VIDEO_STREAM_H_

#include <eigen3/Eigen/Dense>
#include <opencv2/opencv.hpp>

// this class defines a video stream
// a video stream is, pretty much, a camera
// it has a transformation in relation to the base of the robot and streams images

class VideoStream {

	private:
		Eigen::Affine3d tfToBase;
		bool tfWasSet = false;
		cv::Mat lastColorImage;
		bool colorImageWasSet = false;
		cv::Mat lastDepthImage;
		bool depthImageWasSet = false;

	public:
		VideoStream();

		Eigen::Affine3d getTfToBase();
		void setTfToBase(Eigen::Affine3d tf);
		cv::Mat getLastColorImage();
		void addColorImage(cv::Mat img);
		cv::Mat getLastDepthImage();
		void addDepthImage(cv::Mat img);

};

#endif
