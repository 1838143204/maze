#include<time.h>
#include"MazeHead.h"
using namespace std;
extern node maze[n][n];
void randomgo(int x, int y){
	int toward[4] = {0, 1, 2, 3};
	// system("cls");
	// printmaze();
	// Sleep(1000);
	int step=0;
	maze[x][y].ChangeState();
	for(int i=0;i<4;i++)
	{
		int c = rand() % 4;
		int t = toward[i];
		toward[i] = toward[c];
		toward[c] = t; //改变行进顺序
	}

	for(int i=0;i<4;i++){
		switch (toward[i])
		{
		case DOWN:
			if (x + 2 < n && maze[x + 2][y].GetState() == 1)
			{
				maze[x + 1][y].ChangeState();
				maze[x + 1][y].step=6;
				randomgo(x + 2, y);
				step++;
			}
			
            break;
		case UP:
			if (x - 2 >= 0 && maze[x - 2][y].GetState() == 1)
			{
				maze[x - 1][y].ChangeState();
				maze[x - 1][y].step = 6;
				randomgo( x - 2, y);
				step++;
			}
			
            break;
		case LEFT:
			if (y - 2 >= 0 && maze[x][y - 2].GetState() == 1)
			{
				maze[x][y - 1].ChangeState();
				maze[x][y - 1].step = 6;
				randomgo( x, y - 2);
				step++;
			}
			
            break;
		case RIGHT:
			if (y + 2 < n && maze[x][y + 2].GetState() == 1)
			{
				maze[x][y + 1].ChangeState();
				maze[x][y + 1].step = 6;
				randomgo( x, y + 2);
				step++;
			}
			
            break;
		}
	}
	maze[x][y].step=step;
}

void CreatMaze(){
	srand(time(NULL));
	int tempx=rand()%(n/2)*2;
	int tempy=rand()%(n/2)*2;
	maze[tempx][tempy].ChangeState();
	randomgo(tempx,tempy);
	maze[tempx][tempy].step=5;
}