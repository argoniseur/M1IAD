#include "vgraph.h"

// Runs a Dijkstra search on the graph, starting from node "src".
// See https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm .
// Returns the same "parent" vector as BFS() in bfs.1.h.

typedef struct _source_to_node{
	pair<int, double> node;

	bool operator<(struct _source_to_node x){
		return node.second < x.node.second;

	}

}Source2node;

vector<int> Dijkstra(const DirectedGraph& graph, int src);