#include "Node.h"
#include <iostream>
using namespace std;

Node::Node() {
	val = 0;
	next = NULL;
	prev = NULL;
}
Node::Node(int x, Node* a, Node* b) {
	val = x;
	next = a;
	prev = b;
}
Node* Node::getNext() {
	return next;

}

int Node::getVal() {
	return val;
}
void Node::setVal(int i) {
	val = i;

}
