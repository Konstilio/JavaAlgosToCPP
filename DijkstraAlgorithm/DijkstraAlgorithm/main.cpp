#include <vector>
#include <memory>
#include <iostream>
#include "ShortestPath.h"
using std::vector;
using std::shared_ptr;
using std::make_shared;


int main()
{
	vector<shared_ptr<Vertex>> vertexList;
	vertexList.push_back(make_shared<Vertex>("0"));
	vertexList.push_back(make_shared<Vertex>("1"));
	vertexList.push_back(make_shared<Vertex>("2"));
	vertexList.push_back(make_shared<Vertex>("3"));
	
	shared_ptr<Edge> edge01 = make_shared<Edge>(1, vertexList[0], vertexList[1]);
	shared_ptr<Edge> edge10 = make_shared<Edge>(7, vertexList[1], vertexList[0]);
	shared_ptr<Edge> edge12 = make_shared<Edge>(2, vertexList[1], vertexList[2]);
	shared_ptr<Edge> edge23 = make_shared<Edge>(3, vertexList[2], vertexList[3]);
	shared_ptr<Edge> edge03 = make_shared<Edge>(10, vertexList[0], vertexList[3]);

	vertexList[0]->addNeighbour(edge01.get());
	vertexList[0]->addNeighbour(edge03.get());
	vertexList[1]->addNeighbour(edge10.get());
	vertexList[1]->addNeighbour(edge12.get());
	vertexList[2]->addNeighbour(edge23.get());

	ShortestPath sp;
	sp.computePaths(vertexList[0]);
	
	auto path = sp.getShortestPath(vertexList[3]);
	for (Vertex *v : path)
		std::cout << *v << ' ';

	return 0;
}