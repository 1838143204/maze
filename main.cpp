#include"maze.h"

node maze[n][n];
int main(){
start:
	CreatMaze();
	printmaze();
	cout<<"Press any key to find way"<<endl;
	char c;
	if (cin.get(c))
	{
		find(0, 0, LEFT);
		system("cls");
		printmaze();
	}	
	return 0;
}