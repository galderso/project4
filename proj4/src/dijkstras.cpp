//Grant Alderson and Sam Cradock
//Citation:https://www.geeksforgeeks.org/minimum-cost-path-left-right-bottom-moves-allowed/ 
//https://www.techiedelight.com/find-shortest-path-source-destination-matrix-satisfies-given-constraints/ 
//and planks notes
//This program finds the shortest path for a runner using dijkstras algorithm


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


	bool const operator<(Node x)const {
		return tile_weight>x.tile_weight;
	}

}; 


int main(int argc, char *argv[]){
	
	int sizex,sizey;
	int startx,starty;
	int destx,desty;
	char tile;
	map<char, int> weight;
	priority_queue<Node> cpath;
	int dist=0;
    int numtiles, tilenum;
	map<pair<int,int>,pair<int,int>> edges;//edges between the nodes in the struct
	cin >> numtiles;
	for(int i=0;i<numtiles; i++){//takes chars and their weights
		cin >>tile >> tilenum;
		weight[tile]= tilenum;
	}
	cin >>sizex >>sizey;
	char input;
	int board[sizex][sizey];
	for(int i=0; i < sizex; i++){//creates the board
		for(int j=0; j<sizey; j++){
			cin>>input;
			board[i][j]=weight[input];
		}
	}
	Node n;
	cin >>startx>> starty;
	cin >>destx>> desty;
	cpath.push({dist, {destx,desty},{destx,desty}});

	while(!cpath.empty()){//loop until struct is empty
		n = cpath.top();
		cpath.pop();//pop top node
		if((edges.count(n.node1))){//if edge is not already in map
			continue;
		}else{
			edges[n.node1]=n.node2;//place edge into map
			dist=n.tile_weight;//update weight
			if(n.node1.first == startx && n.node1.second == starty){//checks if at starting node

				cout <<dist<<endl;//print
				pair<int, int> temp = n.node1;
				while(temp.first!=destx||temp.second !=desty){
					cout << temp.first<< " " <<temp.second << endl;
					temp=edges[temp];
				}
				cout << temp.first<<" " <<temp.second << endl;

				return 0;

			}
		}

		int x=n.node1.first;
		int y=n.node1.second;
		if((y+1)<sizey){//check up
			cpath.push({n.tile_weight+board[x][y+1],{x, y+1},{x, y}});
		}
		if((y-1)>-1){//check down
			cpath.push({n.tile_weight+board[x][y-1],{x, y-1},{x, y}});
		} 
		if((x+1) < sizex){//check right
			cpath.push({n.tile_weight+board[x+1][y],{x+1, y},{x, y}}); 
		}
		if((x-1) >-1){//check left
			cpath.push({n.tile_weight+board[x-1][y],{x-1, y},{x, y}});
		}


	}
	return 0;
}

