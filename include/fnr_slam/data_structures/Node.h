#ifndef NODE_H_
#define NODE_H_

#include <ctime>
#include <opencv2/opencv.hpp>
#include <eigen3/Eigen/Dense>

// this class defines the node of the SLAM graph
// each node represents a robot state
class Node {
	
	private:
		Node *prev = nullptr;
		Node *next = nullptr;
		time_t timestamp;
		Eigen::Matrix3d transformToPrev; // geometric transformation between this node and the previous
		cv::Mat lastImage; // the last image


	public:
		Node(Node *prev);
};

#endif
