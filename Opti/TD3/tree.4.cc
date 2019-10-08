#include "tree.4.h"



int recursive(int node, const vector<vector<int>>& enfants, vector<int> *mem){
	if(mem->at(node) != -1){
		return mem->at(node);
	}
	if(enfants[node].empty()){
		mem->at(node) = 1;
		return 1;
	}
	int x = 0;
	for(int i=0;i<enfants[node].size();i++){
		x = x + recursive(enfants[node][i], enfants, mem);
	}
	mem->at(node) = x + 1;
	return x + 1;
}


vector<int> AllSubtreeSizes(const vector<vector<int>>& enfants){
	vector<int> ret;
	vector<int> mem(enfants.size(), -1);
	for(int i=0;i<enfants.size();i++){
		ret.push_back(recursive(i, enfants, &mem));
	}
	return ret;
}