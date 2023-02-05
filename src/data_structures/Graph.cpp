#include <fnr_slam/data_structures/Graph.h>

Graph::Graph(time_t max_node_age) {
	this->max_node_age = max_node_age;

	this->head = new Node();
	this->head->prev = this->head; // the previous of the head is the last node
	this->head->next = this->head;
}

Graph::~Graph() {
	// first case: the graph is empty
	if(this->head->next == this->head) {
		delete this->head;
	} else {
		Node *old_head = this->head; // only used to keep referece of the end of the graph
		Node *cur = this->head->next;
		while(cur != old_head) {
			delete cur->prev;
		}
		// TODO: this leaves a memory leak
	}
}

void Graph::addNode(Node *node) {
	this->head->prev->next = node;
	node->prev = this->head->prev; // the previous of the node is the tail
	node->next = this->head; // the tail points to the head
}
