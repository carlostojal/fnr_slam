#ifndef FNRSLAM_H_
#define FNRSLAM_H_

#include <iostream>
#include <opencv2/opencv.hpp>
#include <eigen3/Eigen/Dense>
#include <fnr_slam/VideoStream.h>
#include <fnr_slam/data_structures/Graph.h>
#include <fnr_slam/data_structures/HashTable.h>

// each camera streams images
// each camera is identified by its frame id
// each frame id has an associated transformation matrix

class FNRSLAM {

	private:
		Graph *graph;
		HashTable<std::string,VideoStream> streams; // keep a stream for each frame id

	public:
		void setCameraTf(std::string frame_id, Eigen::Affine3d tf);
		void setCameraIntrinsics(std::string frame_id, Eigen::Matrix3d intrinsics);
		void feedImage(std::string frame_id, cv::Mat image);
};

#endif
