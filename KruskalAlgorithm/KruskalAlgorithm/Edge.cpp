#include "Edge.h"

Edge::Edge(const shared_ptr<Vertex> &_startVertex, const shared_ptr<Vertex> &_targetVertex, double _weight)
	: weight(_weight)
	, startVertex(_startVertex)
	, targetVertex(_targetVertex)
{

}

double Edge::getWeight() const
{
	return weight;
}

shared_ptr<Vertex> Edge::getStartVertex() const
{
	return startVertex;
}

shared_ptr<Vertex> Edge::getTargetVertex() const
{
	return targetVertex;
}

bool Edge::operator<(const Edge &other) const
{
	return weight < other.weight;
}
