#include "DisjointSet.h"

Node::Node(int rank, int _id, Node *_parent /*= nullptr*/)
	: height(rank)
	, id(_id)
	, parent(_parent)
{

}

// Node

int Node::getId() const
{
	return id;
}

int Node::getHeight() const
{
	return height;
}

void Node::setHeight(int height)
{
	this->height = height;
}

Node *Node::getParent() const
{
	return parent;
}

void Node::setParent(Node *parent)
{
	this->parent = parent;
}

// DisjointSet

DisjointSet::DisjointSet(vector<shared_ptr<Vertex>> const &vertices)
{
	rootNodes.resize(vertices.size());
	makeSets(vertices);
}

int DisjointSet::find(shared_ptr<Node> node)
{
	Node *current = node.get();

	/* Ride the pointer up to the root node */
	while (current->getParent() != nullptr)
		current = current->getParent();
	Node *root = current;

	/*
	* Ride the pointer up to the root node again, but make each node below
	* a direct child of the root. This alters the tree such that future
	* calls will reach the root more quickly. "path comression"
	*/
	current = node.get();
	while (current != root) {
		Node *temp = current->getParent();
		current->setParent(root);
		current = temp;
	}

	return root->getId();
}

void DisjointSet::unite(shared_ptr<Node> node1, shared_ptr<Node> node2)
{
	int index1 = find(node1);
	int index2 = find(node2);

	/* Are these nodes already part of the same set? */
	if (index1 == index2)
		return;

	/* Get the root nodes of each set (this will run in constant time) */
	shared_ptr<Node> root1 = rootNodes[index1];
	shared_ptr<Node> root2 = rootNodes[index2];

	/* Attach the smaller tree to the root of the larger tree ez a "union by height" */
	if (root1->getHeight() < root2->getHeight()) {
		root1->setParent(root2.get());
	}
	else if (root1->getHeight() > root2->getHeight()) {
		root2->setParent(root1.get());
	}
	else {
		root2->setParent(root1.get());
		root1->setHeight(root1->getHeight() + 1);
	}

	--setCount;
}

void DisjointSet::makeSets(const vector<shared_ptr<Vertex>> &vertices)
{
	for (auto v : vertices)
		makeSet(v);
}

void DisjointSet::makeSet(const shared_ptr<Vertex> &vertex)
{
	auto node = std::make_shared<Node>(0, nodeCount);
	vertex->setNode(node);
	rootNodes[nodeCount] = node;
	++setCount;
	++nodeCount;
}
