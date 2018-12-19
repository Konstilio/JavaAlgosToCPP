#pragma once
#include <string>
#include <memory>
#include <ostream>
#include <vector>
#include <numeric>
using std::string;
using std::shared_ptr;
using std::ostream;
using std::vector;

class Node;
class Edge;

class Vertex
{
	string name;
	vector<Edge *> adjacenciesList;
	Vertex *predecessor = nullptr;
	double minDistance = std::numeric_limits<double>::max();

public:
	Vertex(string const &name);

	string getName() const;
	
	void addNeighbour(Edge *edge);
	const vector<Edge *> &getAdjacenciesList();

	Vertex *getPredecessor() const;
	void setPredecessor(Vertex *predecessor);

	double getMinDistance() const;
	void setMinDistance(double distance);

	// to string
	friend ostream &operator<<(ostream &strm, const Vertex& vert);
	
	bool operator<(const Vertex &other) const;
};

