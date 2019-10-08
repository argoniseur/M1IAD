#include "tree.2.h"

vector<vector<int>> cheat;

int recursive(int prof, int node){
	if(cheat[node].empty()){
		return prof;
	}else{
		int x = -1, y;
		for(int i=0;i<cheat[node].size();i++){
			y = recursive(prof+1, cheat[node][i]);
			if(x < y)
				x = y;
		}
		return x;
	}
}


int Height(const vector<vector<int>>& enfants, int node){
	cheat = enfants;
	return recursive(0, node);
}