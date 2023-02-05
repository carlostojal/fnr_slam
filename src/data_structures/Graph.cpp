#include <fnr_slam/data_structures/Graph.h>

Graph::Graph(time_t max_node_age) {
	this->max_node_age = max_node_age;

	this->head = new Node();
	this->head->prev = this->head; // the previous of the head is the last node
	this->head->next = this->head;
}

Graph::~Graph() {
	Node *cur = this->head->next;
	Node *old_head = this->head; // preserve the head pointer
	while(cur->next != old_head) {
		// delete the previous of the current
		delete cur->prev;
		cur = cur->next; // go to the next
	}
	// reached the end of the graph, delete the current
	delete cur;
}

void Graph::addNode(Node *node) {
	this->head->prev->next = node;
	node->prev = this->head->prev; // the previous of the node is the tail
	node->next = this->head; // the tail points to the head
}
