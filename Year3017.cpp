#include <iostream>
#include <vector>
#include <list>
using namespace std;
typedef struct tunnel
{
	int planet1;
	int planet2;
}TUNNEL;

typedef struct teleport
{
	int planet1;
	int universe1;
	int planet2;
	int universe2;
}TELEPORT;

typedef struct query
{
	int sPlanet;
	int sUniverse;
	int dPlanet;
	int dUniverse;
}QUERY;

typedef struct planet
{
	planet(int d = 0, bool bVisited = false)
	{
		distance = d;
		visited = bVisited;
	}
	int distance;
	bool visited;
	int universe;
	list<planet> adjacentPlanets;
}PLANET;

int main()
{
	int N, M, Q;
	cin >> N >> M >> Q;
	
	/*TUNNEL *pTunnel = new TUNNEL[N-1];
	for(int index = 0; index < N-1; index++)
	{
		cin >> pTunnel[index].planet1 >> pTunnel[index].planet2;
	}

	TELEPORT *pTeleports = new TELEPORT[M];
	for(int index3 = 0; index3 < M; index3++)
	{
		cin >> pTeleports[index3].planet1 >> pTeleports[index3].universe1 >> pTeleports[index3].planet2 >> pTeleports[index3].universe2;
	}

	QUERY *pQueries = new QUERY[Q];
	for(int index2 = 0; index2 < Q; index2++)
	{
		cin >> pQueries[index2].sPlanet >> pQueries[index2].sUniverse >> pQueries[index2].dPlanet >> pQueries[index2].dUniverse;
	}

	delete[] pTunnel;
	delete[] pTeleports;
	delete[] pQueries;*/

	vector<TUNNEL> Tunnels;
	Tunnels.reserve(N-1);
	TUNNEL tunnel;
	for(int index = 0; index < N-1; index++)
	{
		
		cin >> tunnel.planet1 >> tunnel.planet2;
		Tunnels.push_back(tunnel);		
	}

	vector<TELEPORT> Teleports;
	Teleports.reserve(M);
	TELEPORT teleport;
	for(int index3 = 0; index3 < M; index3++)
	{
		cin >> teleport.planet1 >> teleport.universe1 >> teleport.planet2 >> teleport.universe2;
		Teleports.push_back(teleport);
	}

	vector<QUERY> Queries;
	Queries.reserve(Q);
	QUERY query;
	for(int index2 = 0; index2 < Q; index2++)
	{
		cin >> query.sPlanet >> query.sUniverse >> query.dPlanet >> query.dUniverse;
		Queries.push_back(query);
	}

	int numUniverses;
	//vector<UNIVERSE> universes;
	//universes.reserve(numUniverses);

	int totalPlanets = numUniverses * N;

	vector<UNIVERSE>::iterator itrUni = universes.begin();
	while(itrUni != universes.end())
	{
		itrUni->planets.reserve(N);
		
	}

	return 0;
}