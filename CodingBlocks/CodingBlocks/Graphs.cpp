#include "stdafx.h"
#include <unordered_map>

template <typename T>
class Graph {
	unordered_map<T, list<T>> m;

public:
	void addEdge(T src, T dest, bool bidir = true) {
		m[src].push_back(dest);
		if (bidir) {
			m[dest].push_back(src);
		}
	}

	void prindAdjList() {
		for (auto p : m) {
			// go over each entry in the hash map
			cout << p.first << "-->";
			for (auto node : p.second) {
				//now print each node from the linked list for each node.
				cout << node << ", ";
			}
		}
	}

	// on unweighted graphs, BFS gives shortest paths from specified node to all the nodes
	void bfs(T src, T dest) {
		queue<T> q;
		unordered_map<T, bool> visited;
		unordered_map<T, int> dist;
		unordered_map<T, T> parent;
		q.push(src);
		visited[src] = true;

		while (!q.empty())
		{
			T f = q.front();
			q.pop();
			cout << f << " ";

			for (auto neighbor : m[f]) {
				if (!visited[neighbor]) {
					parent[neighbor] = f;
					dist[neighbor] = dist[f] + 1;
					q.push(neighbor);
					visited[neighbor] = true; // mark as visited
				}
			}
		}

		// print distances
		for (auto p : m) {
			cout << p.first << " --> " << dist[p.second] << endl;
		}
	}

	void dfsHelper(T node, unordered_map<T, bool> & visited, int &count)
	{
		cout << node << " ";
		visited[node] = true;
		count++;

		for (auto nghbr : m[node])
		{
			if (!visited[nghbr]) {
				dfsHelper(node, visited, count);
			}
		}
	}


	void dfs(T src)
	{
		unordered_map<T, bool> visited;
		for (auto p : m) {
			if (!visited[p.first])
			{
				int connectedCompomentNodeCount = 0;
				dfsHelper(p.first, visited, connectedCompomentNodeCount);
			}
		}
	}

	void PrintGraphRecursively(T node) {

		if (node == null)
			return;

		if (!visited[node])
		{
			visited[node] = true;
			cout << node << endl;
			for (auto neighbor : m[node])
			{
				PrintGraphRecursively(neighbor);
			}
		}
	}
};





//---------------------------- xx ---------------------------

//int HashingTest()
//{
//	unordered_map<string, int> price;
//
//	// inserting
//	price["mango"] = 100;
//	price["apple"] = 20;
//	price.insert(make_pair("Orange", 30));
//
//	// searching
//	cout << price["Kiwi"] << endl; // but this will return 0, when Kiwi is not present.
//
//	if (price.count("Kiwi"))
//		cout << price["Kiwi"];
//	else cout << " price not found " << endl;
//}
