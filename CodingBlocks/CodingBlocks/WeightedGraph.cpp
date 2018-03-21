#include "stdafx.h"
#include <unordered_map>
using namespace std;

class Graph {
	unordered_map<int, list<pair<int, int>>> m;
	int v;
public:
	
	Graph(int vrtcs)
	{
		v = vrtcs;
	}
	void addEdge(int u, int v, int wt, bool bidir = true)
	{
		m[u].push_back(make_pair(v, wt));
		if (bidir)
			m[v].push_back(make_pair(u, wt));
	}

	int dfsHelper(int node, int *cnt, bool * visited)
	{
		visited[node] = true;
		for (auto np : m[node])
		{
			int nbr = np.first;
			//if(!visited[nbr])
		}
	}
};
