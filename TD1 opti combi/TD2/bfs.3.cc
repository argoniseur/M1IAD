#include "bfs.3.h"
#include <deque>
#include <algorithm>
#include <iostream>

vector<int> GetShortestPathFromRootedTree(const vector<int>& parent, int target){
	std::vector<int> path;
	

	int current = target;
	int next = parent[target];
	if (next != -1){
		path.push_back(target);
		while(next != current){
			path.push_back(next);
			current = next;
			next = parent[current];
		}
		reverse(path.begin(), path.end());
	}
	return path;
}