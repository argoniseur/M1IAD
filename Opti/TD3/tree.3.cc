#include "tree.3.h"

vector<vector<int>> cheat;
std::vector<int> retour;

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

vector<int> AllHeights(const vector<vector<int>>& enfants){
	cheat = enfants;
	vector<int> v(enfants.size(),-1);
	retour = v;
	for(int i=0;i<enfants.size();i++){
		retour[i] = recursive(0, i);
	}
	return retour;
}