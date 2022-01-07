#include <iostream>
#include <list>
#include <memory>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Node;
using NODE = shared_ptr<Node>;

class Node
{
public:
	int nodeId;
	list<NODE> adjacent;	
	Node(int id):nodeId(id){}

	bool operator==(const Node& node)
	{
		return nodeId == node.nodeId;
	}
};

class myGraph
{
private:
	unordered_map<int, NODE> nodeLookup;

	NODE getNode(int id) { return nodeLookup.find(id) != nodeLookup.end() ? nodeLookup.at(id) : nullptr; }
	bool hasPathDFS(NODE source, NODE destination, unordered_set<int> &visited, int level = 0);
	bool hasPathBFS(NODE source, NODE destination);

public:
	void addEdge(int source, int destination);
	bool hasPathDFS(int source, int destination);
	bool hasPathBFS(int source, int destination);
};

void myGraph::addEdge(int source, int destination)
{
	NODE s = getNode(source);
	if (s == nullptr)
	{
		s = make_shared<Node>(source);
		nodeLookup[source] = s;
	}
		 
	NODE d = getNode(destination);
	if (d == nullptr)
	{
		d = make_shared<Node>(destination);
		nodeLookup[destination] = d;
	}		 

	s->adjacent.push_back(d);
}

bool myGraph::hasPathDFS(int source, int destination)
{
	NODE s = getNode(source);
	NODE d = getNode(destination);

	unordered_set<int> visited;
	int level = 0;
	return ((s != nullptr) && (d != nullptr)) ? hasPathDFS(s, d, visited, level) : false;
}

bool myGraph::hasPathDFS(NODE source, NODE destination, unordered_set<int> &visited, int level)
{
	
	if (visited.find(source->nodeId) != visited.end())
	{
		// node id is present, discontinue
		return false;
	}

	visited.insert(source->nodeId);
	for (int i = 0; i < level; i++)
		cout << "\t";
	cout << source->nodeId << endl;

	if (source == destination)
		return true;

	for (NODE child : source->adjacent)
	{
		if (hasPathDFS(child, destination, visited, level+1))
		{
			return true;
		}
	}

	return false;
}

bool myGraph::hasPathBFS(int source, int destination)
{
	NODE s = getNode(source);
	NODE d = getNode(destination);
	return (s != nullptr && d != nullptr) ? hasPathBFS(s, d) : false;
}

bool myGraph::hasPathBFS(NODE source, NODE destination)
{
	list<NODE> nextToVisit;
	unordered_set<int> visited;
	nextToVisit.push_back(source);

	while (!nextToVisit.empty())
	{
		NODE node = nextToVisit.front();
		nextToVisit.pop_front();
		if (node == destination)
		{
			return true;
		}

		if (visited.find(node->nodeId) != visited.end())
		{
			continue;
		}
		visited.insert(node->nodeId);
		
		//cout << node->nodeId << endl;

		for (NODE child : node->adjacent)
		{
			nextToVisit.push_back(child);
		}
	}

	return false;
}

int main()
{
	myGraph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(1, 3);
	g.addEdge(3, 3);
	//cout << "0-3 = " << (g.hasPathDFS(0, 3) == true ? "true" : "false") << endl;
	//cout << "3-2 = " << (g.hasPathDFS(3, 2) == true ? "true" : "false") << endl;
	cout << "3-1 = " << (g.hasPathDFS(3, 1) == true ? "true" : "false") << endl;
	cout << "2-3 = " << (g.hasPathBFS(2, 3) == true ? "true" : "false") << endl;
	//cout << "1-3 = " << (g.hasPathDFS(1, 3) == true ? "true" : "false") << endl;
	//cout << "1-3 = " << (g.hasPathBFS(1, 3) == true ? "true" : "false") << endl;
	//cout << "0-1 = " << (g.hasPathDFS(0, 1) == true ? "true" : "false") << endl;
	return 0;
}