#include "ShortestPath.h"
#include <set>

void ShortestPath::computePaths(shared_ptr<Vertex> sourceVertex)
{
	auto fCompare = [&](shared_ptr<Vertex> const &l, shared_ptr<Vertex> const &r)
	{
		return *l < *r;
	};

	sourceVertex->setMinDistance(0.);
	std::multiset<shared_ptr<Vertex>, decltype(fCompare)> queue(fCompare);
	queue.insert(sourceVertex);

	while (!queue.empty())
	{
		auto iBegin = queue.begin();
		auto actualVertex = *iBegin;
		queue.erase(iBegin);

		for (const Edge *edge : actualVertex->getAdjacenciesList())
		{
			shared_ptr<Vertex> from = edge->getStartVertex();
			shared_ptr<Vertex> to = edge->getTargetVertex();

			double newDistance = actualVertex->getMinDistance() + edge->getWeight();
			if (newDistance < to->getMinDistance()) {

				// remove to from queue
				for (auto it = queue.begin(); it != queue.end(); ++it)
				{
					if ((*it)->getName() == to->getName())
					{
						queue.erase(it);
						break;
					}
				}
				to->setMinDistance(newDistance);
				to->setPredecessor(actualVertex.get());
				queue.insert(to);
			}
		}
	}
}

vector<Vertex *> ShortestPath::getShortestPath(shared_ptr<Vertex> sourceVertex) const
{
	vector<Vertex *> path;
	for (Vertex *it = sourceVertex.get(); it != nullptr; it = it->getPredecessor())
		path.push_back(it);

	std::reverse(path.begin(), path.end());
	return path;
}
