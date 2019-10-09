#include"MazeHead.h"

bool find(node (*maze)[n],int x,int y,int towardlast){
    // cout<<x<<' '<<y<<' ';
    if(x==n-1 && y==n-1){
        maze[x][y].ChangeFlag(1);
        return 1;
    }
    else {
        int i = 0;
        maze[x][y].ChangeFlag(0);//避免重复绕圈
        while (i < 4)
        {
            if (i != towardlast)//避免走回头路
                switch (i)
                {
                case DOWN:
                    if (x + 1 < n)
                    {
                        // cout<<"Down"<<' ';
                        if (maze[x + 1][y].GetFlag() == -1)
                        {
                            maze[x][y].ChangeDown(find(maze, x + 1, y, 1));
                        }
                        else
                            maze[x][y].ChangeDown(maze[x + 1][y].GetFlag());
                    }
                    break;
                case UP:
                    if (x - 1 >= 0)
                    {
                        // cout<<"Up"<<' ';
                        if (maze[x - 1][y].GetFlag() == -1)
                        {
                            maze[x][y].ChangeUp(find(maze, x - 1, y, 0));
                        }
                        else
                            maze[x][y].ChangeUp(maze[x - 1][y].GetFlag());
                    }
                    break;
                case LEFT:
                    if (y - 1 >= 0)
                    {
                        // cout<<"Left"<<' ';
                        if (maze[x][y - 1].GetFlag() == -1)
                        {
                            maze[x][y].ChangeLeft(find(maze, x, y - 1, 3));
                        }
                        else
                            maze[x][y].ChangeLeft(maze[x][y - 1].GetFlag());
                    }
                    break;
                case RIGHT:
                    if (y + 1 < n)
                    {
                        // cout<<"Right"<<' ';
                        if (maze[x][y + 1].GetFlag() == -1)
                        {
                            maze[x][y].ChangeRight(find(maze, x, y + 1, 2));
                        }
                        else
                            maze[x][y].ChangeRight(maze[x][y + 1].GetFlag());
                    }
                    break;
                }
            i++;
        }
        maze[x][y].AutoFlag();
        return maze[x][y].GetFlag();
    }
    // cout<<endl;
}