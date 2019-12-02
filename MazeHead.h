#include <iostream>
#include <windows.h>
using namespace std;
#define DOWN 0
#define UP 1
#define LEFT 2
#define RIGHT 3
const int n =15;//n只能为奇数
class node{
private:
	bool state;//表示该节点是否为通路
	int flag;//表示该节点是否可行或是否被探索(-1 为探索,0 不可行,1 可行)
	bool right;//右侧是否可行
	bool left;//左侧是否可行
	bool up;//上侧是否可行
	bool down;//下侧是否可行
public:
	int step;
	node(){
		step=0;
		state=1;
		flag=0;
		right=0;
		left=0;
		up=0;
		down=0;
	}//初始化时将所有节点设为墙,此时都不可行
	bool GetState(){return state;}
	void ChangeState(){
		state=0;
		flag=-1;
	}//创建迷宫路径,将改为通路的节点,设置flag为-1,表示可探索但未探索
	int GetFlag(){return flag;}
	void ChangeFlag(bool new_flag){flag=new_flag;}
	// void ChangeLeft(bool new_left){left=new_left;}
	// void ChangeRight(bool new_right){right=new_right;}
	// void ChangeUp(bool new_up){up=new_up;}
	// void ChangeDown(bool new_down){down=new_down;}
	// void AutoFlag(){state=up+right+down+left;};
};

void randomgo(int x, int y);
void CreatMaze();
void printmaze();
bool find(int x,int y,int lasttoward);