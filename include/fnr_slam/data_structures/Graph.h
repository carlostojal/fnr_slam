#ifndef GRAPH_H_
#define GRAPH_H_

#include <fnr_slam/data_structures/Node.h>

// this class describes the SLAM graph
class Graph {
	private:
		Node *head; // the starting state
		time_t max_node_age;
	
	public:
		Graph(time_t max_node_age);
		~Graph();

		void addNode(Node *node);
};

#endif
