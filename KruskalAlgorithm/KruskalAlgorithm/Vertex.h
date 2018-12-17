#pragma once
#include <string>
#include <memory>
#include <ostream>
using std::string;
using std::shared_ptr;
using std::ostream;

class Node;

class Vertex
{
	string name;
	shared_ptr<Node> node;

public:
	Vertex(string const &name);

	void setNode(shared_ptr<Node> const &node);
	shared_ptr<Node> getNode() const;

	// to string
	friend ostream &operator<<(ostream &strm, const Vertex& vert);
};

