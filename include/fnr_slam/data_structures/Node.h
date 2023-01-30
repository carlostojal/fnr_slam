#ifndef NODE_H_
#define NODE_H_

#include <ctime>

// this class defines the node of the SLAM graph
// each node represents a robot state
class Node {
	
	private:
		Node *prev = nullptr;
		Node *next = nullptr;
		time_t timestamp;
};

#endif
