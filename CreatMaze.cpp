#include<time.h>
#include<windows.h>
#include"MazeHead.h"
using namespace std;

void randomgo(node (*maze)[n],int x, int y,int *toward){
	int i=0;
	int c1=rand()%4;
	int c2=rand()%4;
	int t=toward[c1];
	toward[c1]=toward[c2];
	toward[c2]=t;//改变行进顺序
	while(i<4){
		switch (toward[i]){
		case DOWN:
			if(x+2<n&&maze[x+2][y].GetState()==1){
				maze[x+1][y].ChangeState();
				maze[x+2][y].ChangeState();
				randomgo(maze,x+2,y,toward);
			}
			break;
		case UP:
			if(x-2>=0&&maze[x-2][y].GetState()==1){
				maze[x-1][y].ChangeState();
				maze[x-2][y].ChangeState();
				randomgo(maze,x-2,y,toward);
			}
			break;
		case LEFT:
			if(y-2>=0&&maze[x][y-2].GetState()==1){
				maze[x][y-1].ChangeState();
				maze[x][y-2].ChangeState();
				randomgo(maze,x,y-2,toward);
			}
			break;
		case RIGHT:
			if(y+2<n&&maze[x][y+2].GetState()==1){
				maze[x][y+1].ChangeState();
				maze[x][y+2].ChangeState();
				randomgo(maze,x,y+2,toward);
			}
			break;
		}
		i++;
	}
}

void CreatMaze(node (*maze)[n]){
	bool flag=0;
	int toward[4]={0,1,2,3};
	srand(time(NULL));
	maze[n/2][n/2].ChangeState();
	randomgo(maze,n/2,n/2,toward);
	if (maze[0][0].GetState() == 1)
	{
		maze[0][0].ChangeState();
		if (maze[0][1].GetState() != 0 && maze[1][0].GetState() != 0)
			maze[0][1].ChangeState();
	}//入口处理
	if (maze[n-1][n-1].GetState() == 1)
	{
		maze[n-1][n-1].ChangeState();
		if (maze[n-1][n-2].GetState() != 0 && maze[n-2][n-1].GetState() != 0)
			maze[n-1][n-2].ChangeState();
	}//出口处理
}