#include <fnr_slam/data_structures/Node.h>

fnr_slam::Node::Node() {
    this->timestamp = time(nullptr);
}

void fnr_slam::Node::setTransformToPrev(Eigen::Affine3d tf) {
	this->transformToPrev = tf;
}

Eigen::Affine3d fnr_slam::Node::getTransformToPrev() {
	return this->transformToPrev;
}

void fnr_slam::Node::setTransformToStart(Eigen::Affine3d tf) {
	this->transformToStart = tf;
}

Eigen::Affine3d fnr_slam::Node::getTransformToStart() {
	return this->transformToStart;
}
