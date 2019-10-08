#include "tree.1.h"


vector<vector<int>> ParentVectorToChildrenVector(const vector<int>& parent){
	std::vector<int> v{};
	std::vector<std::vector<int>> child(parent.size(), v);
	for(int i=0;i<parent.size();i++){

		if(parent[i] != -1){
			child[parent[i]].push_back(i);
		}
	}
	return child;
}