//Grant Alderson and Sam Cradock
//Citation: https://www.techiedelight.com/find-shortest-path-source-destination-matrix-satisfies-given-constraints/ and planks notes
//This program finds the shortest path for a runner using dijkstras alorithm


#include<vector>
#include<algorithm>
#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;


struct Node{
	int tile_weight;//weight of current node
	pair<int,int> node1;//current node
	pair<int,int> node2;//node before
	bool const operator<( Node a)const {
		return a.tile_weight<tile_weight;
	}
}; 


int main(int argc, char *argv[]){
	int numtiles, tilenum;
	int sizex,sizey;
	int startx,starty;
	int destx,desty;
	string tile;
	map<string, int> weight;
	priority_queue<Node> cpath;
	int dist=0;
	map<pair<int,int>,pair<int,int>> edges;//edges between the nodes in the struct
	cin >> numtiles;
	for(int i=0; i < numtiles; i++){//takes chars and their weights
		cin >>tile >> tilenum;
		weight[tile] = tilenum;
	}
	cin >>sizex >>sizey;
	string board[sizex][sizey];
	for(int i=0; i < sizex; i++){//creates the board
		for(int j=0; j<sizey; j++){
			cin >> board[i][j];

		}
	}
	Node v;
	cin >>startx>> starty;
	cin >>destx>> desty;
	cpath.push({0, {destx,desty},{destx,desty}});

	while(cpath.size()!=0){//loop until struct is empty
		v = cpath.top();
		cpath.pop();//pop top node
		if((edges.count(v.node1))){//if edge is not already in map
			continue;
		}else{
		edges[v.node1] = v.node2;//place edge into map
		dist=v.tile_weight;//update weight
		if(v.node1.first == startx && v.node1.second == starty){//checks if at starting node
			break;  

		}
		}
		
		int x=v.node1.first;
		int y=v.node1.second;
		if((y+1) < sizey){//check up
			cpath.push({v.tile_weight+weight[board[x][y+1]],{x, y+1},{x, y}});
		}
		if((y-1)>-1){//check down
			cpath.push({v.tile_weight+weight[board[x][y-1]],{x, y-1},{x, y}});
		} 
		if((x+1) < sizex){//check right
			cpath.push({v.tile_weight+weight[board[x+1][y]],{x+1, y},{x, y}}); 
		}
		if((x-1) >-1){//check left
			cpath.push({v.tile_weight+weight[board[x-1][y]],{x-1, y},{x, y}});
		}


	}   

	cout <<dist<<endl;//print
	pair<int, int> temp = v.node1;
	while(temp.first !=destx||temp.second !=desty){
		cout << temp.first<< " " <<temp.second << endl;
		temp = edges[temp];
	}
	cout << temp.first<<" " <<temp.second << endl;

}

