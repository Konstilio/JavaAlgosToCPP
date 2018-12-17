#pragma once

#include <vector>
#include "Edge.h"

class KruskalAlgorithm
{
public:
	KruskalAlgorithm();
	
	void operator()(std::vector<shared_ptr<Vertex>> const &vertexList, std::vector<shared_ptr<Edge>> edgeList) const;
};

