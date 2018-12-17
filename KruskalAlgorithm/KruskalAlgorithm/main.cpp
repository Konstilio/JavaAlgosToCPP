#include <vector>
#include <memory>
#include "KruskalAlgorithm.h"
using std::vector;
using std::shared_ptr;
using std::make_shared;


int main()
{
	vector<shared_ptr<Vertex>> vertexList;
	vertexList.push_back(make_shared<Vertex>("A"));
	vertexList.push_back(make_shared<Vertex>("B"));
	vertexList.push_back(make_shared<Vertex>("C"));
	vertexList.push_back(make_shared<Vertex>("D"));
	vertexList.push_back(make_shared<Vertex>("E"));
	vertexList.push_back(make_shared<Vertex>("F"));
	vertexList.push_back(make_shared<Vertex>("G"));
	vertexList.push_back(make_shared<Vertex>("H"));

	vector<shared_ptr<Edge>> edgeList;
	edgeList.push_back(make_shared<Edge>(vertexList[0], vertexList[1], 3));
	edgeList.push_back(make_shared<Edge>(vertexList[0], vertexList[2], 2));
	edgeList.push_back(make_shared<Edge>(vertexList[0], vertexList[3], 5));
	edgeList.push_back(make_shared<Edge>(vertexList[1], vertexList[5], 13));
	edgeList.push_back(make_shared<Edge>(vertexList[1], vertexList[3], 2));
	edgeList.push_back(make_shared<Edge>(vertexList[2], vertexList[4], 5));
	edgeList.push_back(make_shared<Edge>(vertexList[2], vertexList[3], 2));
	edgeList.push_back(make_shared<Edge>(vertexList[3], vertexList[4], 4));
	edgeList.push_back(make_shared<Edge>(vertexList[3], vertexList[5], 6));
	edgeList.push_back(make_shared<Edge>(vertexList[3], vertexList[6], 3));
	edgeList.push_back(make_shared<Edge>(vertexList[4], vertexList[6], 6));
	edgeList.push_back(make_shared<Edge>(vertexList[5], vertexList[6], 2));
	edgeList.push_back(make_shared<Edge>(vertexList[5], vertexList[7], 3));
	edgeList.push_back(make_shared<Edge>(vertexList[6], vertexList[7], 6));

	KruskalAlgorithm kruskalAlgorithm;
	kruskalAlgorithm(vertexList, edgeList);

	return 0;
}