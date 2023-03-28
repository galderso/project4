// dijsktras.cpp

// Main Execution
// dijsktras.cpp

#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;
// Main Execution

struct Node {
int total_weight;
int x,y;
}; 


int main(int argc, char *argv[]) {
    map<char,int> weight;
	int numtiles,tileweight;
	char tile;
	cin>>numtiles;
	for(int i=0;i<numtiles;i++){
		cin>>tile>>tileweight;
		weight[tile]=tileweight;
	}

	int sizex,sizey;
	char inputtile;
	cin>>sizex>>sizey;
	int board[sizex][sizey];
	for(int i =0;i<sizex;i++){
		for(int j =0;j<sizey;j++){
		cin>>inputtile;
		board[i][j]=weight.find(inputtile)->second;
		}
	}
	int sourcex,sourcey,destx,desty;
	cin>>sourcex>>sourcey;
	cin>>destx>>desty;


queue<Node> path;

path.push({0,destx,desty});
while(!path){
Node k=path.top();
path.pop();



}
}
