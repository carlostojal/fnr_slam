#ifndef FNRSLAM_H_
#define FNRSLAM_H_

#include <iostream>
#include <opencv2/opencv.hpp>
#include <eigen3/Eigen/Dense>
#include <fnr_slam/data_structures/Graph.h>

// each camera streams images
// each camera is identified by its frame id
// each frame id has an associated transformation matrix
class FNRSLAM {

	private:
		Graph *graph;
		// TODO: create an hashtable to relate frame IDs with
		// camera intrinsics and transformation matrix

	public:
		void setCameraTf(std::string frame_id, Eigen::Affine3d tf);
		void setCameraIntrinsics(std::string frame_id, Eigen::Matrix3d intrinsics);
		void feedImage(std::string frame_id, cv::Mat image);
};

#endif
