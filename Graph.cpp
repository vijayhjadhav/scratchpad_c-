#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Vertex
{
	int m_id;
	vector<Vertex *> m_adjacents;
public:
	Vertex(int id) : m_id(id) {}
	bool operator==(Vertex* other);
	int getId() { return m_id; }
	vector<Vertex *> &getAdjacents() { return m_adjacents; }
	void addAdjacent(Vertex *Adjacent) { m_adjacents.push_back(Adjacent);}
};

bool Vertex::operator==(Vertex* other)
{
	if (other != NULL)
	{
		if (m_id != other->getId())
			return false;
		vector<Vertex *> othersAdjacents = other->getAdjacents();
		if (m_adjacents.size() != othersAdjacents.size())
			return false;
		for (auto index = 0; index < m_adjacents.size(); index++)
		{
			if (m_adjacents[index]->getId() != othersAdjacents[index]->getId())
				return false;
		}
	}
	return true;
}

class Graph
{
	map<int, Vertex *> Vertices;	
	map<int, bool> VisitedVertices;
	bool hasPathDFS(Vertex *source, Vertex *destination);
public:
	Vertex *getVertex(int id);
	void addEdge(int vId1, int vId2);
	void printGraph();
	bool hasPathBFS(int vId1, int vId2);
	bool hasPathDFS(int vId1, int vId2);
	void resetVisitedVertices(bool bVal);
};

void Graph::resetVisitedVertices(bool bVal)
{
	int numVertices = Vertices.size();
	for (auto index = 0; index < numVertices; index++)
		VisitedVertices[index] = bVal;
}

bool Graph::hasPathDFS(Vertex *source, Vertex *destination)
{
	if (VisitedVertices[source->getId()])
		return false;
	
	VisitedVertices[source->getId()] = true;
	
	if (source == destination)
		return true;

	vector<Vertex *> adjacents = source->getAdjacents();
	for (auto index = 0; index < adjacents.size(); index++)
	{
		if (hasPathDFS(adjacents[index], destination))
		{
			return true;
		}
	}
	return false;
}

bool Graph::hasPathDFS(int vId1, int vId2)
{
	Vertex *source = getVertex(vId1);
	Vertex *destination = getVertex(vId2);
	resetVisitedVertices(false);
	return hasPathDFS(source, destination);
}

bool Graph::hasPathBFS(int sourceID, int destinationID)
{
	queue<Vertex *> nextToVisit;
	resetVisitedVertices(false);
	Vertex *source = getVertex(sourceID);
	Vertex *destination = getVertex(destinationID);
	nextToVisit.push(source);
	while (!nextToVisit.empty())
	{
		Vertex *currentVertex = nextToVisit.front();
		nextToVisit.pop();

		if (VisitedVertices[currentVertex->getId()])
			continue;

		VisitedVertices[currentVertex->getId()] = true;

		if (currentVertex == destination)
			return true;
		
		vector<Vertex *> adjacents = currentVertex->getAdjacents();
		for (auto index = 0; index < adjacents.size(); index++)
		{
			nextToVisit.push(adjacents[index]);
		}
	}
	return false;
}

void Graph::printGraph()
{
	for (auto itr = Vertices.begin(); itr != Vertices.end(); itr++)
	{
		cout << "Vertex " << itr->first << " : ";
		vector<Vertex *> vecAdjacents = itr->second->getAdjacents();
		for (auto itr2 = vecAdjacents.begin(); itr2 != vecAdjacents.end(); itr2++)
		{
			cout << " --> " << (*itr2)->getId();
		}
		cout << endl;
	}
}

void Graph::addEdge(int vId1, int vId2)
{
	Vertex *v1 = getVertex(vId1);
	Vertex *v2 = getVertex(vId2);
	v1->addAdjacent(v2);
	v2->addAdjacent(v1);
}

Vertex *Graph::getVertex(int id)
{
	if (Vertices.count(id) == 0)
	{
		Vertex *newVertex = new Vertex(id);
		Vertices[id] = newVertex;		
	}
	return Vertices[id];
}

int main()
{
	Graph obj;
	obj.addEdge(0, 1);
	obj.addEdge(0, 4);
	obj.addEdge(1, 2);
	obj.addEdge(1, 3);
	obj.addEdge(1, 4);
	obj.addEdge(2, 3);
	obj.addEdge(3, 4);
	obj.printGraph();

	if (obj.hasPathDFS(0, 4))
		cout << "0 has path to 4" << endl;
	else
		cout << "0 do not have path to 4" << endl;
	return 0;
}