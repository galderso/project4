//This program takes in an int value N and creates a random NxN graph that can be used for 
//The dijkstras.cpp file. It does this by creating seperate map#.txt files for each different
//map and using a switch to make a space equal to only f,g,G,h,m or r.

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){
	int N = 0; //N used for NxN graph
	int mapNum = 10; //which map we're writing to, increments
	char space; //tile character
	srand((unsigned) time(NULL)); //seed for rand()
	while(cin >> N){ 
		stringstream ss;
		ss << "map" << mapNum << ".txt";
		string filename = ss.str(); //will generate map0-6.txt
		ofstream mapFile;
		mapFile.open(filename);
		for(int i = 0; i < N; i++){
			if(i >0){
				mapFile << "\n"; //add a newspace each time we iterate
			}
			for(int j = 0; j < N; j++){
				int rng = rand()%6; //numbers in range from 0-5
				switch (rng) { //based on the rng, choose one of the valid characters
					case 0:
						space = 'f';
						break;
					case 1:
						space = 'g';
						break;
					case 2:
						space = 'G';
						break;
					case 3:
						space = 'h';
						break;
					case 4:
						space = 'm';
						break;
					case 5:
						space = 'r';
						break;
				}
				mapFile << space;
			}
		}
		mapNum++;
		mapFile.close();
	}
	return 0;
}

	

