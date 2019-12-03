#include <time.h>
#include "maze.h"
using namespace std;
extern node maze[n][n];
void randomgo(int x, int y)
{
    int toward[4] = {0, 1, 2, 3};
    int step = 0;
    maze[x][y].ChangeState();
    for (int i = 0; i < 4; i++)
    {
        int c = rand() % 4;
        int t = toward[i];
        toward[i] = toward[c];
        toward[c] = t; //改变行进顺序
    }

    for (int i = 0; i < 4; i++)
    {
        switch (toward[i])
        {
        case DOWN:
            if (x + 2 < n && maze[x + 2][y].GetState() == 1)
            {
                maze[x + 1][y].ChangeState();
                maze[x + 1][y].step = 6;
                randomgo(x + 2, y);
                step++;
            }

            break;
        case UP:
            if (x - 2 >= 0 && maze[x - 2][y].GetState() == 1)
            {
                maze[x - 1][y].ChangeState();
                maze[x - 1][y].step = 6;
                randomgo(x - 2, y);
                step++;
            }

            break;
        case LEFT:
            if (y - 2 >= 0 && maze[x][y - 2].GetState() == 1)
            {
                maze[x][y - 1].ChangeState();
                maze[x][y - 1].step = 6;
                randomgo(x, y - 2);
                step++;
            }

            break;
        case RIGHT:
            if (y + 2 < n && maze[x][y + 2].GetState() == 1)
            {
                maze[x][y + 1].ChangeState();
                maze[x][y + 1].step = 6;
                randomgo(x, y + 2);
                step++;
            }

            break;
        }
    }
    maze[x][y].step = step;
}

void CreatMaze()
{
    srand(time(NULL));
    int tempx = rand() % (n / 2) * 2;
    int tempy = rand() % (n / 2) * 2;
    maze[tempx][tempy].ChangeState();
    randomgo(tempx, tempy);
    maze[tempx][tempy].step = 5;
}

void printmaze()
{
    system("cls");
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {

            if (i == 1 && j == 0 || i == n && j == n + 1)
                cout << "   "; //出入口
            else if (i == 0 || i == n + 1 || j == 0 || j == n + 1)
                cout << "[#]"; //边界
            else if (maze[i - 1][j - 1].GetState() == 1)
                cout << "[#]"; //墙体
            else if(maze[i - 1][j - 1].GetState() == 0)
            {
                if (maze[i - 1][j - 1].GetFlag()==1)
                    cout << " * "; //通路
                else 
                    cout <<  "   ";//道路
            }
        }
        cout << "\n";
    }
}

bool find(int x, int y, int towardlast)
{
    if (x == n - 1 && y == n - 1)
    {
        maze[x][y].ChangeFlag(1);
        return 1;
    }
    else
    {
        int i = 0;
        maze[x][y].ChangeFlag(0); //避免重复绕圈
        while (i < 4)
        {
            if (i != towardlast) //避免走回头路
                switch (i)
                {
                case DOWN:
                    if (x + 1 < n)
                    {
                        if (maze[x + 1][y].GetFlag() == -1)
                        {
                            maze[x][y].ChangeDown(find(x + 1, y, 1));
                        }
                        else
                            maze[x][y].ChangeDown(maze[x + 1][y].GetFlag());
                    }
                    break;
                case UP:
                    if (x - 1 >= 0)
                    {
                        if (maze[x - 1][y].GetFlag() == -1)
                        {
                            maze[x][y].ChangeUp(find(x - 1, y, 0));
                        }
                        else
                            maze[x][y].ChangeUp(maze[x - 1][y].GetFlag());
                    }
                    break;
                case LEFT:
                    if (y - 1 >= 0)
                    {
                        if (maze[x][y - 1].GetFlag() == -1)
                        {
                            maze[x][y].ChangeLeft(find(x, y - 1, 3));
                        }
                        else
                            maze[x][y].ChangeLeft(maze[x][y - 1].GetFlag());
                    }
                    break;
                case RIGHT:
                    if (y + 1 < n)
                    {
                        if (maze[x][y + 1].GetFlag() == -1)
                        {
                            maze[x][y].ChangeRight(find(x, y + 1, 2));
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
}