#include<time.h>
#include<windows.h>
#include"MazeHead.h"
using namespace std;

void randomgo(node (*maze)[n],int x, int y,int *toward,int towardlast){
	int c1=rand()%4;
	int c2=rand()%4;
	int t=toward[c1];
	toward[c1]=toward[c2];
	toward[c2]=t;//改变行进顺序

	for(int i=0;i<4;i++){
		if(toward[i] != towardlast)
		switch (toward[i]){
		case DOWN:
			if(x+2<n&&maze[x+2][y].GetState()==1){
				maze[x+1][y].ChangeState();
				maze[x+2][y].ChangeState();
				randomgo(maze,x+2,y,toward,UP);
			}
			break;
		case UP:
			if(x-2>=0&&maze[x-2][y].GetState()==1){
				maze[x-1][y].ChangeState();
				maze[x-2][y].ChangeState();
				randomgo(maze,x-2,y,toward,DOWN);
			}
			break;
		case LEFT:
			if(y-2>=0&&maze[x][y-2].GetState()==1){
				maze[x][y-1].ChangeState();
				maze[x][y-2].ChangeState();
				randomgo(maze,x,y-2,toward,RIGHT);
			}
			break;
		case RIGHT:
			if(y+2<n&&maze[x][y+2].GetState()==1){
				maze[x][y+1].ChangeState();
				maze[x][y+2].ChangeState();
				randomgo(maze,x,y+2,toward,LEFT);
			}
			break;
		}
	}
}

void CreatMaze(node (*maze)[n]){
	int toward[4]={0,1,2,3};
	srand(time(NULL));
	int tempx=rand()%(n/2)*2;
	int tempy=rand()%(n/2)*2;
	cout<<tempx<<' '<<tempy<<endl;
	maze[tempx][tempy].ChangeState();
	randomgo(maze,tempx,tempy,toward,-1);
}