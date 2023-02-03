#include <fnr_slam/data_structures/Node.h>

Node::Node(Node *prev) {
    this->prev = prev;
    this->timestamp = time(nullptr);
}
