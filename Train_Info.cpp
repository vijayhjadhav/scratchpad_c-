#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
using namespace std;

// Data structure use to store the town information
typedef struct town
{
	int townNumber;
	int distance;	
}TOWN;

// Data structure to store the route information
typedef struct route
{
	int source_vertex;
	int dest_vertex;
	int distance;
}ROUTE;

// Data structure to store the information of shortest distance for each vertex from given source vertex
typedef struct shortest_path_table
{
	int vertex_number;
	bool known;
	int distance;
	int path;
}TABLE_SHORTEST_DISTANCE;

class route_info
{
public:	
	route_info(){};
	~route_info();
	void init(string input_routes);
	void print_distance_route(string route);
	void printNumTrips(char source, char dest, int max_stops);
	void printNumTrips_shorter_or_equal(char source, char dest, int max_stops);
	void print_shortest_distance(char source, char dest);
	void printNumRoutes_with_shorter_distance(char source, char dest, int max_distance);

private:
	void create_route_list(string input_routes);
	void map_name_number(char name, int &vertex_number);
	void create_adjacency_list();
	int get_distance_route(string route);
	int get_distance_route(int source, int vertex);
	int getNumTrips(char source, char dest, int max_stops);
	int getNumTrips_shorter_or_equal(char source, char dest, int max_stops);
	int getNumRoutes_with_shorter_distance(char source, char dest, int max_distance);
	void init_table(int source_vertex);
	int get_length_shortest_path(int dest_vertex);	
	int minimum_distance_vertex();
	void compute_shortest_path_all(char source);	
	void print_shortest_path(char source, char dest);
	void print_shortest_path_r(int vertex, vector<TABLE_SHORTEST_DISTANCE> &table);	
	void findAllPaths(char source, char dest, vector<vector<int>> &list_paths);
	void findAllPaths_r(int source, int dest, vector<bool> &visited, vector<int> &paths, vector<vector<int>> &list_paths);	
	
private:
	map<char, int> m_townName_townNumber;  // Mapping between town name and number
	vector<ROUTE> m_routes;   // list of routes
	map<int, vector<TOWN *>> m_adjacency_list;  // Adjacency list for each vertex
	vector<TABLE_SHORTEST_DISTANCE> m_table;	// Table to store the shortest distance for each vertex from specified source vertex
};

// Destructor
route_info::~route_info()
{
	// clear the adjacency list
	auto itrMap = m_adjacency_list.begin();
	while(itrMap != m_adjacency_list.end())
	{
		auto itrVector = itrMap->second.begin();
		while(itrVector != itrMap->second.end())
		{
			if((*itrVector) != NULL)
				delete (*itrVector);
			itrVector++;
		}
		itrMap->second.clear();
		itrMap++;
	}	
}

// Initialises the graph
void route_info::init(string input)
{
	if(!input.empty())
	{
		create_route_list(input);
		create_adjacency_list();
	}
}

// Extracts the route data from the given input and add it to route list. 
void route_info::create_route_list(string input)
{
	istringstream ss(input);
	int vertex_number = 0;
	vector<string> tokens;
	copy(istream_iterator<string>(ss), istream_iterator<string>(), back_inserter(tokens));
	vector<string>::iterator itr = tokens.begin();
	while(itr != tokens.end())
	{	
		ROUTE route;
		
		map_name_number((*itr)[0], vertex_number);
		route.source_vertex = m_townName_townNumber[(*itr)[0]];
		
		map_name_number((*itr)[1], vertex_number);
		route.dest_vertex = m_townName_townNumber[(*itr)[1]];	
		
		int pos = (*itr).find(',');
		if(pos != string::npos)
		{
			route.distance = stoi((*itr).substr(2, pos));
		}
		else			
			route.distance = stoi((*itr).substr(2));
		
		m_routes.push_back(route);
		itr++;
	}
}

// Maps town name to town number
void route_info::map_name_number(char name, int &vertex_number)
{	
	if(m_townName_townNumber.find(name) == m_townName_townNumber.end())
	{
		m_townName_townNumber[name] = vertex_number++;
	}
}

// Creates adjacency list for each vertex in the graph
void route_info::create_adjacency_list()
{
	vector<ROUTE>::iterator itr = m_routes.begin();
	while(itr != m_routes.end())
	{
		TOWN *tn = new TOWN();
		tn->townNumber = (*itr).dest_vertex;
		tn->distance = (*itr).distance;
		auto itm = m_adjacency_list.find((*itr).source_vertex);
		if(itm == m_adjacency_list.end())
		{
			m_adjacency_list[(*itr).source_vertex].push_back(tn);
		}
		else
		{
			(*itm).second.push_back(tn);
		}
		itr++;
	}
}

int route_info::get_distance_route(int source, int dest)
{
	int distance = -1;
	auto itr = m_routes.begin();
	while(itr != m_routes.end())
	{
		if((source == (*itr).source_vertex) && (dest == (*itr).dest_vertex))
		{
			distance = (*itr).distance;				
			break;
		}
		itr++;
	}
	return distance;
}

// returns the total distance for the given route
int route_info::get_distance_route(string route)
{
	int totaldistance = 0;
	vector<char> rt;
	string::iterator itr = route.begin();
	while(itr != route.end())
	{
		if((*itr) != '-')
			rt.push_back(*itr);

		itr++;
	}

	vector<char>::iterator crt = rt.begin();
	bool route_found = false;
	////////////////////////////////////////////
	while(crt != rt.end() && (crt+1) != rt.end())
	{
		route_found = false;		
		if((m_townName_townNumber.find((*crt)) != m_townName_townNumber.end())
			&& (m_townName_townNumber.find((*(crt+1))) != m_townName_townNumber.end())) 
		{
			int distance = get_distance_route(m_townName_townNumber[(*crt)], m_townName_townNumber[*(crt+1)]);
			if(distance != -1)
			{				
				totaldistance = totaldistance + distance;
				route_found = true;
			}			
		}

		if(route_found == false)
			break;
		crt++;
	}

	////////////////////////////////////////////
	/*while(crt != rt.end() && (crt+1) != rt.end())
	{
		route_found = false;		
		size_t size = m_routes.size();
		for(auto i = 0; i < size; i++)
		{
			if((m_townName_townNumber.find((*crt)) != m_townName_townNumber.end())
				&& (m_townName_townNumber.find((*(crt+1))) != m_townName_townNumber.end())) 
			{
				if((m_townName_townNumber[(*crt)] == m_routes[i].source_vertex) && (m_townName_townNumber[*(crt+1)] == m_routes[i].dest_vertex))
				{
					distance = distance + m_routes[i].distance;	
					route_found = true;
					break;
				}
			}			
		}

		if(route_found == false)
			break;
		crt++;
	}*/

	return route_found == true? totaldistance : -1;
}

// Displays the total distance for the given route
void route_info::print_distance_route(string route)
{
	int distance = get_distance_route(route);
	if(distance == -1)
	{
		cout << "NO SUCH ROUTE" << endl;
	}
	else
	{
		cout << distance << endl;
	}
}

// Displays the shortest path from given source to destination.
void route_info::print_shortest_path(char source, char dest)
{	
	if((m_townName_townNumber.find(source) != m_townName_townNumber.end())
		&& (m_townName_townNumber.find(dest) != m_townName_townNumber.end()))
	{
		compute_shortest_path_all(source);
		print_shortest_path_r(m_townName_townNumber[dest], m_table);
		m_table.clear();
	}
	else
	{
		cout << "NO PATH EXIST" << endl;
	}	
}

void route_info::print_shortest_path_r(int vertex, vector<TABLE_SHORTEST_DISTANCE> &table)
{
	if(table[vertex].path != -1)
	{
		print_shortest_path_r(table[vertex].path, table);
		cout << " to ";
	}

	cout << vertex;
}

void route_info::print_shortest_distance(char source, char dest)
{
	int distance = -1;
	if((m_townName_townNumber.find(source) != m_townName_townNumber.end())
		&& (m_townName_townNumber.find(dest) != m_townName_townNumber.end()))
	{
		compute_shortest_path_all(source);
		distance = get_length_shortest_path(m_townName_townNumber[dest]);
	}
	
	if(distance == -1)
	{
		cout << "NO SUCH ROUTE" << endl;
	}
	else
	{
		cout << distance << endl;
		m_table.clear();
	}
}

// Initialises table use to store information about shortest distance for each vertex from given source vertex
void route_info::init_table(int source_vertex)
{
	int num_vertex = m_townName_townNumber.size();	
	for(auto i = 0; i < num_vertex; i++)
	{
		TABLE_SHORTEST_DISTANCE table_entry;
		table_entry.distance = INT_MAX;
		table_entry.known = false;
		table_entry.vertex_number = i;
		table_entry.path = -1;
		m_table.push_back(table_entry);
	}

	m_table[source_vertex].distance = 0;
}

// Returns a vertex with minimum distance
int route_info::minimum_distance_vertex()
{
	TOWN nearest_town;
	vector<TABLE_SHORTEST_DISTANCE>::iterator itrtable = m_table.begin();
	nearest_town.distance = INT_MAX;
	nearest_town.townNumber = -1;		
	while(itrtable != m_table.end())
	{
		if(!(*itrtable).known)
		{
			if((*itrtable).distance < nearest_town.distance)
			{
				nearest_town.distance = (*itrtable).distance;
				nearest_town.townNumber = (*itrtable).vertex_number;
			}
		}
		itrtable++;
	}
	return nearest_town.townNumber;
}

// Determines shortest for all the vertices from given source.
void route_info::compute_shortest_path_all(char source)
{
	if(m_townName_townNumber.find(source) != m_townName_townNumber.end())
	{
		init_table(m_townName_townNumber[source]);
		int num_vertex = m_table.size();
		int vertex;
		for(auto count = 0; count < num_vertex -1; count++) 
		{		
			vertex = minimum_distance_vertex();

			m_table[vertex].known = true;
			vector<TOWN *> list = m_adjacency_list[vertex];
			int adjacent_vertex;
			int adjacent_distance;
			for(vector<TOWN *>::iterator itr_adjacent = list.begin(); itr_adjacent != list.end(); itr_adjacent++)
			{
				adjacent_vertex = (*itr_adjacent)->townNumber;
				adjacent_distance = (*itr_adjacent)->distance;
				if(!m_table[adjacent_vertex].known)
				{
					if((m_table[vertex].distance + adjacent_distance) < m_table[adjacent_vertex].distance)
					{
						m_table[adjacent_vertex].distance = m_table[vertex].distance + adjacent_distance;
						m_table[adjacent_vertex].path = vertex;					
					}
				}			
			}	
		}
	}
}

// Gets number of trips between given source and destination with exactly max_stops
int route_info::getNumTrips(char source, char dest, int max_stops)
{
	vector<vector<int>> list_paths;
	findAllPaths(source, dest, list_paths);
	int numTrips = 0;
	auto itr = list_paths.begin();
	while(itr != list_paths.end())
	{
		if((*itr).size() == max_stops)
			numTrips++;
		itr++;
	}

	return numTrips;
}

// Displays number of trips between given source and destination with exactly max_stops
void route_info::printNumTrips(char source, char dest, int max_stops)
{
	int numTrips = getNumTrips(source, dest, max_stops);
	//cout << "Number of Trips from "<< source << " to " << dest << " with exactly " << max_stops << " : " << numTrips << endl;
	cout << numTrips << endl;
}

// Gets number of trips between given source and destination with maximum of max_stops
int route_info::getNumTrips_shorter_or_equal(char source, char dest, int max_stops)
{
	vector<vector<int>> list_paths;
	findAllPaths(source, dest, list_paths);
	int numTrips = 0;
	auto itr = list_paths.begin();
	while(itr != list_paths.end())
	{
		if((*itr).size() <= max_stops)
			numTrips++;
		itr++;
	}

	return numTrips;
}

// Displays number of trips between given source and destination with maximum of max_stops
void route_info::printNumTrips_shorter_or_equal(char source, char dest, int max_stops)
{
	int numTrips = getNumTrips_shorter_or_equal(source, dest, max_stops);
	cout << numTrips << endl;
}

// returns number of routes betwen source and destination with distance less than max_distance
int route_info::getNumRoutes_with_shorter_distance(char source, char dest, int max_distance)
{
	int numRoutes = 0;
	vector<vector<int>> list_paths;
	findAllPaths(source, dest, list_paths);	
	auto itr = list_paths.begin();
	int total_distance;
	while(itr != list_paths.end())
	{
		total_distance = 0;
		auto itrVetex = (*itr).begin();
		while(itrVetex != (*itr).end() && ((itrVetex+1) != (*itr).end()))
		{
			total_distance = total_distance + get_distance_route((*itrVetex), (*(itrVetex+1)));
			itrVetex++;
		}
		if(total_distance < max_distance)
			numRoutes++;
		itr++;
	}
	return numRoutes;
}

// Displays number of routes betwen source and destination with distance less than max_distance
void route_info::printNumRoutes_with_shorter_distance(char source, char dest, int max_distance)
{
	int numRoutes = getNumRoutes_with_shorter_distance(source, dest, max_distance);
	cout << numRoutes << endl;
}

// Finds all the paths for the given source and destination
void route_info::findAllPaths(char source, char dest, vector<vector<int>> &list_paths)
{
	// Clear the previous list
	auto szList = list_paths.size();
	for(auto i = 0; i < szList; i++)
	{
		list_paths[i].clear();
	}
	list_paths.clear();
	
	int num_vertex = m_townName_townNumber.size();
	vector<bool> visited(num_vertex, false);
	vector<int> paths;	
	if((m_townName_townNumber.find(source) != m_townName_townNumber.end())
		&& (m_townName_townNumber.find(dest) != m_townName_townNumber.end()))
	{
		findAllPaths_r(m_townName_townNumber[source], m_townName_townNumber[dest], visited, paths, list_paths);
	}
}

void route_info::findAllPaths_r(int source, int dest, vector<bool> &visited, vector<int> &paths, vector<vector<int>> &list_paths)
{
	visited[source] = true;	
	paths.push_back(source);
	
	if(source == dest)
	{
		list_paths.push_back(paths);
	}
	else
	{
		vector<TOWN *> list = m_adjacency_list[source];
		for(vector<TOWN *>::iterator itr_adjacent = list.begin(); itr_adjacent != list.end(); itr_adjacent++)
		{
			if(!visited[(*itr_adjacent)->townNumber])
			{				
				findAllPaths_r((*itr_adjacent)->townNumber, dest, visited, paths, list_paths);
			}
		}
	}

	//Remove current vertex from paths[] and mark it as unvisited	
	paths.pop_back();	
	visited[source] = false;
}

int route_info::get_length_shortest_path(int dest_vertex)
{		
	return m_table[dest_vertex].distance;
}

int main()
{
	vector<string> queries;
	ifstream inputFile;
	inputFile.open("input.txt");
	if(!inputFile)
	{
		cout << "Cannot open input file.\n";
		return 1;
	}

	string input;
	getline(inputFile, input);

	// Initialize the route info object
	route_info objInfo;
	objInfo.init(input);

	// Read the queries
	string line;
	while(!inputFile.eof())
	{
		getline(inputFile, line);
		queries.push_back(line);
	}	

	auto itr = queries.begin();
	while(itr != queries.end())
	{
		istringstream ss(*itr);

		vector<string> tokens;
		copy(istream_iterator<string>(ss), istream_iterator<string>(), back_inserter(tokens));

		if(tokens[0] == "DR") //The distance of the given route eg. A-B-C
		{
			objInfo.print_distance_route(tokens[1]);
		}

		if(tokens[0] == "NTL") //The number of trips starting at source and ending at destination with a maximum of max_stops
		{
			objInfo.printNumTrips_shorter_or_equal(tokens[1][0],tokens[2][0], stoi(tokens[3]));
		}

		if(tokens[0] == "NTE") //The number of trips starting at source and ending at destination with exactly max_stops stops
		{
			objInfo.printNumTrips(tokens[1][0],tokens[2][0], stoi(tokens[3]));
		}

		if(tokens[0] == "SRD") //The length of the shortest route (in terms of distance to travel) from source to destination
		{
			objInfo.print_shortest_distance(tokens[1][0],tokens[2][0]);
		}

		if(tokens[0] == "NR") //The number of routes from source to destination with distance less than max_distance
		{
			objInfo.printNumRoutes_with_shorter_distance(tokens[1][0],tokens[2][0], stoi(tokens[3]));
		}
		
		itr++;
	}	

	cout << "Press and key to exit" << endl;
	getchar();
	return 0;
} 