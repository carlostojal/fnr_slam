#include <fnr_slam/VideoStream.h>

VideoStream::VideoStream() {
	this->tfWasSet = false;
	this->colorImageWasSet = false;
	this->depthImageWasSet = false;
}

Eigen::Affine3d VideoStream::getTfToBase() {
	if(this->tfWasSet) {
		return this->tfToBase;
	}
	// TODO: throw an exception
	return this->tfToBase;
}

void VideoStream::setTfToBase(Eigen::Affine3d tf) {
	this->tfToBase = tf;
	this->tfWasSet = true;
}

cv::Mat VideoStream::getLastColorImage() {
	if(this->colorImageWasSet) {
		return this->lastColorImage;
	}
	// TODO: throw an exception
	return this->lastColorImage;
}

void VideoStream::addColorImage(cv::Mat img) {
	this->lastColorImage = img;
	this->colorImageWasSet = true;
}

cv::Mat VideoStream::getLastDepthImage() {
	if(this->depthImageWasSet) {
		return this->lastDepthImage;
	}
	// TODO: throw an exception
	return this->lastDepthImage;
}

void VideoStream::addDepthImage(cv::Mat img) {
	this->lastDepthImage = img;
	this->depthImageWasSet = true;
}

Eigen::Matrix3d VideoStream::getIntrinsics() {
	if(this->intrinsicsWasSet)
		return this->intrinsics;
	// TODO: throw an exception
	return this->intrinsics;
}

void VideoStream::setIntrinsics(Eigen::Matrix3d K) {
	this->intrinsics = K;
	this->intrinsicsWasSet = true;
}

