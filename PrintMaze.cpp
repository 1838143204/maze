#include"MazeHead.h"

void printmaze(node (*maze)[n]){
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            if(i==1&&j==0||i==n&&j==n+1)cout<<"[]";//出入口
            else if (i == 0 || i == n + 1 || j == 0 || j == n + 1)
                cout << "[]";
            else if(maze[i-1][j-1].GetState()==1) cout<<"[]";
            else cout<<"  ";
            // else
            // {
            //     if (maze[i - 1][j - 1].GetState() == 1)
            //         cout << "#";//打印墙体
            //     else if(maze[i - 1][j - 1].GetFlag() == 1)
            //         cout << "*";//打印可行通路
            //     else 
            //         cout<<" ";//打印通路
            // }
        }
        cout << "\n";
    }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(maze[i][j].GetState()==1)cout<<1;
    //         else cout<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<maze[i][j].GetFlag();
    //     }
    //     cout<<endl;
    // }
}