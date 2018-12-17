#include "Vertex.h"
#include "DisjointSet.h"


Vertex::Vertex(string const &name)
{
	this->name = name;
}

void Vertex::setNode(shared_ptr<Node> const &node)
{
	this->node = node;
}

shared_ptr<Node> Vertex::getNode() const
{
	return node;
}

ostream &operator<<(ostream &strm, const Vertex& vert)
{
	strm << vert.name;
	return strm;
}

