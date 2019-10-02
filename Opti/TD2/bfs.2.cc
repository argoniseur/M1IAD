#include "bfs.2.h"
#include <deque>
#include <iostream>

vector<int> GetBfsDistances(const vector<int>& parent){
	std::vector<int> distance(parent.size(), -1);

	for(int i=0;i<distance.size();i++){
		int n = 0;
		int e = i;
		int p = parent[e];

		while(e != p && parent[i] != -1){
			n++;
			e = parent[e];
			p = parent[p];
		}
		if(parent[i] != -1){
			distance[i] = n;
		}
	}
	return distance;
}