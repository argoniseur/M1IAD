#include "bfs.1.h"
#include <deque>
#include <iostream>

vector<int> BFS(const UndirectedGraph& graph, int src){
	std::vector<int> marque(graph.NumNodes(),0);
	std::vector<int> parent(graph.NumNodes(),-1);
	std::vector<int> voisin;
	deque<int> f;
	f.push_back(src);
	parent[src] = src;
	marque[src] = 1;
	int s;

	while(!f.empty()){
		s = f.front();
		f.pop_front();
		voisin = graph.Neighbors(s);
		
		for(int i=0;i<voisin.size();i++){
			
			if (marque[voisin[i]] != 1){
				f.push_back(voisin[i]);
				marque[voisin[i]] = 1;
				parent[voisin[i]] = s;
			}
		}
	}
	return parent;
}