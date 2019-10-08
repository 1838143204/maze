#include<iostream>
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
		case 0:
			if(x+2<n&&maze[x+2][y].GetState()==1){
				maze[x+1][y].ChangeState(0);
				maze[x+2][y].ChangeState(0);
				randomgo(maze,x+2,y,toward);
			}
			break;
		case 1:
			if(x-2>=0&&maze[x-2][y].GetState()==1){
				maze[x-1][y].ChangeState(0);
				maze[x-2][y].ChangeState(0);
				randomgo(maze,x-2,y,toward);
			}
			break;
		case 2:
			if(y-2>=0&&maze[x][y-2].GetState()==1){
				maze[x][y-1].ChangeState(0);
				maze[x][y-2].ChangeState(0);
				randomgo(maze,x,y-2,toward);
			}
			break;
		case 3:
			if(y+2<n&&maze[x][y+2].GetState()==1){
				maze[x][y+1].ChangeState(0);
				maze[x][y+2].ChangeState(0);
				randomgo(maze,x,y+2,toward);
			}
			break;
		}
		i++;
	}
}

void CreatMaze(node (*maze)[n]){
	int toward[4]={0,1,2,3};
	srand(time(NULL));
	maze[n/2][n/2].ChangeState(0);
	randomgo(maze,n/2,n/2,toward);
	for(int i=0;i<n+2;i++){
		for(int j=0;j<n+2;j++){
			if(i==0||i==n+1||j==0||j==n+1)cout<<"#";
			else{
				if(maze[i-1][j-1].GetState()==1)cout<<"#";
				else cout<<" ";
			}
		}		
		cout<<"\n";
	}
}