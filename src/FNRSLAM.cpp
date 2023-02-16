#include <fnr_slam/FNRSLAM.h>

fnr_slam::FNRSLAM::FNRSLAM(time_t max_node_age) {
	this->graph = std::make_shared<fnr_slam::Graph>(max_node_age);
}

fnr_slam::FNRSLAM::~FNRSLAM() {
}

void fnr_slam::FNRSLAM::setCameraTf(std::string frame_id, Eigen::Matrix<double, 3, 4> Rt) {
	if(this->streams[frame_id] == nullptr)
		this->streams[frame_id] = std::make_shared<fnr_slam::VideoStream>();
	this->streams[frame_id]->setExtrinsic(Rt);
}

void fnr_slam::FNRSLAM::setCameraIntrinsics(std::string frame_id, Eigen::Matrix3d K) {
	if(this->streams[frame_id] == nullptr)
		this->streams[frame_id] = std::make_shared<fnr_slam::VideoStream>();
	this->streams[frame_id]->setIntrinsic(K);
}

void fnr_slam::FNRSLAM::feedDepthImage(std::string frame_id, cv::Mat image) {
	if(this->streams[frame_id] == nullptr)
		this->streams[frame_id] = std::make_shared<fnr_slam::VideoStream>();
	this->streams[frame_id]->addDepthImage(image);
}

void fnr_slam::FNRSLAM::feedColorImage(std::string frame_id, cv::Mat image) {
	if(this->streams[frame_id] == nullptr)
		this->streams[frame_id] = std::make_shared<fnr_slam::VideoStream>();
	this->streams[frame_id]->addColorImage(image);
}
