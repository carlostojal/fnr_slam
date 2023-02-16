#ifndef GRAPH_H_
#define GRAPH_H_

#include <memory>
#include <fnr_slam/data_structures/Node.h>

// this class describes the SLAM graph
class Graph {
	private:
		std::shared_ptr<Node> head = nullptr; // the starting state
		time_t max_node_age;
	
	public:
		Graph(time_t max_node_age);
		~Graph();

		void addNode(std::shared_ptr<Node> node);
};

#endif
