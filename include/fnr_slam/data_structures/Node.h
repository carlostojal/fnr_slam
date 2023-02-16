#ifndef NODE_H_
#define NODE_H_

#include <ctime>
#include <memory>
#include <opencv2/opencv.hpp>
#include <eigen3/Eigen/Dense>

// this class defines the node of the SLAM graph
// each node represents a robot state
namespace fnr_slam {
	class Node {
		
		private:
			time_t timestamp;
			Eigen::Affine3d transformToPrev; // geometric transformation between this node and the previous
			Eigen::Affine3d transformToStart; // geometric transformation between this node and the first of the graph
			cv::Mat lastImage; // the last image


		public:
			Node();
			std::shared_ptr<fnr_slam::Node> prev = nullptr;
			std::shared_ptr<fnr_slam::Node> next = nullptr;

			void setTransformToPrev(Eigen::Affine3d tf);
			Eigen::Affine3d getTransformToPrev();
			void setTransformToStart(Eigen::Affine3d tf);
			Eigen::Affine3d getTransformToStart();
	};
}

#endif
