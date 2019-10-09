#include"MazeHead.h"

void printmaze(node (*maze)[n]){
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            //if(i==7&&j==7)cout<<'0';
            //else 
            if(i==1&&j==0||i==n&&j==n+1)cout<<' ';
            else if (i == 0 || i == n + 1 || j == 0 || j == n + 1)
                cout << "#";
            else
            {
                if (maze[i - 1][j - 1].GetState() == 1)
                    cout << "#";
                else if(maze[i - 1][j - 1].GetFlag() == 1)
                    cout << "*";
                else 
                    cout<<" ";
            }
        }
        cout << "\n";
    }
}

