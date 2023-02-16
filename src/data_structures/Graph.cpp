#include <fnr_slam/data_structures/Graph.h>

fnr_slam::Graph::Graph(time_t max_node_age) {
	this->max_node_age = max_node_age;

	this->head = std::make_shared<fnr_slam::Node>();
	this->head->prev = this->head; // the previous of the head is the last node
	this->head->next = this->head;
}

fnr_slam::Graph::~Graph() {
	std::shared_ptr<fnr_slam::Node> cur = this->head->next;
	std::shared_ptr<fnr_slam::Node> old_head = this->head;

	while(cur->next != old_head) {
		cur->prev.reset();
		cur = cur->next;
	}

}

void fnr_slam::Graph::addNode(std::shared_ptr<fnr_slam::Node> node) {
	this->head->prev->next = node;
	node->prev = this->head->prev; // the previous of the node is the tail
	node->next = this->head; // the tail points to the head
}
