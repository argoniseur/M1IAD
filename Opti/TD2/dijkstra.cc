#include "dijkstra.h"
#include <limits.h>

vector<int> Dijkstra(const DirectedGraph& graph, int src){
	vector<int> distance(graph.NumNode(), INT_MAX);
	distance[src] = 0;
	priority_queue<int> q;

	
}