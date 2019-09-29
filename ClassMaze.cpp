#include<iostream>
using namespace std;
const int n = 100;
class node{
private:
	int x,y;
	bool state;
	bool right;
	bool left;
	bool up;
	bool down;
public:
	node(int x_,int y_):x(x_),y(y_){
	state=0；
	right=0;
	left=0;
	up=0;
	down=0;
}
	bool GetState(){return state};
	void ChangeState(bool s):state(s){};
}

void CreatMaze(node **maze){
	srand(time(NULL));
	int tempx=rand()/n,tempy=rand()/n;

}


