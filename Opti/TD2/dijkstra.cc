#include "dijkstra.h"
#include <limits.h>
#include <queue>

vector<int> Dijkstra(const DirectedGraph& graph, int src){
	vector<int> distance(graph.NumNodes(), INT_MAX);
	distance[src] = 0;
	std::priority_queue<int> q;


	return distance;
}