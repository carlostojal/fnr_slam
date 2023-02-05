#include <fnr_slam/data_structures/Node.h>

Node::Node() {
    this->timestamp = time(nullptr);
}

void Node::setTransformToPrev(Eigen::Affine3d tf) {
	this->transformToPrev = tf;
}

Eigen::Affine3d Node::getTransformToPrev() {
	return this->transformToPrev;
}

void Node::setTransformToStart(Eigen::Affine3d tf) {
	this->transformToStart = tf;
}

Eigen::Affine3d Node::getTransformToStart() {
	return this->transformToStart;
}
