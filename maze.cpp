#include"MazeHead.h"

int main(){
	char c;
	while(cin.get(c)){
		if(c=='q')break;
		node maze[n][n];
		CreatMaze(maze);
//		printmaze(maze);
//		find(maze,0,0,LEFT);
		printmaze(maze);
	}
	return 0;
}