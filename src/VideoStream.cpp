#include <fnr_slam/VideoStream.h>

fnr_slam::VideoStream::VideoStream() {
	this->extrinsicWasSet = false;
	this->colorImageWasSet = false;
	this->depthImageWasSet = false;
}

Eigen::Matrix<double, 3, 4> fnr_slam::VideoStream::computeProjectionMatrix() {
	// both the K and and [R|t] need to be defined
	if(this->extrinsicWasSet && this->intrinsicWasSet)
		this->projection = this->intrinsic * this->extrinsic;
}

cv::Mat fnr_slam::VideoStream::computeHomographyMatrix() {

	// the perspective image must be set to compute the homography
	if(this->colorImageWasSet) {
		this->computeProjectionMatrix();

		// populate a vector with the corners of the output image
		cv::Size s = this->lastColorImage.size();
		std::vector<cv::Point2f> output_corners = {
			cv::Point2f(0,0),
			cv::Point2f(s.width, 0),
			cv::Point2f(s.width, s.height),
			cv::Point2f(0, s.height)
		};

		std::vector<cv::Point2f> input_corners;

		// calculate the input corners from the input corners
		// using the projection matrix inverse
		Eigen::MatrixXd P_inv = this->projection.inverse();
		cv::Mat P_inv_cv(4, 3, CV_64F);
		// copy the eigen matrix to the opencv matrix
		# pragma omp parallel for
		for(uint8_t i = 0; i < 4; i++) {
			double *rowPtr = P_inv_cv.ptr<double>(i);
			for(uint8_t j = 0; j < 3; j++) {
				rowPtr[j] = P_inv(i,j);
			}
		}
		cv::perspectiveTransform(output_corners, input_corners, P_inv_cv);

		// compute the homography matrix from the transformation of the corners
		cv::Mat H = cv::findHomography(input_corners, output_corners);

		return H;

	}

	// TODO: throw an exception

}

Eigen::Matrix<double, 3, 4> fnr_slam::VideoStream::getExtrinsic() {
	if(this->extrinsicWasSet) {
		return this->extrinsic;
	}
	// TODO: throw an exception
	return this->extrinsic;
}

void fnr_slam::VideoStream::setExtrinsic(Eigen::Matrix<double, 3, 4> Rt) {
	this->extrinsic = Rt;
	this->extrinsicWasSet = true;
	this->computeProjectionMatrix(); // update/set projection matrix
}

cv::Mat fnr_slam::VideoStream::getLastColorImage() {
	if(this->colorImageWasSet) {
		return this->lastColorImage;
	}
	// TODO: throw an exception
	return this->lastColorImage;
}

void fnr_slam::VideoStream::addColorImage(cv::Mat img) {
	this->lastColorImage = img;
	this->colorImageWasSet = true;
}

cv::Mat fnr_slam::VideoStream::getLastDepthImage() {
	if(this->depthImageWasSet) {
		return this->lastDepthImage;
	}
	// TODO: throw an exception
	return this->lastDepthImage;
}

void fnr_slam::VideoStream::addDepthImage(cv::Mat img) {
	this->lastDepthImage = img;
	this->depthImageWasSet = true;
}

Eigen::Matrix3d fnr_slam::VideoStream::getIntrinsic() {
	if(this->intrinsicWasSet)
		return this->intrinsic;
	// TODO: throw an exception
	return this->intrinsic;
}

void fnr_slam::VideoStream::setIntrinsic(Eigen::Matrix3d K) {
	this->intrinsic = K;
	this->intrinsicWasSet = true;
	this->computeProjectionMatrix(); // update/set projection matrix
}

cv::Mat fnr_slam::VideoStream::getLastTopView() {

	// get the homography matrix
	cv::Mat H = this->computeHomographyMatrix();

	// get the input image size to use the same on the output
	cv::Size s = this->lastColorImage.size();

	// warp the input image to make the top view
	cv::warpPerspective(this->lastColorImage, this->lastTopView, H, s);

	return this->lastTopView;
}

