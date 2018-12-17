#pragma once
#include "Vertex.h"
class Edge
{
	double weight;
	shared_ptr<Vertex> startVertex;
	shared_ptr<Vertex> targetVertex;

public:

	Edge(const shared_ptr<Vertex> &startVertex, const shared_ptr<Vertex> &targetVertex, double weight);


	double getWeight() const;

	shared_ptr<Vertex> getStartVertex() const;
	shared_ptr<Vertex> getTargetVertex() const;

	bool operator<(const Edge &other) const;
};

