#pragma once

#include <vector>
#include <memory>
#include "Vertex.h"
using std::vector;
using std::shared_ptr;

class Node
{
private:

	int height = 0;
	int id = -1;
	Node *parent = nullptr;

public:

	Node(int rank, int id, Node *parent = nullptr);

	int getId() const;

	int getHeight() const;
	void setHeight(int height);

	Node *getParent() const;
	void setParent(Node *parent);
};

class DisjointSet
{
	int nodeCount = 0;
	int setCount = 0;
	vector<shared_ptr<Node>> rootNodes;

public:

	DisjointSet(const vector<shared_ptr<Vertex>> &vertices);

	/*
	* Returns the index of the set that n is currently in. The index of the
	* root node of each set uniquely identifies the set. This is used to
	* determine whether two elements are in the same set.
	*/
	int find(shared_ptr<Node> node);

	/*
	* Combines the sets containing nodes i and j.
	*/
	void unite(shared_ptr<Node> node1, shared_ptr<Node> node2);

private:

	/*
	* Takes a list of n vertices and creates n disjoint singleton sets.
	*/
	void makeSets(const vector<shared_ptr<Vertex>> &vertices);

	/*
	* Creates a singleton set containing one vertex.
	*/
	void makeSet(const shared_ptr<Vertex> &vertex);
};

