#ifndef FNRSLAM_H_
#define FNRSLAM_H_

#include <iostream>
#include <unordered_map>
#include <memory>
#include <opencv2/opencv.hpp>
#include <eigen3/Eigen/Dense>
#include <fnr_slam/VideoStream.h>
#include <fnr_slam/data_structures/Graph.h>

// each camera streams images
// each camera is identified by its frame id
// each frame id has an associated transformation matrix
namespace fnr_slam {
	class FNRSLAM {

		private:
			std::shared_ptr<fnr_slam::Graph> graph = nullptr;
			std::unordered_map<std::string,std::shared_ptr<fnr_slam::VideoStream>> streams; // keep a stream object for each frame id

		public:
			FNRSLAM(time_t max_node_age);
			~FNRSLAM();
			void setCameraTf(std::string frame_id, Eigen::Matrix<double, 3, 4> Rt);
			void setCameraIntrinsics(std::string frame_id, Eigen::Matrix3d K);
			void feedDepthImage(std::string frame_id, cv::Mat image);
			void feedColorImage(std::string frame_id, cv::Mat image);
	};
}

#endif
