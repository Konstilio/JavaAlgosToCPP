#include "KruskalAlgorithm.h"
#include "DisjointSet.h"
#include <algorithm>
#include <iostream>

KruskalAlgorithm::KruskalAlgorithm()
{
}


void KruskalAlgorithm::operator()(std::vector<shared_ptr<Vertex>> const &vertexList, std::vector<shared_ptr<Edge>> edgeList) const
{
	DisjointSet disjointSet{ vertexList };

	/* Create a list of edges */
	std::vector<shared_ptr<Edge>> tree;

	/* C++'s modified version of quicksort - average time is nlog(n) time*/
	std::sort(edgeList.begin(), edgeList.end(), [](const shared_ptr<Edge> &l, const shared_ptr<Edge> &r) {return *l < *r; });

	/* Kruskal's algorithm */
	for (shared_ptr<Edge> e : edgeList) {
		auto u = e->getStartVertex();
		auto v = e->getTargetVertex();
		if (disjointSet.find(u->getNode()) != disjointSet.find(v->getNode())) {
			/* Vertices v and u are not in the same component */
			tree.push_back(e);

			/* Union them in the tree */
			disjointSet.unite(u->getNode(), v->getNode());
		}
	}

	for (auto edge : tree) {
		std::cout << *edge->getStartVertex() << '-' << *edge->getTargetVertex() << '\n';
	}
}
